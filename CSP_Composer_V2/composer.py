# Deals with the composition. Keeps track of constrains
# and current state of the composition.

from constraintsADT import *
import random

class Composer:
	# Time Indexes
	composition = None

	# List of Possible Notes
	notePool = ["A", "As", "B", "C", "Cs", "D", "Ds", "E", "F",\
				"Fs", "G", "Gs"]

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

		### CHOOSE COMPLEMENTARY NOTE
		# "Forward Checking" Add required notes
		# 1) Pattern Matching
		temp = self.pattern.match(self.composition, timestamp)
		if len(temp) != 0:
			for n in temp:
				if self.checkCurrentPlaying(noteADT(n), timestamp):
					tempDuration = self.durationProbability.get(timestamp)
					tempRegister = self.selectRegister(timestamp)
					temp = [noteADT(a, tempRegister, tempDuration) for a in temp] 
					noteList += temp

		# 2) Ary Inclusion Constraint
		currentSet = self.composition.getN(self.consideration.get(timestamp), timestamp)
		temp = self.aryInclusion.getInclusion(currentSet, timestamp)
		if len(temp) != 0:
			for n in temp:
				if self.checkCurrentPlaying(noteADT(n), timestamp):
					tempDuration = self.durationProbability.get(timestamp)
					tempRegister = self.selectRegister(timestamp)
					temp = [noteADT(a, tempRegister, tempDuration) for a in temp] 
					noteList += temp

		### IF NO NOTE IS REQUIRED, CHOOSE A VALID NOTE
		if not noteList:
			tempNoteList = []
			# Choose Duration and Register
			tempDuration = self.durationProbability.get(timestamp)
			tempRegister = self.selectRegister(timestamp)

			# Choose Note (Pitch)
			for pitch in self.notePool:
				tempNote = noteADT(pitch, tempRegister, tempDuration)
				if self.checkAll(tempNote, timestamp):
					tempNoteList += [tempNote]

			noteList = self.noteSelector(tempNoteList, timestamp)

		if noteList:
			return noteList
		return []

	# Select Register
	def selectRegister(self, timestamp):
		# Create register list from notes being currently played
		n = self.consideration.get(timestamp)
		notes = self.composition.getN(n, timestamp)
		reg = [note.register for note in notes]
		reg = list(set(reg)) # Remove duplicates

		# Add range based on jump constraint
		rangeReg = []
		jump = self.jumpLimit.get(timestamp)
		maxReg = self.numRegister.get(timestamp)
		for r in reg:
			rangeReg.append(r)
			temp = r+jump
			if temp <= maxReg:
				rangeReg.append(temp)
			temp = r-jump
			if temp > 0:
				rangeReg.append(temp)

		# Notice that duplicates are NOT removed! That increases
		# the chances of remainin within the current register...
		if not rangeReg: # If Empty
			return 1
		return random.choice(rangeReg)

	# Selects a note from a list of valid notes
	def noteSelector(self, noteList, timestamp):
		if noteList:
			return [noteList[0]]
		return []

	##################################################
	############# Constraint Checks ##################
	##################################################

	# Checks all constraints
	def checkAll(self, note, timestamp):
		return self.checkMaxNoteLimit(timestamp) and self.checkConsecutiveLimit(note, timestamp) \
			and self.checkCurrentPlaying(note, timestamp) and self.composition.checkFutureConflict(note, timestamp) \
			and self.checkAryExclusion(note, timestamp)


	# Returns the number of spaces available in a given timestamp
	def checkMaxNoteLimit(self, timestamp):
		return -self.composition.countNotesInTime(timestamp) \
					+ self.noteLimit.get(timestamp)[1]

	# Returns true if a given note does NOT violate the repetition
	# constraint
	def checkConsecutiveLimit(self, note, timestamp):
		n = self.consecutiveNoteLimit.get(timestamp)
		return self.composition.countConsecutiveNote(note, timestamp, n) < n

	# Returns true if a given register does not violate the register 
	# jump limit.
	def checkRegisterJump(self, note, timestamp):
		return True

	# Returns true if a given note does not violate the 
	# ary exclusion constraint
	def checkAryExclusion(self, note, timestamp):
		notesPlaying = self.composition.getN(self.consideration.get(timestamp), timestamp)
		return self.aryExclusion.checkE(note, notesPlaying, timestamp)

	# Return true if the given note is NOT currently playing
	def checkCurrentPlaying(self, note, timestamp):
		n = self.consideration.get(timestamp)
		return note not in self.composition.getN(n, timestamp) 

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







