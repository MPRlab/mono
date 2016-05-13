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
from logger import *
import random as rdm

# Read user input arguments
c = Config()

# Create Logger Object
l = None
if c.logFileName != None:
	l = Logger(c.logFileName, c.verbose)

# Create composer object
comp = Composer()

# Parse input 
p = Parser(c.inputFileName, comp)
comp.setUp()  

# Run the Solver
sol = Solver(c.numIterations, l)
solution = sol.solve(comp)

# Write Result to file
w = Writer(c.outputFileName, comp)

