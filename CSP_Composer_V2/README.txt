CSP_Composer_V2 README File
By Paulo Carvalho

##########################################################
############ SECTION 1: HOW TO RUN PROGRAM ###############
##########################################################

On the terminal of a python enabled computer run the 
following command:
	
	./main.py inputFile outputFile [...]

		where [...] are the optional arguments

			ADD OPTIONAL ARGUMENTS HERE


##########################################################
############# SECTION 2: INPUT FILE FORMAT ###############
##########################################################

The input file contains all constraints the generated song
will follow. The Constraints can be of the following general
types:
	
	1) Note Limit Constraint: A pair of integers indicating the 
	maximum and lowest number of notes that can be played at the
	same time.

	2) Consecutive Note Constraint: Limits the number of repeated
	occurences of any one note (contiguously). 
		Ex: If CNC constraint is 3, a song cannot have A A A A

	3) Register Jump Limit Constraint: An integer determining the
	maximum number of registers that a new note can jump given the
	register of the previous note.
		Ex: If RJLC is 0, voice has to go through all registers
		in between its current register and desired regiter.
		No jumps allowed!

	4) Ary Exclusion Constraint: A given set of notes, cannot
	be played together. Ex: A B C cannot be played simultaneously

	5) Ary Inclusion Constraint: A given pair of notes, can 
	only be played together.

	6) Set Beginning of Piece Constraint: Manually sets a certain
	number of notes in the beginning of the song. Initial conditions!

	7) Consideration Constraint: Number of timestamps to consider
	when placing the next note. Very IMPORTANT constraint!!!

	8) Pattern Constraint: If a given sequence of notes is played
	play a given set of notes next.
		Ex: If A B C has just been played, play D

	9) "Valid for" Constraint: Sets the lifetime of a certain
	section of the constraint file.

	10) Completion Constraint: A song is deemed complete once it
	has reached a certain number of notes.

	11) Rhythm: Silence Probability: Sets the probability of a
	given time stamp containing a silence.

	12) Rhythm: Note Duration Probability: Sets the probability 
	distribution for note durations.
		Should be a set of integers that selects from a given
		set of probability distributions. Ex: 1 10 100 is a
		uniform distribution from 10 to 100.
		Options include:
			1 min max - uniform distribution
			2 mu sigma - gauss distribution

	13) Number of Registers Constraint: Number of registers in
	the instrument where the song will be played.

	14) Time parameters of the song. Ex: 300 50, creates a song
	that is 5 min long and has time divisions of 50 ms.

	15) Probability Seed: Determines the seed to be used in the
	random number generators. Guarantees that a given input file
	always generates the same output. Note that this attribute 
	is ubiquitous to the file.

The File format should follow exacly:

##### 
# Note Limit Constraints
1 0 3 
# Consecutive Notes Constraints
2 3
# Regsiter Jump Limit Constraint
3 1
# Set beginning of Piece Constraint
# Organized by: Contraint TimestampIndex Note Register Duration
6 0 A 1 100
6 1 B 1 300
6 2 C 1 500 
6 2 A 1 500
# Consideration Constraint
7 3
# Pattern Constraint
8 A B C | D
# Completion Constraint
10 100
# Number of Registers Constraint
13 3
# Time Constraints
14 10 50
















