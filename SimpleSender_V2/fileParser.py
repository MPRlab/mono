'''
	Contains classes for parsing the input files
'''

'''
	Note:
		The mapParser assumes that the file format is as follows:
			'NOTE, BOARD_ID, [SOLENOID LIST]'
'''
class MapParser:
	def __init__(self, fileName):
		self.fileName = fileName
		self.mapping = None

		# Parse the file
		self.parse()

	'''
		Parses the input file and saves to a dictionary
	'''
	def parse(self):
		# Open the file safely
		with open(self.fileName) as f:
			self.mapping = {}
			data = f.readlines()
			for line in data:
				try:
					line = line.rstrip().split(',')
					self.mapping[line[0]] = [line[1], line[2].split(';')]
				except:
					print 'Line: ' + str(line) + ' ignored.'

class SongParser:
	def __init__(self, fileName):
		self.fileName = fileName
		self.song = None

		# Parse the file
		self.parse()

	'''
		Parses the input file and saves data to list 
	'''
	def parse(self):
		# Open the file safely
		with open(self.fileName) as f:
			self.song = []
			data = f.readlines()
			for line in data:
				try:
					line = line.rstrip().split(',')
					self.song.append([line[0], line[1], line[2]])
				except:
					print 'Line: ' + str(line) + ' ignored.'



