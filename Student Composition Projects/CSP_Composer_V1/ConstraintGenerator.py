#!/usr/bin/env python
# Creates a constraint file in format supported by constraint
# solver based on a friendlier constraint file for music 
# composition
# By Paulo Carvalho

import sys
import csv

# Save Files Given By User
constraintFile = sys.argv[1]
outputFile = sys.argv[2]
numBins = int(sys.argv[3])
limits = sys.argv[4:6]

######### PART 1: Reading and Parsing Input

# Open Input File, Read and Save to Dictionaries, etc
fi = open(constraintFile)

notes = {} # Dictionary of Notes and Duration
interval = {} # Dictionary of Intervals
unaryI = {} # Unary Inclusions
unaryE = {} # Unary Exclusions
binE = [] # Binary Equality
binNE = [] # Binary Exclusion
uniE = {} # Universal Exclusion - One Cannot Follow Other!

for row in csv.reader(fi):
	if row[0] != 'Note': # Header Field
		note = row[0]
		numOccu = int(row[1])
		durations = row[2].split(';')
		dist = len(durations)

		j = 0
		for i in range(numOccu): # Save Notes
			noteName = note+'_'+str(i)
			notes[noteName] = durations[j]
			j = j+1 if j < dist-1 else 0

		tempUnaryI = row[3].split(';') # Unary Inclusion
		for i in tempUnaryI:
			if i != '':
				for tempNote in notes:
					if tempNote not in unaryI.keys():
						unaryI[tempNote] = [i]
					else:
						unaryI[tempNote] += [i]

		tempUnaryE = row[4].split(';') # Unary Exclusion
		for i in tempUnaryE:
			if i != '':
				for tempNote in notes:
					if tempNote not in unaryE.keys():
						unaryE[tempNote] = [i]
					else:
						unaryE[tempNote] += [i]


fi.close()

########## PART 2: Perform Conversions
# TODO

########## PART 3: Create Bins
for i in range(numBins):
	interval[str(i)] = 1000

########## PART 4: Save to Output File
fo = open(outputFile, 'w')
delimiter = '#####'

# Write Variables (Notes)
fo.write(delimiter + ' - Notes' + '\n')
for note in notes:
	fo.write(note + ' ' + notes[note] + '\n')

# Write Values (Intervals)
fo.write(delimiter + ' - Interval' + '\n')
for value in interval:
	fo.write(value + ' ' + str(interval[value]) + '\n')

# Write Fitting Limits
fo.write(delimiter + ' - Limits' + '\n')
fo.write(limits[0] + ' ' + limits[1] + '\n')

# Write UnaryI 
fo.write(delimiter + ' - UnaryI' + '\n')
for temp in unaryI:
	fo.write(temp + ' ')
	for i in range(len(unaryI[temp])):
		fo.write(unaryI[temp][i] + ' ')
	fo.write('\n')

# Write UnaryE
fo.write(delimiter + ' - UnaryE' + '\n')
for temp in unaryE:
	fo.write(temp + ' ')
	for i in range(len(unaryE[temp])):
		fo.write(unaryE[temp][i] + ' ')
	fo.write('\n')

# Write BinE 
fo.write(delimiter + ' - BinE' + '\n')

# Write BinNE
fo.write(delimiter + ' - BinNE' + '\n')

# Write BinS 
fo.write(delimiter + ' - BinS' + '\n')







