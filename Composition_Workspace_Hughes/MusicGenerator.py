#! /usr/bin/env python
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

from CSpaceLibrary.CollisionChecker import CollisionChecker
from CSpaceLibrary.CSpaceSampler import CSpaceSampler
from CSpaceLibrary.PathPlanner import PathPlanner
from CSpaceLibrary.PathExporter import PathExporter
from CSpaceLibrary.DurationChecker import DurationChecker
from CSpaceLibrary.PitchChecker import PitchChecker
from CSpaceLibrary.ComplexConfigurationGenerator import ComplexConfigurationGenerator
from CSpaceLibrary.PitchRuleChecker import PitchRuleChecker
from CSpaceLibrary.DurationRuleChecker import DurationRuleChecker
import random
import networkx as nx
import sys


def main(outfile1, outfile2):
    """
    Main file to generate a composition
    """
    d_means = [1000, 300]
    d_variances = [200, 500]
    keys = ['e', 'g']
    octaves = [0, -2]
    n_means = [2, 5]
    n_variances = [1, 1]
    r_probabilities = [0.2, 0.1]
    pitch_rule_checker = PitchRuleChecker(5, [0.05, 0.05, 0.05, 0.05])
    duration_rule_checker = DurationRuleChecker(3, [0.05])
    generator = ComplexConfigurationGenerator(d_means, d_variances, keys, octaves, n_means, n_variances,
                                              r_probabilities, pitch_rule_checker, duration_rule_checker)
    pitch_checker = PitchChecker.from_configuration_generator(generator)
    duration_checker = DurationChecker.from_configuration_generator(generator)
    collision_checker = CollisionChecker(pitch_checker, duration_checker, [1, 1], 1)
    roadmap_builder = CSpaceSampler.from_configuration_generator(generator, collision_checker)
    prm = roadmap_builder.build_prm(5, 100)
    generator.print_number_of_themes()
    largest_connected_component = sorted(nx.connected_components(prm), key=len, reverse=True)[0]
    connected_prm = prm.subgraph(largest_connected_component)
    planner = PathPlanner(connected_prm)
    path = planner.generate_path(random.choice(connected_prm.nodes()), random.choice(connected_prm.nodes()))
    exporter = PathExporter()
    exporter.export_path_multiple_notes(path, outfile1)
    exporter.export_path_multiple_notes_with_voices(path, outfile2)

if __name__ == "__main__":
    if len(sys.argv) == 3:
        main(sys.argv[1], sys.argv[2])
    else:
        print "Wrong Command Line Arguments!"
