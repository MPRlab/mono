__author__ = 'nathan'

from CSpaceSampler import VoiceGenerator
import numpy as np
import random


# TODO Finish Class
class PitchChecker:

    def __init__(self, generators):
        for generator in generators:
            if not isinstance(generator, VoiceGenerator):
                raise ValueError("Not a valid generator")
        self.generators = generators

    @staticmethod
    def check_inside_range(pitch, generator):
        return 0.

    @staticmethod
    def check_harmonics(pitches):
        return 0.

    def check_pitch(self, configuration):
        pitches = configuration.get_pitch()
        pitch_score = 0
        for i in range(0, len(pitches)):
            pitch_score += self.check_inside_range(pitches[i], self.generators[i])
        pitch_score /= float(len(pitches))
        pitch_score += self.check_harmonics(pitches)
        return np.clip(pitch_score, 0, 1)


# TODO Finish Class
class DurationChecker:

    def __init__(self, generators):
        for generator in generators:
            if not isinstance(generator, VoiceGenerator):
                raise ValueError("Not a valid generator")
        self.generators = generators

    @staticmethod
    def check_inside_range(duration, generator):
        return 0.

    @staticmethod
    def check_variance(durations):
        return 0.

    def check_duration(self, configuration):
        durations = configuration.get_duration()
        duration_score = 0
        for i in range(0, len(durations)):
            duration_score += self.check_inside_range(durations[i], self.generators[i])
        durations /= float(len(durations))
        durations += self.check_variance(durations)
        return np.clip(durations, 0, 1)


class CollisionChecker:
    """
    This class defines the configuration space of the composition by creating a probabilistic model for whether a
    configuration should be included or excluded from the sampled representation of the space. This probabilistic model
    depends on the following different parameters: the pitch difference between voices, the difference in duration
    between voices, whether a pitch fits within the key of the voice, and whether the duration fits within the assumed
    duration of the given voice.
    """
    def __init__(self, generators, weights):
        self.duration_checker = DurationChecker(generators)
        self.pitch_checker = PitchChecker(generators)
        self.weights = weights

    def is_valid(self, q):
        score = 0.
        score += self.weights[0] * self.pitch_checker.check_pitch(q)
        score += self.weights[1] * self.duration_checker.check_duration(q)
        guess = random.random()
        if score < guess:
            return False
        else:
            return True