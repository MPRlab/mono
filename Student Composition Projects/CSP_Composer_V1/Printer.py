# Creates the output file
# Music Format!

from datetime import datetime
import operator

class Printer:
	f = 0

	# Constructor
	def __init__(self, filename):
		self.f = open(filename, 'w')

	# Write Output to file
	def write(self, w):
		# Timestamp
		self.f.write(str(datetime.now()) + '\n\n')

		# Convert from Dictinoary to Ordered Tuple
		time = sorted(w.assignment.items(), key=operator.itemgetter(1))

		impeder = []
		for var,value in time:
			if value not in impeder:
				impeder += value
				tempV = str(int(value)*100)
				self.f.write('T: ' + tempV + ' ') 
				count = 0
				for var in w.assignment:
					if w.assignment[var] == value:
						self.f.write(' |' + var.split('_')[0] + ' ' + str(w.var[var]))
						count += 1
				self.f.write('\n')
				




