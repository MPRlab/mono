#!/usr/bin/env python
# Main file
# By Paulo Carvalho 

from Parser import Parser
from World import World
from CSP import CSP
from Printer import Printer
import sys

# Get User Input from Terminal
inputFileName = sys.argv[1]
outputFileName = sys.argv[2]
minCapacityConstraint = int(sys.argv[3])
if len(sys.argv) > 4:
	overallCapacityConstraint = int(sys.argv[4])

# Create Classes
world = World(minCapacityConstraint,overallCapacityConstraint)
csp = CSP()

# Read the input file
parser = Parser(inputFileName, world)
parser.read() 

# PERFORM CSP CALCULATION!!!
result = csp.backtrackSearch(world)

# Print Fail or Pass
print "******************************"
if not result.isComplete():
	print "Assignment not possible..."
else:
	print "Finished Assignment!"
print "Assigned: " + str(result.assignment)
print "With unused capacity: " + str(result.calcTotalUnusedCapacity()) + \
	" of " + str(result.calcTotalCapacity())
print "In " + str(csp.counter) + " iterations."
print "******************************"

# Print Final Result
printer = Printer(outputFileName)
printer.write(result)


