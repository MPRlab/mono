'''
	Argument parser
'''

'''
	Current version of the argument parser takes two arguments.
		1) First argument is the path to the mapping file. See
			README for more details on file format.
		2) Second argument is the path to the song file. See
			README for more details on file format.
'''

class ArgParser:
	''' 
		Constructor
	'''
	def __init__(self, argv):
		self.songFile = None
		self.mapFile = None

		self.argv = argv

		# Parse arguments
		self.parse()

	def parse(self):
		# Check length of argument
		if len(self.argv) < 3:
			raise NameError('Not enough input arguments...')

		# Get path to the mapping file
		self.mapFile = self.argv[1]

		# Get path to the song file
		self.songFile = self.argv[2]