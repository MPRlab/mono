# Takes in the user input argument and parse them
# By Paulo Carvalho

from sys import argv

class Config:
	inputFileName = None
	outputFileName = None

	def __init__(self):
		# If two arguments are provided assume input and output file
		if len(argv) == 3:
			self.inputFileName = argv[1]
			self.outputFileName = argv[2]

		# If more than two arguments read through list
		elif len(argv) > 3:
			readCommands()

		else:
			raise Exception('Not enough input arguments! At least 2 expected.')

	# Parses commands
	def readCommands(self):
		for arg in argv[4,-1]:
			pass # TODO! ADD COMMANDS HERE!