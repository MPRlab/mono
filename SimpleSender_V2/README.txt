Simple Sender V2 README File
By Paulo and Katie

This software can be used as a simple interface between
the multisolenoid driver boards and a computer.

Features:
	1) Handles playing songs that use solenoids distributed
	among multiple boards.

	2) Simple input format and mapping.

inputs:
	1) Mapping File:
		A file containing the mapping between notes (or chords)
		and the board and solenoid collection that compose it.
		Format of file should be a:
			NOTE_NAME,BOARD_ID,SOL1;SOL2;SOL3;SOLN

			Notice that items are separated with commas with a new
			line character in the end of each line.
				Solenoids are separated by semi-colons

	2) Song File:
		A file containing the song to be played in a MIDI inspired
		format.
			ONSET_DELAY,NOTE_NAME,DURATION_OF_NOTE

			Notice that to have multiple notes playing at the same
			time each note should be on its own line with 
			ONSET_DELAY of 0 between them.

Executing:
	To execute the program CD into the program folder and run:

		./main.py MAPPING_FILE_PATH SONG_FILE_PATH