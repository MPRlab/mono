# Takes in the user input argument and parse them
# By Paulo Carvalho

from sys import argv

class Config:
	inputFileName = None
	outputFileName = None
	logFileName = None
	numIterations = 5

	def __init__(self):
		# If two arguments are provided assume input and output file
		if len(argv) >= 3:
			self.inputFileName = argv[1]
			self.outputFileName = argv[2]

		# If more than two arguments read through list
		if len(argv) > 3:
			self.readCommands()

		else:
			raise Exception('Not enough input arguments! At least 2 expected.')

	# Parses commands
	def readCommands(self):
		iteIsNext = False # Iteration Command is the next to be read
		logIsNext = False # Logging Command is the next to be read
		for arg in argv[4:len(argv)]:
			if arg == '-i': # Number of iterations allowed
				iteIsNext = True
			elif iteIsNext:
				self.numIterations = int(numIterations)
				iteIsNext = False
			
			if arg == '-l': # Enable Logging and Next argument is file
				logIsNext = True
			elif logIsNext:
				self.logFileName = arg
				logIsNext = False


