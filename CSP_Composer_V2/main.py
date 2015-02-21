#!/usr/bin/python
# Software for algorithmic composition. Given a set of 
# constraints it outputs the MIDI sequence for playing a song
# By Paulo Carvalho

from sys import argv
from config import Config
from composer import *
from parser import *

# Read user input arguments
c = Config()

# Create composer object
comp = Composer()

# Parse input 
p = Parser(c.inputFileName, comp)

print comp.durationProbability.get(100)
print comp.durationProbability.get(100)
print comp.durationProbability.get(100)
print comp.durationProbability.get(100)
print comp.durationProbability.get(100)