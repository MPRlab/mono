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

import numpy as np


class PitchChecker:

    def __init__(self, generators, generator):
        if generators:
            self.generators = generators
            self.voice_flag = True
        else:
            self.voice_flag = False
            self.generator = generator
        self.verbose = False

    @classmethod
    def from_voice_generators(cls, generators):
        return cls(generators, None)

    @classmethod
    def from_configuration_generator(cls, generator):
        return cls(None, generator)

    @staticmethod
    def check_inside_range(pitch, generator):
        return generator.get_pitch_score(pitch)

    @staticmethod
    def check_harmonics(pitches):
        return 0.

    def check_pitch(self, configuration):
        if self.voice_flag:
            pitches = configuration.pitches
            pitch_score = 0
            for i in range(0, len(pitches)):
                pitch_score += self.check_inside_range(pitches[i], self.generators[i])
            pitch_score /= float(len(pitches))
            pitch_score += self.check_harmonics(pitches)
        else:
            pitch_score = self.generator.get_pitch_score(configuration)
        if self.verbose:
            print "\tPitch Score:", pitch_score
        return np.clip(pitch_score, 0, 1)

    def enable_verbose(self):
        self.verbose = True

    def disable_verbose(self):
        self.verbose = False
