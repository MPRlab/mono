# Deals with the composition. Keeps track of constrains
# and current state of the composition.

from constraintsADT import *

class Composer:
	# Time Indexes
	composition = None

	# List of Possible Notes
	notePool = ['A', 'As', 'B', 'C', 'Cs', 'D', 'Ds', 'E', 'F',\
				'Fs', 'G', 'Gs']

	# Constructor
	def __init__(self):
		# Declare Variables
		self.noteLimit = lADT()
		self.consecutiveNoteLimit = lADT()
		self.aryExclusion = aryADT()
		self.aryInclusion = aryADT()
		self.consideration = lADT()
		self.pattern = patADT()
		self.completion = lADT()
		self.jumpLimit = lADT()
		self.silenceProbability = lADT()
		self.durationProbability = pADT()
		self.timeParameters = lADT()
		self.numRegister = lADT()
		self.initialNotes = [] # List of [timestamp, noteADT]

	##################################################
	############### ADDER METHODS ####################
	##################################################
	def addNoteLimit(self, limit, valid):
		self.noteLimit.add(limit, valid)

	def addConsecNoteLimit(self, limit, valid):
		self.consecutiveNoteLimit.add(limit, valid)

	def addRegisterJumpLimit(self, limit, valid):
		self.jumpLimit.add(limit, valid)

	def addAryExclusion(self, constraint, valid):
		self.aryExclusion.add(constraint, valid)

	def addAryInclusion(self, constraint, valid):
		self.aryInclusion.add(constraint, valid)

	def addConsiderationConstraint(self, limit, valid):
		self.consideration.add(limit, valid)

	def addPatternConstraint(self, pattern, toPlay, valid):
		self.pattern.add(pattern, toPlay, valid)

	def addCompletionConstraint(self, limit, valid):
		self.completion.add(limit, valid)

	def addSilenceProbability(self, probability, valid):
		self.silenceProbability.add(probability, valid)

	def addDurationProbability(self, probability, valid):
		self.durationProbability.add(probability, valid)

	def addNumRegisters(self, limit):
		self.numRegister.add(limit)

	def addTimeParameters(self, par):
		self.timeParameters.add(par)

	##################################################
	############# ALGORITHM RELATED ##################
	##################################################

	# Checks if the song is complete
	def isComplete(self):
		numNotes = self.composition.countNotes()

		if numNotes > self.completion.get():
			return True

		return False

	# Returns a list of notes that will be added to the given
	# time stamp. Can be one note of more if constraints have
	# to be satisfied.
	def selectNote(self, timestamp):
		noteList = []

		# Choose Note (Pitch)
		finalPitch = 0
		for pitch in self.notePool:
			if self.checkAllForPitch(noteADT(pitch), timestamp):
				finalPitch = pitch

		# Choose Register
		finalRegister = 1

		# Choose Duration
		finalDuration = self.durationProbability.get(timestamp)

		# Add First note to list
		if finalPitch and finalRegister:
			noteList += [noteADT(finalPitch, finalRegister, finalDuration)]

		return noteList


	##################################################
	############# Constraint Checks ##################
	##################################################

	# Checks all constraints
	def checkAllForPitch(self, note, timestamp):
		return self.checkMaxNoteLimit(timestamp) and self.checkConsecutiveLimit(note, timestamp)


	# Returns the number of spaces available in a given timestamp
	def checkMaxNoteLimit(self, timestamp):
		return -self.composition.countNotesInTime(timestamp) \
					+ self.noteLimit.get(timestamp)[1]

	# Returns true if a given note does NOT violate the repetition
	# constraint
	def checkConsecutiveLimit(self, note, timestamp):
		n = self.consecutiveNoteLimit.get(timestamp)
		return self.composition.countConsecutiveNote(note, timestamp, n) < \
		 			self.consecutiveNoteLimit.get(timestamp)

	# Returns true if a given register does not violate the register 
	# jump limit.
	def checkRegisterJump(self, note, timestamp):
		return True

	# Returns true if a given note does not violate the 
	# ary exclusion constraint
	def checkAryExclusion(self, note, timestamp):
		return True

	##################################################
	############### Helper Methods ###################
	##################################################

	# Initializes the Composition Class (SongADT)
	# And fills out the beginning of the song
	def setUp(self):
		timeParameters = self.timeParameters.get(0)
		self.composition = songADT(timeParameters[0], timeParameters[1])

		for note in self.initialNotes:
			self.composition.add(note[1],note[0]*timeParameters[1])







