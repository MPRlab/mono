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
import random as rdm

rdm.seed(1) ## TODO!!

# Read user input arguments
c = Config()

# Create composer object
comp = Composer()

# Parse input 
p = Parser(c.inputFileName, comp)
comp.setUp()  

# Run the Solver
sol = Solver(100)
solution = sol.solve(comp)

# Write Result to file
w = Writer(c.outputFileName, comp)

