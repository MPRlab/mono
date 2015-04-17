#!/usr/bin/python

'''
	Simple sender for the musical orchestra. Takes two files:
		1) Mapping of solenoids to note for each of the boards.
		2) MIDI-like file containing the song to be played
	By Paulo, Anurag and Katie
	Version 2
'''

#############################################
############ SERIAL PORT NAME ###############
#############################################
PORT = '/dev/cu.usbserial-A603RPHO'

from time import time, sleep
from sys import argv

from argParser import ArgParser
from fileParser import MapParser, SongParser
from status import Status
from comm import Comm

def main():
	argParser = ArgParser(argv)
	mapParser = MapParser(argParser.mapFile)
	songParser = SongParser(argParser.songFile)

	# Create Status Class
	status = Status(mapParser.mapping)

	# Instantiate Communication Class (Open Serial)
	comm = Comm(status, PORT)

	# Loops through the entire song
	onsetDelay = 0 # Time to next note, 0 means concurrent
	lineNum = 0 # Start parsing song from first line
	lastNoteUpdate = 0 # Keeps track of time for parsing song
	durationDelay = 0 # Keeps track of next dying note in status
	lastStatusUpdate = 0 # pairs with above
	while lineNum < len(songParser.song) or (durationDelay > 0 \
				and durationDelay < float('infinity')):
		# Check of onset delay and read song
		while (time() - lastNoteUpdate)*1000 > onsetDelay and \
					lineNum < len(songParser.song):
			# Update with information from new line
			onsetDelay = int(songParser.song[lineNum][0])
			noteToPlay = songParser.song[lineNum][1]
			noteDuration = int(songParser.song[lineNum][2])

			# Save to status class
			status.markNote(noteToPlay, noteDuration)

			# Increment line number
			lineNum += 1

			# Save time of last update
			lastNoteUpdate = time()

		# Update the status class to reflect note progression
		if (time() - lastStatusUpdate)*1000 > 10: # Should be durationDelay instead of 10!!!!
			durationDelay = status.update()
			lastStatusUpdate = time()

		# Send updates over serial if solenoid state has changed
		comm.update()

		# TODO: Implement a varying sleep time to use less CPU!!
		sleep(0.01)

	# Ensure all solenoids are turned OFF upon song completion
	status.resetStatus()
	comm.update()

	# Close Serial Port
	comm.close()

	print '*****************************************'
	print 'Song is complete! The burrito cat awaits!'
	print '*****************************************'



if __name__ == '__main__':
	main()




