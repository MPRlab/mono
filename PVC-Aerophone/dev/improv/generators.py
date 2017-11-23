"""
generator.py
Module containing generators to produce notes via algorithmic composition for improvisation

#author  Tanuj Sane
#since   4/18/2017
#version 1.2

Changelog:
1.2 Moved shared data to `datamodel.py`
1.1 New file structure
1.0 Initial Commit
"""

import json
import math
from ast import literal_eval as parse_list
from os.path import normpath as path
from random import random, choice as choose

from mido import Message

# Shared data
from core.shared import DATA
from core.shared import usec_per_beat, root, time_sig


# Generate Euclidean rhythms
class EuclideanRhythmGenerator:
    def __init__(self, pulses_and_beats, measures):
        # Store pulses and beats
        self.pulses_and_beats = pulses_and_beats

        # The number of measures to play for
        self.measures = measures

    def generate(self):
        # Figure out how many of each rhythm necessary to fill requested measures
        num_cycles = math.floor(self.measures * time_sig[1] / self.pulses_and_beats[1])

        # Generate the rhythm
        rhythm = self._bjorklund()

        delay = 0; beats_since_last = 0
        while num_cycles > 0:
            mask = 1 << self.pulses_and_beats[1] - 1
            for _ in range(self.pulses_and_beats[1]):
                if rhythm & mask:
                    yield Message('note_on', channel=1, note=51, time=delay)
                    delay = 0; beats_since_last = 0

                delay += usec_per_beat / 1e+6
                mask >>= 1
                beats_since_last += 1

            num_cycles -= 1
            delay = beats_since_last * usec_per_beat / 1e+6

    def _bjorklund(self):
        pulses = self.pulses_and_beats[0]
        beats = self.pulses_and_beats[1]

        pieces = [0x01 for i in range(pulses)]                  # each 1 gets an allotted n-bits for storing 0s
        out = 0x00

        s = math.floor((beats - pulses) / pulses)
        r = beats % pulses

        for i in range(pulses):                                 # populate with 0s, tack on remainders
            pieces[i] <<= s
            if r > 0:
                pieces[i] <<= 1
                r -= 1
            out = (out << len(bin(pieces[i])) - 2) + pieces[i]

        return out

# Generate melodies using Markov chain selection
class MarkovChainGenerator:
    def __init__(self, measures, channel):
        # Get the Markov 'matrices' from file
        self._read_matrices()

        # Populate priors with uniformly random selected set of starting states
        # TODO: Make less gross (holy nested bullshit, Batman)
        self.priors = (
            parse_list (
                choose(list(self.pitches.keys()))
            ),
            parse_list (
                choose(list(self.durations.keys()))
            )
        )

        # The number of full measures in the piece to be played for
        self.measures = measures

        self.channel = channel

    def _read_matrices(self):
        with open(path(DATA + 'pitches.json'), 'r') as pitch_file:
            self.pitches = json.load(pitch_file)

        with open(path(DATA + 'durations.json'), 'r') as durs_file:
            self.durations = json.load(durs_file)

    def generate(self):
        # Convert measures into an amount of time to play the generated track
        play_time = self.measures * time_sig[0] * usec_per_beat / 1e+6

        elapsed = 0
        while elapsed < play_time:
            msg = self._next(self.priors)

            # Append abstract versions of notes to the priors
            self.priors[0].append(msg.note)
            self.priors[1].append(msg.time)

            # Message processing - convert pitch and duration to particular from abstract
            msg.note = ((msg.note + root) % 12) + 60
            msg.time = (msg.time / 16) * (usec_per_beat / 1e+6)

            elapsed += msg.time
            if elapsed > play_time:
                msg.time -= (elapsed - play_time)                   # ensure that the last note does not exceed the measure limit

            yield msg

            # Remove the first of each prior to make room for the new note
            self.priors[0].pop(0)
            self.priors[1].pop(0)

    def _next(self, priors):
        pitch_probs = self.pitches[str(priors[0])]
        dur_probs = self.durations[str(priors[1])]

        # An implementation of uniform random weighted selection
        rnd = random(); pitch = -1
        for tup in pitch_probs:
            rnd -= tup[1]
            if rnd < 0:
                pitch = tup[0]
                break

        rnd = random(); duration = -1
        for tup in dur_probs:
            rnd -= tup[1]
            if rnd < 0:
                duration = tup[0]
                break

        return Message('note_on', note=pitch, time=duration)
