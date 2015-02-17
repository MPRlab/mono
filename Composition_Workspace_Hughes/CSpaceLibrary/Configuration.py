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
        return self.pitches + self.durations

    def get_voices(self):
        return self.voices

    def __repr__(self):
        return "Voices: " + str(self.voices) + " Notes: " + str(self.pitches) + " Durations: " + str(self.durations)

    def __str__(self):
        return "Voices: " + str(self.voices) + " Notes: " + str(self.pitches) + " Durations: " + str(self.durations)

    def __eq__(self, other):
        if isinstance(other, Configuration):
            if self.voices == other.voices:
                if self.pitches == other.pitches:
                    if self.durations == other.durations:
                        return True
        return False

    def __hash__(self):
        return hash(self.__str__())