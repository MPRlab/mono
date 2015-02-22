#!/usr/bin/python
# Software for algorithmic composition. Given a set of 
# constraints it outputs the MIDI sequence for playing a song
# By Paulo Carvalho

from sys import argv
from config import Config
from composer import *
from parser import *
from solver import *
from writer import *

# Read user input arguments
c = Config()

# Create composer object
comp = Composer()

# Parse input 
p = Parser(c.inputFileName, comp)
comp.setUp()  

# Run the Solver
sol = Solver()
solution = sol.solve(comp)
print "Finished processing..."

# Write Result to file
w = Writer(c.outputFileName, comp)

