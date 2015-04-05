'''
	Comm class is responsible for handling the serial 
	communicaiton.
'''

import serial
from parser import *

class Comm:
	def __init__(self, status, port, baudrate = 500000):
		try: # Try to open serial port
			self.ser = serial.Serial(port,baudrate)
		except: # If failed, throw error
			raise NameError("Serial could not connect")
		
		# Make pointer to status class accessible in class.
		self.status = data

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
	def sendPacket(self, headersToSend):
		# Create a packet from headers
		message = createPacket(headersToSend, self.status)
		# If a message was returned
		if len(message) is not 0:
			# Send message
			self.writeSerial(chr(0xfd)) # Start Byte
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








		
