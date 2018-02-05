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

# Main
if __name__ == "__main__":
    print("Loading the music...", end="", flush=True)
    buffer = shared.PlaybackBuffer()
    output = outputs.DebugOutput()

    # Initialize and start writers
    writers = [
        writers.MidiFileWriter("speak-now.mid")
    ]
    for writer in writers: writer.start()

    # Wait for something in the music buffer
    while buffer.size() == 0: continue
    print("done!")

    now = 0
    while buffer.size() != 0:
        # Pop the next set of notes to be played
        notes = buffer.next()

        # Update the global timer
        wait(notes[0].time - now)
        now = notes[0].time

        # PLAY!
        output.play(notes)

    print("FIN")

    # Close the output port
    output.close()