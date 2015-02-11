__author__ = 'nathan'

import networkx as nx
from abc import ABCMeta, abstractmethod
from .Configuration import Configuration


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


class CSpaceSampler:
    """
    This class uses a collision checker to build up a graph that represents the configuration space
    """
    def __init__(self, generators, collision_checker):
        self.generators = generators
        for generator in generators:
            if not isinstance(generator, VoiceGenerator):
                raise ValueError("Not a valid voice generator")
        self.collision_checker = collision_checker

    def _make_new_configuration(self):
        pitches = []
        durations = []
        for generator in self.generators:
            pitches.append(generator.get_new_pitch())
            durations.append(generator.get_new_duration())
        return Configuration(len(self.generators), pitches, durations)

    def build_prm(self, radius, samples):
        prm = nx.Graph()  # TODO look into directed graph
        for _ in range(samples):
            sample_configuration = self._make_new_configuration()
            while not self.collision_checker.is_valid(sample_configuration):
                sample_configuration = self._make_new_configuration()
            prm.add_node(sample_configuration)
            for node in prm.nodes():
                if node != sample_configuration:
                    if (self.collision_checker.distance(node, sample_configuration) < radius and
                            self.collision_checker.path(sample_configuration, node)):
                        prm.add_edge(sample_configuration, node)
        return prm