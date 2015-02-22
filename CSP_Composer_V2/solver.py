# Makes the assignments on the world in order to create a song

class Solver:
	# Declare Variables
	comp = None

	# Constructor
	def __init__(self):
		pass

	# Solver
	def solve(self, c):

		# Attempt to Satisfy other Constraints
		while 1:
			for timeStamp in c.composition.keys():
				noteList = c.selectNote(timeStamp)

				if noteList: # List not empty
					for note in noteList:
						c.composition.add(note, timeStamp)

			if c.isComplete():
				return c

