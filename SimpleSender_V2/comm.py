'''
	Comm class is responsible for handling the serial 
	communicaiton.
'''

import serial
from copy import deepcopy

class Comm:
	def __init__(self, status, port, baudrate = 500000):
		try: # Try to open serial port
			self.ser = serial.Serial(port,baudrate)
		except: # If failed, throw error
			raise NameError("Serial could not connect")
		
		# Make pointer to status class accessible in class.
		self.status = status

	'''
		Send state changes to PCBs where solenoids have changed
	'''
	def update(self):
		if self.status.setToSend:
			# Gets the current active solenoids
			activeSolenoids = self.status.findActive()
			
			# Loop through board and solenoid pairs
			newActiveSolenoids = {}
			for board,solenoids in activeSolenoids.items():
				newActiveSolenoids[board] = self.combineBytes(solenoids)

			# Send serial to all boards.
			if len(newActiveSolenoids): # Dict not empty
				for board,bytes in newActiveSolenoids.items():
					self.sendPacket(board, bytes)
			else: # Dict is empty
				self.sendPacket(0xff, 0)

			# Mark message as sent
			self.status.setToSend = False

			# Return active solenoids 
			return newActiveSolenoids

		return None

	# Compute Checksum based on CRC-8
	def checkSum(self,packet,length):
		# Starting value for checksum
		chk = 0xff
		# Subtracts each byte from starting value (8-bit unsigned)
		for i in range(length):
			chk -= packet[i]
			if chk >= 0:
				pass
			else:
				chk += 0xff + 0x01
		return chk

	#######################################################
	##################### TRANSMITTER #####################
	#######################################################

	# This method will call the parser to create the messsage
	# given the passed arguments. Will then encapsulate message
	# and send over serial.
	def sendPacket(self, board, bytes):
		# Create a packet from headers
		message = self.createPacket(bytes)
		# If a message was returned
		if len(message) is not 0:
			# Send message
			self.writeSerial(chr(0xfd)) # Start Byte
			self.writeSerial(chr(int(board))) # Send Board ID
			self.writeSerial(chr(len(message))) # Length of message
			for i in range(len(message)):
				self.writeSerial(chr(message[i])) # Message
			self.writeSerial(chr(self.checkSum(message, len(message))))
			return True # Sent successfully
		return False # Nothing to send

	# Function sends a byte over serial
	# Eases debugging
	def writeSerial(self,byte):
		self.ser.write(byte)

	'''
		Combines solenoids 1-25 into a sequence of 25 bits.
		data is an array of solenoid numbers.
	'''
	def combineBytes(self, data):
		summary = 0

		for sol in data:
			sol = int(sol)
			summary |= (1 << (sol-1))

		return summary

	'''
		Create a message from the solenoid bits
			0x10 followed by 3 bytes of solenoids 1-24
			0x11 Powers solenoid 25 ON
			ox12 Power solenoid 25 OFF
	'''
	def createPacket(self, bytes):
		message = []

		message += [0x10] # Low current Solenoid Header
		for i in range(3):
			message += [(bytes >> i*8) & 0xff]

		if (bytes & (0x01 << 24)): # Power Solenoid
			message += [0x11]
		else:
			message += [0x12]

		return message

	'''
		Close the serial port
	'''
	def close(self):
		self.ser.close()










