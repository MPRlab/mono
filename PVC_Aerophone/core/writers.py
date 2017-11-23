"""
writers.py
Thread subclasses that write notes to the shared buffer

#author  Tanuj Sane
#since   11/6/2017
#version 1.0

Changelog:
1.0 Initial commit
"""

from threading import Thread
from mido import MidiFile
from core import shared

# Read in from file and populate the playback buffer
class MidiFileWriter(Thread):
    def __init__(self, filename):
        super(MidiFileWriter, self).__init__()

        # Access the singleton instance
        path = shared.PathManager()

        # Grab the notes to be added
        self._notes = filter(
            lambda n : n.type == "note_on",
            list(MidiFile(
                path.midi(filename)
            ))
        )

        # Grab the singleton instance of the playback buffer
        self._buffer = shared.PlaybackBuffer()

    def run(self):
        now = 0
        for note_on in self._notes:
            if note_on.velocity == 0:
                now += note_on.time
                continue

            # Put into absolute time (rather than relative time)
            note_on.time += now; now = note_on.time
            self._buffer.put(note_on)

# Generate improvisational tracks and populate the playback buffer
class ImprovWriter(Thread):
    def __init__(self, generator):
        super(ImprovWriter, self).__init__()
        self.generator = generator

        # Grab the singleton instance of the playback buffer
        self._buffer = shared.PlaybackBuffer()

    def run(self):
        now = 0
        for note in self.generator.generate():
            now += note.time; note.time = now
            self._buffer.put(note)
