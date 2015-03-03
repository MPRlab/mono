"""
    Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
    Laboratory at Worcester Polytechnic Institute.

    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.
"""


__author__ = 'nathan'


class PathExporter:

    def __init__(self):
        pass

    @staticmethod
    def export_path(path, filename):
        with open(filename, 'w') as f:
            time = 0
            for configuration in path:
                line = "T: %d " % time
                max_duration = 0
                for i in range(configuration.get_voices()):
                    line += "|%d %d " % (configuration.get_pitch(i), configuration.get_duration(i))
                    if configuration.get_duration(i) > max_duration:
                        max_duration = configuration.get_duration(i)
                line += "\n"
                f.write(line)
                time += max_duration

    @staticmethod
    def export_path_multiple_notes(path, filename):
        with open(filename, 'w') as f:
            time = 0
            for configuration in path:
                durations = configuration.get_all_coordinates()[configuration.get_voices():]
                pitches = configuration.get_all_coordinates()[:configuration.get_voices()]
                print configuration
                curr_time_0 = 0
                curr_index_0 = 0
                curr_index_1 = 0
                curr_time_1 = 0
                while curr_index_0 < len(durations[0]) and curr_index_1 < len(durations[1]):
                    if curr_time_1 == curr_time_0:
                        pitch_0 = pitches[0][curr_index_0]
                        pitch_1 = pitches[1][curr_index_1]
                        duration_0 = durations[0][curr_index_0]
                        duration_1 = durations[1][curr_index_1]

                        line = "%d %d %d\n" % (time, pitch_0, duration_0)
                        f.write(line)

                        line = "%d %d %d\n" % (time, pitch_1, duration_1)
                        f.write(line)

                        curr_time_0 += duration_0
                        curr_time_1 += duration_1
                        curr_index_0 += 1
                        curr_index_1 += 1
                        if duration_0 < duration_1:
                            time += duration_0
                        else:
                            time += duration_1
                    elif curr_time_1 > curr_time_0:
                        pitch_1 = pitches[1][curr_index_1]
                        duration_1 = durations[1][curr_index_1]

                        line = "%d %d %d\n" % (time, pitch_1, duration_1)
                        f.write(line)

                        curr_time_1 += duration_1
                        curr_time_1 += 1
                        curr_index_1 += 1
                        time += duration_1
                    else:
                        pitch_0 = pitches[0][curr_index_0]
                        duration_0 = durations[0][curr_index_0]

                        line = "%d %d %d\n" % (time, pitch_0, duration_0)
                        f.write(line)

                        curr_index_0 += 1
                        curr_time_0 += duration_0
                        curr_time_0 += 1
                        time += duration_0

