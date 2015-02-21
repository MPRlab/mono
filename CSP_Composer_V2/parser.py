# Parses the input file to return all constraints

class Parser:
	f = None
	c = None
	valid = [0,float('infinity')]

	def __init__(self, fileName, composer):
		self.f = open(fileName, 'r')
		self.c = composer

		# Parse the file
		self.parse()

	def parse(self):
		for line in self.f.readlines():
			line = line.split()
			if len(line): # If line is not empty
				if line[0] == '#': # Line is a comment. Ignore
					pass
				
				elif line[0] == '#####': # Validity Constraint
					if len(line) == 2:
						self.valid = [line[1],float('infinity')]
					elif len(line) == 3:
						self.valid = [line[1],line[2]]

				elif line[0] == '1': # Note Limit constraints
					self.noteLimitParser(line)


	# Parses a line containing the note limit constraint
	def noteLimitParser(self, line):
		try:
			line = map(int, line)
			c.addNoteLimit([line[1], line[2]], self.valid)
			print c.noteLimit.limit
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Add note limit constraint ignored.'

	# Parses a line containing a consecutive note limit
	def consecutiveNoteLimit(self, line):
		try:
			c.addConsecNoteLimit(line[1], self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Add consecutive note limit constraint ignored.'