# This class will take an input file and parse it. In the end, 
# it will return the raw representation of all constraints in the
# file.

class Parser:
	# Variables
	f = []
	world = 0

	# Constructor
	def __init__(self, filename, world):
		self.f = open(filename, 'r')
		self.world = world

	# Reader Function. Reads all lines of the file and saves
	# data in appropriate format.
	def read(self):
		section = 0 # Keeps track of which section we are in
		for line in self.f.readlines():
			line = line.split()
			
			if line[0] == "#####": # New Section Started
				section += 1

			elif section == 1: # Read Variables
				self.world.addVar(line[0], line[1])

			elif section == 2: # Read Values
				self.world.addValue(line[0], line[1])

			elif section == 3: # Read Limits
				self.world.addLimits(line[0], line[1])

			elif section == 4: # Read Unary Inclusive
				self.world.addUnaryI(line[0], line[1:len(line)])

			elif section == 5: # Read Unary Exclusive
				self.world.addUnaryE(line[0], line[1:len(line)])

			elif section == 6: # Read Binary Equals
				self.world.addBinE(line[0], line[1])
			
			elif section == 7: # Read Binary NOT Equals
				self.world.addBinNE(line[0], line[1])

			elif section == 8: # Simultaneous Exclusion
				self.world.addBinS(line[0],line[2], line[1], line[3])




