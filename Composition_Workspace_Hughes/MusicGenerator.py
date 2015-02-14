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

from CSpaceLibrary.CollisionChecker import CollisionChecker
from CSpaceLibrary.CSpaceSampler import VoiceGenerator, CSpaceSampler
from CSpaceLibrary.PathPlanner import PathPlanner
from CSpaceLibrary.PathExporter import PathExporter
import random
import numpy as np


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


"""
Main file to generate a composition
"""
voice1_generator = SimpleVoiceGenerator(40, 8, 4, 2, 0, 61, 1, 16)
voice2_generator = SimpleVoiceGenerator(25, 15, 8, 2, 0, 61, 1, 16)
generators = [voice1_generator, voice2_generator]
collision_checker = CollisionChecker(generators, [1, 1], 1)
roadmap_builder = CSpaceSampler(generators, collision_checker)
prm = roadmap_builder.build_prm(1000, 2)

planner = PathPlanner(prm)
path = planner.generate_path(random.choice(prm.nodes()), random.choice(prm.nodes()))
exporter = PathExporter()
exporter.export_path(path, "testing.org")
