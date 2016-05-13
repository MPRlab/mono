# This file contains the current assignme. It also possesses
# the methods for checking validity of the assignment.

class Assign:
	# Class Variables
	assignment = {} # Saves the current assignment!!! Keys are ITEMS!
	maxAssign = 0

	# Constructor
	def __init__(self, maxAssign = 1):
		self.maxAssign = maxAssign # Maximum assignments

	# Adds the given assignment to dictionary
	def addAssignment(self, var, value):
		self.assignment[var] = value

	# Returns the variable that currently has the least items
	def minItems(self):
		