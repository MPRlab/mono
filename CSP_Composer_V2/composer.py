# Deals with the composition. Keeps track of constrains
# and current state of the composition.

from constraintsADT import *

class Composer:
	# Declare Variables
	noteLimit = lADT()
	consecutiveNoteLimit = lADT()
	aryExclusion = aryADT()
	aryInclusion = aryADT()
	consideration = lADT()
	pattern = patADT()
	completion = lADT()
	jumpLimit = lADT()
	silenceProbability = lADT()
	durationProbability = pADT()


	# Constructor
	def __init__(self):
		pass

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

