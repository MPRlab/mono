#! /usr/bin/env python

__author__ = 'nathan'

import matplotlib.pyplot as plt
import sys
import numpy as np


class SongVisualizer:

    def __init__(self):
        colors = [(1.0, 0., 0.), (1.0, 0.5, 0.), (1.0, 1.0, 0.), (0.5, 1., 0.), (0., 1., 0.), (0., 1., 0.5),
                  (0., 1., 1.), (0., 0.5, 1.0), (0., 0., 1.0), (0.5, 0., 1.), (1., 0., 1.), (1., 0., 0.5)]
        self.colors = colors

    def output_line(self, line, times, durations, pos):
        colors = []
        for i in range(len(line)):
            pitch = line[i]
            if pitch != -1:
                color = self.colors[pitch % 12]
            else:
                color = (1., 1., 1.)
            colors.append(color)
        pitch_heights = np.array(line) % 12 / 24. + pos
        plt.barh(pitch_heights, durations, left=times, color=colors, edgecolor="none", height=1/24.)

    @staticmethod
    def create_lines_from_file_contents(times, pitches, durations, voices):
        pitch_lines = [[pitches[0]], [pitches[1]]]
        time_lines = [[times[0]], [times[1]]]
        duration_lines = [[durations[0]], [durations[1]]]
        for i in range(1, len(times)):
            if voices[i] == 1:
                pitch_lines[1].append(pitches[i])
                duration_lines[1].append(durations[i])
                time_lines[1].append(times[i])
            if voices[i] == 0:
                pitch_lines[0].append(pitches[i])
                duration_lines[0].append(durations[i])
                time_lines[0].append(times[i])
        return pitch_lines, time_lines, duration_lines

    def plot_lines(self, pitches, times, durations):
        for i in range(len(pitches)):
            self.output_line(pitches[i], times[i], durations[i], i)
        plt.gca().set_ylim(-1, len(pitches))
        plt.show()

    def do_everything(self, file_path):
        import re
        pitches = []
        times = []
        durations = []
        voices = []
        with open(file_path, "r") as f:
            for line in f:
                temp = re.findall('-*\d+', line)
                pitches.append(int(temp[1]))
                times.append(int(temp[0]))
                durations.append(int(temp[2]))
                voices.append(int(temp[3]))
        results = self.create_lines_from_file_contents(times, pitches, durations, voices)
        self.plot_lines(*results)


if __name__ == "__main__":
    visualizer = SongVisualizer()
    visualizer.do_everything(sys.argv[1])


