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


class Configuration:
    """
    This class is intended to be a collection of the different parameters that make up a configuration, and gives easy
    access to parameters based on voices
    """
    def __init__(self, voices, pitches, durations):
        self.voices = voices
        self.pitches = pitches
        self.durations = durations
        if len(pitches) != voices:
            raise ValueError("There should be an assigned pitch for each voice")
        if len(durations) != voices:
            raise ValueError("There should be an assigned duration for each voice")

    def get_pitch(self, voice):
        return self.pitches[voice]

    def get_duration(self, voice):
        return self.durations[voice]

    def get_all_coordinates(self):
        print self.durations
        print self.voices
        return self.durations + self.voices

    def get_voices(self):
        return self.voices
