# Abstract data type that stores the contraints. Contains alls
# methods for accessing these constraints.

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