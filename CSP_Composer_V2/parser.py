# Parses the input file to return all constraints

from constraintsADT import noteADT

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
						self.valid = [int(line[1]),float('infinity')]
					elif len(line) == 3:
						self.valid = [int(line[1]),int(line[2])]

				elif line[0] == '1': # Note Limit constraints
					self.noteLimitParser(line)

				elif line[0] == '2': # Consecutive Note Constraint
					self.consecutiveNoteLimit(line)

				elif line[0] == '3': # Register Jump Limit
					self.registerJumpLimit(line)

				elif line[0] == '4': # Ary Exclusion Constraint
					self.aryExclusion(line)

				elif line[0] == '5': # Ary Inclusion Constraint
					self.aryInclusion(line)

				elif line[0] == '6': # Beginning of Piece
					self.initialNotes(line)

				elif line[0] == '7': # Consideration Constraint
					self.considerationConstraint(line)

				elif line[0] == '8': # Pattern Constraint
					self.patternConstraint(line)

				# Constraint 9 is computed before elif sequence!

				elif line[0] == '10': # Completion Constraint
					self.completionConstraint(line)

				elif line[0] == '11': # Silence Probability
					self.silenceProbability(line)

				elif line[0] == '12': # Note Duration Probability
					self.noteDurationProbability(line)

				elif line[0] == '13': # Number of Registers
					self.numberRegisters(line)

				elif line[0] == '14': # Time parameters of song
					self.timeParameters(line)


	# Parses a line containing the note limit constraint
	def noteLimitParser(self, line):
		try:
			line = map(int, line)
			self.c.addNoteLimit([line[1], line[2]], self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Add note limit constraint ignored.'

	# Parses a line containing a consecutive note limit
	def consecutiveNoteLimit(self, line):
		try:
			line = map(int, line)
			self.c.addConsecNoteLimit(line[1], self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Add consecutive note limit constraint ignored.'

	# Parses a line containing a register jump limit
	def registerJumpLimit(self, line):
		try:
			line = map(int, line)
			self.c.addRegisterJumpLimit(line[1], self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Add register limit constraint ignored.'

	# Parses a line containing an ary Exclusion constraint
	def aryExclusion(self, line):
		try:
			self.c.addAryExclusion(line[1:len(line)], self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint ignored!'

	# Parses a line containing an ary Inclusion constraint
	def aryInclusion(self, line):
		try:
			self.c.addAryInclusion(line[1:len(line)], self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint ignored!'


	##### ADD CONSTRAINT 6 HERE!!!!

	# Parses a line containing a consideration constraint
	def considerationConstraint(self, line):
		default = 5
		try:
			self.c.addConsiderationConstraint(int(line[1]), self.valid)
		except:
			self.c.addConsiderationConstraint(default, self.valid)
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint set to: ' + str(default)

	# Parses a line containing a pattern constraint
	def patternConstraint(self, line):
		pattern = []
		toPlay = []
		switch = True

		try:
			for p in line[1:len(line)]:
				if p == '|':
					switch = False
				elif switch == True:
					pattern += p
				else:
					toPlay += p

			self.c.addPatternConstraint(pattern, toPlay, self.valid)
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint ignored!'

	# Parses a line containing the song completion constraint
	def completionConstraint(self, line):
		default = 150
		try:
			self.c.addCompletionConstraint(int(line[1]), self.valid)
		except:
			self.c.addCompletionConstraint(default, self.valid)
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint set to: ' + str(default)

	# Parses a line containing a silence probability
	def silenceProbability(self, line):
		default = 50
		try:
			self.c.addSilenceProbability(int(line[1]), self.valid)
		except:
			self.c.addSilenceProbability(default, self.valid)
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint set to: ' + str(default)

	# Parses a line containing the note duration probability
	def noteDurationProbability(self, line):
		default = [1,100,1000]
		try:
			line = map(int, line)
			self.c.addDurationProbability([line[1],line[2],line[3]], self.valid)
		except:
			self.c.addDurationProbability(default, valid)
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint set to: ' + str(default)


	# Parses a line containing number of registers
	def numberRegisters(self, line):
		try:
			self.c.addNumRegisters(int(line[1]))
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint ignored!'

	# Parses a line containing time parameters
	def timeParameters(self, line):
		default = [50, 50]
		try:
			line = map(int, line)
			self.c.addTimeParameters([line[1], line[2]])
		except:
			self.c.addTimeParameters([default[0], default[1]])
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint set to: ' + str(default)

	# Parses the beginning of the song
	def initialNotes(self, line):
		try:
			tempNote = noteADT(line[2], int(line[3]), int(line[4]))
			self.c.initialNotes += [[int(line[1]), tempNote]]
		except:
			print 'Line: ' + str(line) + ' is broken.'
			print 'Constraint ignored!'











