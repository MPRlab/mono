"""
	Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
	Labrotory at Worcester Polytechnic Institute.

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
                line = "T: %d" % time
                max_duration = 0
                for i in range(configuration.get_voices()):
                    line += "|%d %d " % configuration.get_pitch(i), configuration.get_duration(i)
                    if configuration.get_duration(i) > max_duration:
                        max_duration = configuration.get_duration(i)
                    f.write(line)
                time += max_duration
