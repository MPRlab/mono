# Makes the assignments on the world in order to create a song

class Solver:
	# Constructor
	def __init__(self, threshold=10, logger=None):
		self.iteTreshold = threshold
		self.logger = logger

	# Solver
	def solve(self, c):

		# Attempt to Satisfy other Constraints
		ite = 0
		while ite < self.iteTreshold:
			for timeStamp in c.composition.keys():
				noteList = c.selectNote(timeStamp)

				if noteList: # List not empty
					for note in noteList:
						c.composition.add(note, timeStamp)

				if c.isComplete():
					print "Algorithm completed successfully!"
					if self.logger != None:
						self.logger.logCompletion(c, ite)
					return c
			ite += 1

			if self.logger != None:
				self.logger.logIteration(c, ite)

		print "Algorithm has reached maximum number of iterations..."
		return c

