"""
trainer.py
Provides training mechanisms for trainable algorithms

#author  Tanuj Sane
#since   4/18/2017
#version 1.2

Changelog:
1.2 Moved shared data to `datamodel.py`
1.1 New file structure
1.0 Initial Commit
"""

import json
from os import listdir as ls
from os.path import normpath as path

from mido import MidiFile, MetaMessage

# Shared data
from core.shared import MIDI, DATA

"""
Encapsulation of training functionality
"""
class MarkovChainTrainer:
    def __init__(self):
        # The Markov 'matrices'
        self.pitches = {}
        self.durations = {}

        # Tuple holding pitch, duration state
        self.priors = ([], [])

        # Mapping of keys from letters to identifiers
        # TODO: Find some math to do this
        self.key_map = {
            'Cb': 11,
            'C': 0,
            'C#': 1,
            'Db': 1,
            'D': 2,
            'D#': 3,
            'Eb': 3,
            'E': 4,
            'F': 5,
            'F#': 6,
            'Gb': 6,
            'G': 7,
            'G#': 8,
            'Ab': 8,
            'A': 9,
            'A#': 10,
            'Bb': 10,
            'B': 11,
        }

    def study(self):
        for filename in ls(MIDI):
            print('Training with: {}'.format(filename))
            naptime = 0

            data = self._get_metadata(filename)
            root = data['root']; usec_per_beat = data['usec_per_beat']

            for msg in MidiFile(path(MIDI + filename)):
                if msg.type == 'note_on':
                    if msg.velocity == 0:
                        naptime += msg.time
                        continue

                    msg.time += naptime
                    naptime = 0

                    # Note processing - convert to [0:12] with the root as 0
                    pitch = (msg.note - root) % 12

                    # Duration processing - convert sec -> usec -> beats -> 16ths, throw out stupid values
                    duration = 16 * (msg.time * 1e+6) / usec_per_beat
                    if not 0 < duration <= 16 or not duration % 1 == 0: continue

                    if len(self.priors[0]) == 4:
                        pitch_key = str(self.priors[0])
                        duration_key = str(self.priors[1])

                        # The lazy way to do it - if key not exist, put it there
                        try:
                            self.pitches[pitch_key].append(pitch)
                        except KeyError:
                            self.pitches[pitch_key] = [pitch]

                        try:
                            self.durations[duration_key].append(duration)
                        except KeyError:
                            self.durations[duration_key] = [duration]

                        self.priors[0].pop(0)
                        self.priors[1].pop(0)

                    self.priors[0].append(pitch)
                    self.priors[1].append(duration)

        self._to_probs()
        self._write_matrices()

    def _get_metadata(self, filename):
        data = {}
        for msg in MidiFile(path(MIDI + filename)):
            if isinstance(msg, MetaMessage):
                if msg.type == 'key_signature':
                    data['root'] = self.key_map[msg.key[:2]]
                elif msg.type == 'time_signature':
                    data['time'] = (msg.numerator, msg.denominator)
                elif msg.type == 'set_tempo':
                    data['usec_per_beat'] = msg.tempo

        return data

    """
    Convert 'matrix' of counts to a Markov chain matrix of probabilities
    """
    def _to_probs(self):
        for key, value in self.pitches.items():
            total = len(value); probs = []

            # Remove duplicates
            for i in set(value):
                probs.append((i, value.count(i) / total))

            self.pitches[key] = probs

        for key, value in self.durations.items():
            total = len(value); probs = []

            # Ditto ^
            for i in set(value):
                probs.append((i, value.count(i) / total))

            self.durations[key] = probs

    """
    Write out matrices to file for storage and retrieval
    """
    def _write_matrices(self):
        with open(path(DATA + 'pitches.json'), 'w') as pitch_file:
            # Print pretty out to the files
            json.dump(self.pitches, pitch_file, indent=1, separators=(',', ': '))

        with open(path(DATA + 'durations.json'), 'w') as durs_file:
            json.dump(self.durations, durs_file, indent=1, separators=(',', ': '))

if __name__ == '__main__':
    trainers = [
        MarkovChainTrainer()
    ]

    for trainer in trainers:
        trainer.study()
