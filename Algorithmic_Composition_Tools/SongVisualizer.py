__author__ = 'nathan'

import matplotlib.pyplot as plt
import sys

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
        plt.barh([pos]*len(line), durations, left=times, color=colors, edgecolor="none", height=0.5)
        # plt.gca().set_ylim([0, 1.5])
        # plt.show()

    @staticmethod
    def create_lines_from_file_contents(times, pitches, durations):
        pitch_lines = [[pitches[0]]]
        time_lines = [[times[0]]]
        duration_lines = [[durations[0]]]
        line_count = 0
        for i in range(1, len(times)):
            if times[i] == times[i-1]:
                line_count += 1
                if len(duration_lines) <= line_count:
                    duration_lines.append([])
                if len(time_lines) <= line_count:
                    time_lines.append([])
                if len(pitch_lines) <= line_count:
                    pitch_lines.append([])
            else:
                line_count = 0
            pitch_lines[line_count].append(pitches[i])
            duration_lines[line_count].append(durations[i])
            time_lines[line_count].append(times[i])
        return pitch_lines, time_lines, duration_lines

    def plot_lines(self, pitches, times, durations):
        # print pitches
        # print times
        # print durations
        for i in range(len(pitches)):
            self.output_line(pitches[i], times[i], durations[i], i)
        plt.gca().set_ylim(-1, len(pitches))
        plt.show()

    def do_everything(self, file_path):
        import re
        pitches = []
        times = []
        durations = []
        with open(file_path, "r") as f:
            for line in f:
                temp = re.findall('-*\d+', line)
                pitches.append(int(temp[1]))
                times.append(int(temp[0]))
                durations.append(int(temp[2]))

        results = self.create_lines_from_file_contents(times, pitches, durations)
        self.plot_lines(*results)


if __name__ == "__main__":
    visualizer = SongVisualizer()
    visualizer.do_everything(sys.argv[1])


# visualizer.output_line([60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, -1],
#                        [0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000],
#                        [500]*13)
# test_times = [0, 0, 0, 2, 3, 4, 4, 5]
# test_pitches = [1, 2, 3, 1, 1, 1, 5, 2]
# test_durations = [1, 3, 7, 1, 1, 1, 5, 1]
#
# results = visualizer.create_lines_from_file_contents(test_times, test_pitches, test_durations)
# visualizer.plot_lines(results[0], results[1], results[2])
