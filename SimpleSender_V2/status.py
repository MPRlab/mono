'''
	Status class
'''

from time import time
from copy import deepcopy

class Status:
	def __init__(self, noteMap):
		# Dictionaries for keeping state
		self.notesPlaying = None
		self.noteMap = noteMap

		# Populate class dicionaries
		self.populate()

		# First run of update
		self.update()

	'''
		Creates a dictionary to keep track of time remaining per
		note.
	'''
	def populate(self):
		self.notesPlaying = \
			{val:(0,0) for val in self.noteMap.keys()}


	'''
		Determine which solenoids in each of the boards should be
		active at the moment
	'''
	def findActive(self):
		activeSolenoids = {}

		for key,val in self.notesPlaying.items():
			val = val[0] # Get duration
			if not val == 0:
				boardAndSolenoids = self.noteMap[key]

				if boardAndSolenoids[0] in activeSolenoids.keys():
					activeSolenoids[boardAndSolenoids[0]] += boardAndSolenoids[1]
				else:
					activeSolenoids[boardAndSolenoids[0]] = boardAndSolenoids[1]

			# Remove repeats
			for key,value in activeSolenoids.items():
				activeSolenoids[key] = list(set(value))

		return activeSolenoids

	'''
		Helper method for adding items to dictionary. Adds if
		item is already in, else creates item
	'''
	def appendDict(self, dict):
		pass

	''' 
		Updates the notes playing dictionary. Such that notes
		that have expired (played for their entire duration)
		have their remaining duration set to 0 and others reduce.
	'''
	def update(self):
		minTime = float('infinity')
		for key,value in self.notesPlaying.items():
			if (time() - value[1])*1000 > value[0]:
				self.notesPlaying[key] = (0,0)

			tempTime = (value[0] - (time() - value[1])*1000)
			if tempTime < minTime and tempTime > 0:
				minTime = tempTime

		return minTime

	''' 
		Helper method that allows a note to be marked for playing
		and time stamps automatically.
	'''
	def markNote(self, noteToPlay, noteDuration):
		self.notesPlaying[noteToPlay] = (noteDuration, time())

		return self.update()












