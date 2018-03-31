"""
controller.py
Play the composition and any installed improvisational measures

#author  Tanuj Sane
#since   11/6/2017
#version 1.0

Changelog:
1.0 Initial commit
"""

from time import sleep as wait
from core import writers, outputs, shared
from dev.improv import generators
import signal

# Main
if __name__ == "__main__":
    print("Loading the music...", end="", flush=True)
    buffer = shared.PlaybackBuffer()
    output = outputs.DebugOutput()

    # Intercept the interrupt signal and clean up the GPIO directory
    signal.signal(signal.SIGINT, lambda *args: output.close())

    # Initialize and start writers
    writers = [
        #writers.MidiFileWriter("speak-now.mid")
        writers.ImprovWriter(500, generators.EuclideanRhythmGenerator(60, 5, 13)),
        writers.ImprovWriter(500, generators.EuclideanRhythmGenerator(72, 3, 8))
    ]
    for writer in writers: writer.start()

    # Wait for something in the music buffer
    while buffer.size() == 0: continue
    print("done!")

    now = 0
    while buffer.size() != 0:
        # Pop the generate set of notes to be played
        notes = buffer.next()

        # Update the global timer
        wait(notes[0].time - now)
        now = notes[0].time

        # PLAY!
        output.play(notes)

    print("FIN")

    # Close the output port
    output.close()
