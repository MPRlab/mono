__author__ = 'nathan'

from .Configuration import Configuration
import numpy as np
import random


# TODO Figure out mapping between harmonics and score, and harmonic rules
class PitchChecker:

    def __init__(self, generators):
        self.generators = generators

    @staticmethod
    def check_inside_range(pitch, generator):
        return generator.get_pitch_score(pitch)

    @staticmethod
    def check_harmonics(pitches):
        return 0.

    def check_pitch(self, configuration):
        pitches = configuration.pitches
        pitch_score = 0
        for i in range(0, len(pitches)):
            pitch_score += self.check_inside_range(pitches[i], self.generators[i])
        pitch_score /= float(len(pitches))
        pitch_score += self.check_harmonics(pitches)
        return np.clip(pitch_score, 0, 1)


# TODO Figure out the mapping from variance to score
class DurationChecker:

    def __init__(self, generators):
        self.generators = generators

    @staticmethod
    def check_inside_range(duration, generator):
        return generator.get_duration_score(duration)

    def check_variance(self, durations):
        variance = np.var(durations)
        return self.variance_mapping(variance)

    @staticmethod
    def variance_mapping(variance):
        return variance

    def check_duration(self, configuration):
        durations = configuration.durations
        duration_score = 0
        for i in range(0, len(durations)):
            duration_score += self.check_inside_range(durations[i], self.generators[i])
        duration_score /= float(len(durations))
        duration_score += self.check_variance(durations)
        return np.clip(duration_score, 0, 1)


class CollisionChecker:
    """
    This class defines the configuration space of the composition by creating a probabilistic model for whether a
    configuration should be included or excluded from the sampled representation of the space. This probabilistic model
    depends on the following different parameters: the pitch difference between voices, the difference in duration
    between voices, whether a pitch fits within the key of the voice, and whether the duration fits within the assumed
    duration of the given voice.
    """
    def __init__(self, generators, weights, tolerance):
        self.duration_checker = DurationChecker(generators)
        self.pitch_checker = PitchChecker(generators)
        self.weights = weights
        self.tolerance = tolerance

    def is_valid(self, q):
        score = 0.
        score += self.weights[0] * self.pitch_checker.check_pitch(q)
        score += self.weights[1] * self.duration_checker.check_duration(q)
        score = np.clip(score, 0, 1)
        guess = random.random()
        if score < guess:
            return False
        else:
            return True

    @staticmethod
    def distance(q1, q2):
        coordinates1 = q1.get_all_coordinates()
        coordinates2 = q2.get_all_coordinates()
        distance_sum = 0.
        for i in range(0, len(coordinates1)):
            distance_sum += (coordinates1 + coordinates2)**2
        return distance_sum**0.5

    def path(self, q1, q2):
        distance = self.distance(q1, q2)
        steps = int(distance / self.tolerance)
        start = np.array(q1.get_all_coordinates())
        end = np.array(q2.get_all_coordinates())
        vector = end - start
        unit_vector = vector / distance
        distance_to_check = self.tolerance
        for i in range(steps):
            coordinates_to_check = start + unit_vector * distance_to_check
            configuration_to_check = Configuration(q1.get_voices(),
                                                   coordinates_to_check[:q1.get_voices()],
                                                   coordinates_to_check[q1.get_voices():])
            if not self.is_valid(configuration_to_check):
                return False
            distance_to_check += self.tolerance
        return True

