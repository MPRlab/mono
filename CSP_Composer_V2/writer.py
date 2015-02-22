# Writes to the output file in the appropriate format
from constraintsADT import *

class Writer:
	# Constructor
	def __init__(self, outputFileName, comp):
		self.f = open(outputFileName, 'w')
		self.c = comp

		# Run all
		self.write()

	# Write method
	def write(self):
		# Create ordered list from ADT
		tempList = self.c.composition.orderedList()

		# Write to file
		for item in tempList:
			time = str(item[0])
			for note in item[1]:
				if isinstance(note, noteADT):
					pitch = str(note.note)
					dur = str(note.duration)
					reg = str(note.register)
					self.f.write(time + ' ')
					self.f.write(pitch + ' ')
					self.f.write(reg + ' ')
					self.f.write(dur + '\n')