MPR_WORKSPACE
=============

This repository, for the most part, is licensed under GPL V3.0.  This includes any code inside ipython notebooks.  A copy of the GPL V3.0 is available in the file license.txt

This repository is intended to store all code development for the Music Perception and Robotics Lab at WPI.

Currently, it is divided into several different directories:

Old Work:

AudioAnalysis - used for development of a real time pitch and onset detection system

MessagePassing - Test code for message passing via sockets

SharedMemoryTest - Test code for shared memory structure eventually used for leap motion controller

oscpack_1_1_0 - Library code to use for OSC (should have installation code maybe?)

build - All exectuables produced 

New Work:

Algorithmic_Composition_Tools - a directory to place general scripts and tools, like pitch number to western music notation or pitch number to midi output.  

Composition_Workspace_Hughes - Nathan's directory for path planning algorithms and C-Space generator / collision checker

Daughter_Control - directory for eventual software for instrument controllers

Mother_Control - directory for eventual software for motherboard controller

MAX_MSP_MIDI_CONVERTER - max/msp plugin for converting midi to custom osc messages

PAM_CONTROL - directory for old code / test code for pam

PERCUSSION_CONTROL - directory for old code / test code for percussion robot

MISC_DOC - directory for anything that doesn't belong


It also includes the following files:

Makefile - file to make programs from the various directories

README.md - this file

Please note that this repo is very much in progress. Some things that need to be done are the following (but are not limited to)
1) Document current Executables
2) Add Max/MXP plugins to the repo
3) Look into better build system than make

Finally, this repo has programs in a few different langauges and a couple different dependencies.

Languages: C, C++, Python
Dependencies: Jackd (audio analysis), boost (everything), ipython and numpy and scipy (some experimental audio analysis)

The dependencies is not an exhaustive list.  If a program doesn't run, it's probably missing a dependency.
