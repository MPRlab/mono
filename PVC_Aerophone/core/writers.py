"""
writers.py
Thread subclasses that write notes to the shared buffer

#author  Tanuj Sane
#since   11/6/2017
#version 1.0

Changelog:
1.0 Initial commit
"""

import threading
import mido
from core import shared
from time import sleep as wait

# Read in from file and populate the playback buffer
class MidiFileWriter(threading.Thread):
    def __init__(self, filename):
        super(MidiFileWriter, self).__init__()

        # Access the singleton instance
        path = shared.PathManager()

        # Grab the notes to be added
        self._notes = filter(
            lambda n : n.type == "note_on",
            list(mido.MidiFile(
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
class ImprovWriter(threading.Thread):
    def __init__(self, usec_per_beat, generator):
        """
        Constructor

        :param usec_per_beat:   The tempo of the piece, used to ensure improv is in time
        :param generator:       The generator to use to create the improvised music
        """
        super(ImprovWriter, self).__init__()
        self._stop_event = threading.Event()

        self._usec_per_beat = usec_per_beat
        self._generator = generator

        # Grab the singleton instance of the playback buffer
        self._buffer = shared.PlaybackBuffer()

    def run(self):
        now = 0
        while not self._stop_event.is_set():
            for note in self._generator.generate():
                now += (self._usec_per_beat / 1000) * note.time; note.time = now
                self._buffer.put(note)

    def end(self):
        self._stop_event.set()