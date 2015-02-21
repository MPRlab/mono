# Abstract data type that stores the contraints. Contains alls
# methods for accessing these constraints.

import random as rdm

class lADT:

	limit = []

	def __init__(self):
		pass

	# Adds the given limit and validity pair
	def add(self, limit, valid):
		self.limit += [[valid,limit]]

	# Return the limit that is valid for a given timestamp
	def get(self, timestamp):
		if len(self.limit) == 1:
			return self.limit[0][1]

		else:
			for temp in self.limit[1:len(self.limit)]:
				if timestamp in range(temp[0][0], temp[0][1]):
					return temp[1]

		return self.limit[0][1]

# Maintains an Ary Type constraint. 
class aryADT:

	constraint = []

	def __init__(self):
		pass

	# Adds the given constraint to the constraint list
	def add(self, constraint, valid):
		self.constraint += [[valid, constraint]]

# Maintains a Probability Constraint
class pADT:

	probability = []

	def __init__(self):
		pass

	# Adds the given probability to the probability list
	def add(self, probability, valid):
		self.probability += [[valid, probability]]

	# Return a value based on the probability distribution at time
	def get(self, timestamp):
		probability = self.getRaw(timestamp)

		if probability[0] == 1: # Uniform Distribtion
			return int(rdm.uniform(probability[1], probability[2]))

		return int(rdm.uniform(probability[1], probability[2]))

	# Gets the raw probability at the given time
	def getRaw(self, timestamp):
		if len(self.probability) == 0:
			return [1,100,1000] # DEFAULT WHEN NOT GIVEN!!!

		if len(self.probability) == 1:
			return self.probability[0][1]

		else:
			for temp in self.probability[1:len(self.probability)]:
				if timestamp in range(temp[0][0], temp[0][1]):
					return temp[1]

		return self.probability[0][1]

# Maintains a Pattern Constraint
class patADT:

	pattern = []

	def __init__(self):
		pass

	# Adds the given pattern to the pattern list
	def add(self, pattern, toPlay, valid):
		self.pattern += [[valid, pattern, toPlay]]



