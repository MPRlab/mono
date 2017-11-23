"""
shared.py
Contains shared data across the different files

#author  Tanuj Sane
#since   4/29/2017
#version 1.0

Changelog:
1.0 Initial commit
"""

from threading import Semaphore
from os import getcwd as pwd
from mido import MidiFile, MetaMessage

# An implementation of a HiveMind class (shares data across different instances)
class HiveMind:
    _shared_state = {}

    def __init__(self):
        self.__dict__ = self._shared_state

# A HiveMind class (shares data across different instances) for path management
class PathManager(HiveMind):
    def __init__(self):
        HiveMind.__init__(self)
        self._home = pwd() + "/{}"

    def midi(self, filename):
        return self._home.format(
            "midi/{}".format(filename)
        )

# A HiveMind class (shares data across different instances) encapsulating the playback buffer
class PlaybackBuffer(HiveMind):
    def __init__(self):
        HiveMind.__init__(self)
        self._buffer = []
        self._lock = Semaphore()

    def put(self, note):
        with self._lock: self._buffer.append(note)

    def next(self):
        with self._lock:
            self._buffer.sort(key=lambda msg: msg.time)

            # Grab all notes to be played next - these will all have the same time
            next_note_time = self._buffer[0].time; next_notes = []; done = False
            while not done:
                if self._buffer[0].time == next_note_time:
                    next_notes.append(
                        self._buffer.pop(0)
                    )
                else: done = True

            return next_notes

    def size(self):
        return len(self._buffer)

class CompositionMetaData:
    def __init__(self, filename):
        path = PathManager()

        key_descriptors = {
            'C': 0,
            'C#': 1, 'Db': 1,
            'D': 2,
            'D#': 3, 'Eb': 3,
            'E': 4,
            'F': 5,
            'F#': 6, 'Gb': 6,
            'G': 7,
            'G#': 8, 'Ab': 8,
            'A': 9,
            'A#': 10, 'Bb': 10,
            'B': 11, 'Cb': 11,
        }

        metas = filter(
            lambda n: type(n) is MetaMessage,
            list(MidiFile(path.midi(filename)))
        )

        for meta in metas:
            if meta.type == "time_signature": self._time_signature = (meta.numerator, meta.denominator)
            if meta.type == "key_signature": self._key_descriptor = key_descriptors[meta.key]
            if meta.type == "set_tempo": self._usec_per_beat = meta.tempo
