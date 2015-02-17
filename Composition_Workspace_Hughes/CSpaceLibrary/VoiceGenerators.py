"""
    Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics
    Labratory at Worcester Polytechnic Institute.

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
import random
from abc import ABCMeta, abstractmethod


class VoiceGenerator:
    """
    This class is an abstract base class (abc) for the different possible voice generators (i.e. sampling methods of the
    configuration space)
    """
    __meta_class__ = ABCMeta

    def __init__(self):
        pass

    @abstractmethod
    def get_new_pitch(self):
        pass

    @abstractmethod
    def get_new_duration(self):
        pass

    @abstractmethod
    def get_duration_score(self, duration):
        pass

    @abstractmethod
    def get_pitch_score(self, pitch):
        pass


class SimpleVoiceGenerator(VoiceGenerator):

    def __init__(self, pitch_mean, pitch_variance, duration_mean, duration_variance, min_pitch, max_pitch,
                 min_duration, max_duration):
        VoiceGenerator.__init__(self)
        self.pitch_mean = pitch_mean
        self.pitch_variance = pitch_variance
        self.duration_mean = duration_mean
        self.duration_variance = duration_variance
        self.min_pitch = min_pitch
        self.min_duration = min_duration
        self.max_pitch = max_pitch
        self.max_duration = max_duration

    def get_pitch_score(self, pitch):
        distance = abs(self.pitch_mean - pitch)
        std_variations = distance / self.pitch_variance
        return np.clip(1 - std_variations, 0, 1)

    def get_new_duration(self):
        return np.clip(int(random.normalvariate(self.duration_mean, self.duration_variance)), self.min_duration,
                       self.max_duration)

    def get_duration_score(self, duration):
        distance = abs(self.duration_mean - duration)
        std_variations = distance / self.duration_variance
        return np.clip(1 - std_variations, 0, 1)

    def get_new_pitch(self):
        return np.clip(int(random.normalvariate(self.pitch_mean, self.pitch_variance)), self.min_pitch,
                       self.max_pitch)


class MultiNoteVoiceGenerator(VoiceGenerator):
    """
    This class is an abstract base class (abc) for the different possible voice generators (i.e. sampling methods of the
    configuration space)
    """
    __meta_class__ = ABCMeta

    def __init__(self):
        VoiceGenerator.__init__(self)

    @abstractmethod
    def get_new_pitch(self):
        pass

    @abstractmethod
    def get_new_duration(self):
        pass

    @abstractmethod
    def get_duration_score(self, duration):
        pass

    @abstractmethod
    def get_pitch_score(self, pitch):
        pass

    @abstractmethod
    def update_num_notes(self):
        pass


class ComplexRhythmGenerator(MultiNoteVoiceGenerator):

    def __init__(self, duration_mean, duration_variance, number_mean, number_variance):
        VoiceGenerator.__init__(self)
        self.duration_mean = duration_mean
        self.duration_variance = duration_variance
        self.number_mean = number_mean
        self.number_variance = number_variance
        self.number_notes = int(random.normalvariate(number_mean, number_variance))

    def get_pitch_score(self, pitch):
        return 0.

    def get_duration_score(self, duration):
        return 0

    def get_new_duration(self):
        durations = []
        for i in range(int(random.normalvariate(self.number_mean, self.number_variance))):
            durations.append(random.normalvariate(self.duration_mean, self.duration_variance))
        return durations

    def get_new_pitch(self):
        pitches = []  # TODO put in starting pitch
        for i in range(self.number_notes):
            pass  # TODO add in transforms to starting pitch (i.e. intervals, not notes)
        return pitches

    def update_num_notes(self):
        self.number_notes = int(random.normalvariate(self.number_mean, self.number_variance))