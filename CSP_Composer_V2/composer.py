# Deals with the composition. Keeps track of constrains
# and current state of the composition.

from constraintsADT import *

class Composer:
	noteLimit = lADT()
	consecutiveNoteLimit = lADT()

	def __init__(self):
		pass

	##################################################
	############### ADDER METHODS ####################
	##################################################
	def addNoteLimit(self, limit, valid):
		self.noteLimit.add(limit, valid)

	def addConsecNoteLimit(self, limit, valid):
		self.consecutiveNoteLimit.add(limit, valid)