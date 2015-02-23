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

		# Dictionary of notes
		notePool = {"A":1, "As":2, "B":3, "C":4, "Cs":5, "D":6, "Ds":7,\
		 		"E":8, "F":9, "Fs":10, "G":11, "Gs":12}

		# Write to file
		dTime = 0
		previousTime = 0
		for item in tempList:
			for note in item[1]:
				time = item[0]
				dTime = time - previousTime
				previousTime = time
				if isinstance(note, noteADT):
					pitch = str(note.note)
					dur = str(note.duration)
					reg = note.register
					pitch = int(notePool[pitch]) # Convert to Number
					pitch *= reg
					self.f.write(str(dTime) + ' ')
					self.f.write(str(time) + ' ')
					self.f.write(str(pitch) + ' ')
					self.f.write(dur + '\n')