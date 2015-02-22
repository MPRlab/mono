# Abstract data type that stores the contraints. Contains alls
# methods for accessing these constraints.

import random as rdm
import operator

class lADT:

	def __init__(self):
		self.limit = []

	# Adds the given limit and validity pair
	def add(self, limit, valid = [0,float('infinity')]):
		self.limit += [[valid,limit]]

	# Return the limit that is valid for a given timestamp
	def get(self, timestamp=0):
		if len(self.limit) == 0:
			return []

		if len(self.limit) == 1:
			return self.limit[0][1]

		else:
			for temp in self.limit[1:len(self.limit)]:
				if timestamp in range(temp[0][0], temp[0][1]):
					return temp[1]

		return self.limit[0][1]

# Maintains an Ary Type constraint. 
class aryADT:

	def __init__(self):
		self.constraint = []

	# Adds the given constraint to the constraint list
	def add(self, constraint, valid):
		self.constraint += [[valid, constraint]]

	# Returns true if there are NO conflicts for Exclusion
	def checkE(self, currentSet, timestamp):
		for c in get(timestamp):
			for cur in currentSet:
				if cur in c:
					return cur
		return []

	# Returns the raw constraint at the given time
	def get(self, timestamp):
		if len(self.constraint) == 1:
			return self.constraint[0][1]

		else:
			for temp in self.constraint[1:len(self.constraint)]:
				if timestamp in range(temp[0][0], temp[0][1]):
					return temp[1]

		return self.constraint[0][1]

# Maintains a Probability Constraint
class pADT:

	def __init__(self):
		self.probability = []

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

	def __init__(self):
		self.pattern = []

	# Adds the given pattern to the pattern list
	def add(self, pattern, toPlay, valid):
		for item in self.pattern:
			if valid == item[0]:
				item[1].append([pattern, toPlay])
				return True
		self.pattern += [[valid, [[pattern, toPlay]]]]

	# Returns notes to be added if a pattern match is found
	def match(self, c, timestamp):
		tempList = []
		stepSize = c.stepSize
		
		for both in self.get(timestamp):
			count = 0
			n = len(both[0])
			for tstamp in range(timestamp-n*stepSize, timestamp, stepSize):
				if tstamp >= 0:
					j = (tstamp - (timestamp - n*stepSize)) / stepSize
					if both[0][j] in [a.note for a in c.getN(n,timestamp)]:
						count += 1

			if count >= n:
				tempList += both[1]

		return tempList

				

	# Returns the raw constraint at the given time
	def get(self, timestamp):
		if len(self.pattern) == 1:
			return self.pattern[0][1]

		else:
			for temp in self.pattern[1:len(self.pattern)]:
				if timestamp in range(temp[0][0], temp[0][1]):
					return temp[1:len(self.pattern[0])]

		return self.pattern[0][1]


# Maintains the song
class songADT:

	def __init__(self, duration, stepSize):
		duration = duration * 1000
		self.duration = duration
		self.stepSize = stepSize
		self.song = {}

		for i in range(int(duration/stepSize)):
			self.song[i*stepSize] = []

	# Returns all notes being played at a given time. This 
	# includes notes that are running into the current time
	# n previous time slots are considered.
	def getN(self, n, timestamp):
		tempList = []
		for i in range(timestamp, timestamp-n*self.stepSize, -self.stepSize):
			if i >= 0:
				for note in self.song[i]:
					if isinstance(note, noteADT):
						if note.duration > timestamp-i:
							tempList += [note]

		return tempList

	# Returns TRUE if the addition of a given note does not
	# lead to a conflict of "same note".
	def checkFutureConflict(self, nt, timestamp):
		tempList = []
		n = nt.duration
		for i in range(timestamp, timestamp+n, self.stepSize):
			if i <= max(self.song):
				for note in self.song[i]:
					if isinstance(note, noteADT):
						if note == nt:
							return False

		return True

	# Adds the given note to the specified time slot
	def add(self, note, timestamp):
		self.song[timestamp] += [note]

	# Removes the given note from a specified time slot
	def remove(self, note, timestamp):
		self.song[timestamp].remove(note)

	# Returns a list of all time indexes
	def keys(self):
		return sorted(self.song.keys())

	# Returns the number of notes in the song
	def countNotes(self):
		total = 0

		for noteList in self.song.values():
			total += len(noteList)

		return total

	# Returns the number of notes in a given time stamp
	def countNotesInTime(self, timestamp):
		return len(self.song[timestamp])

	# Consecutive note count
	def countConsecutiveNote(self, note, tstamp, n):
		occurences = 0
		for i in range(tstamp-n*self.stepSize, tstamp, self.stepSize):
			if i >= 0:
				for nt in self.song[i]:
					if isinstance(nt, noteADT):
						if note.note == nt.note:
							occurences += 1
		return occurences 

	# Returns as an ordered list
	def orderedList(self):
		return sorted(self.song.items(), key=operator.itemgetter(0))

# Maintains a note
class noteADT:

	def __init__(self, note, register=1, duration=500):
		self.duration = duration
		self.note = note
		self.register = register

	def setRegister(self, register):
		self.register = register

	def setDuration(self, duration):
		self.duration = duration

	def __str__(self):
		return str(self.note) + ' ' + str(self.register) + ' ' + str(self.duration)

	def __eq__(self, other):
		return self.note == other.note and self.register == other.register







