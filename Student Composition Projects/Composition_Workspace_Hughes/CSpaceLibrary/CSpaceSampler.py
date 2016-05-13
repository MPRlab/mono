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

import networkx as nx
from .VoiceGenerator import VoiceGenerator
from .ConfigurationGenerator import ConfigurationGenerator
from .Configuration import Configuration


class CSpaceSampler:
    """
    This class uses a collision checker to build up a graph that represents the configuration space
    """
    def __init__(self, voice_generators, configuration_generator, collision_checker):
        if voice_generators:
            self.generators = voice_generators
            for generator in voice_generators:
                if not isinstance(generator, VoiceGenerator):
                    raise ValueError("Not a valid voice generator")
            self.voice_flag = True
        else:
            if isinstance(configuration_generator, ConfigurationGenerator):
                self.generator = configuration_generator
            else:
                raise ValueError("Not a valid configuration generator")
            self.voice_flag = False
        self.collision_checker = collision_checker

    @classmethod
    def from_voice_generators(cls, voice_generators, collision_checker):
        return cls(voice_generators, None, collision_checker)

    @classmethod
    def from_configuration_generator(cls, configuration_generator, collision_checker):
        return cls(None, configuration_generator, collision_checker)

    def _make_new_configuration(self):
        if self.voice_flag:
            pitches = []
            durations = []
            for generator in self.generators:
                pitches.append(generator.get_new_pitch())
                durations.append(generator.get_new_duration())
            return Configuration(len(self.generators), pitches, durations)
        else:
            return self.generator.get_new_configuration()

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
