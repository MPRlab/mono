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
        return np.clip(int(random.normalvariate(self.duration_mean, self.duration_variance)), self.min_pitch,
                       self.max_pitch)

    def get_duration_score(self, duration):
        distance = abs(self.duration_mean - duration)
        std_variations = distance / self.duration_variance
        return np.clip(1 - std_variations, 0, 1)

    def get_new_pitch(self):
        return np.clip(int(random.normalvariate(self.pitch_mean, self.pitch_variance)), self.min_duration,
                       self.max_duration)


"""
Main file to generate a composition
"""
voice1_generator = SimpleVoiceGenerator(40, 8, 4, 2, 0, 61, 1, 16)
voice2_generator = SimpleVoiceGenerator(25, 15, 8, 2, 0, 61, 1, 16)
generators = [voice1_generator, voice2_generator]
collision_checker = CollisionChecker(generators, [0.5, 0.5], 0.5)
roadmap_builder = CSpaceSampler(generators, collision_checker)
prm = roadmap_builder.build_prm(10, 100)
planner = PathPlanner(prm)
print prm.nodes()
path = planner.generate_path(random.choice(prm.nodes()), random.choice(prm.nodes()))
exporter = PathExporter()
exporter.export_path(path, "testing.org")
