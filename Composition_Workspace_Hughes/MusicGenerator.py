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
import random


"""
Main file to generate a composition
"""
d_means = [10, 3]
d_variances = [2, 5]
p_means = [50, 30]
p_variances = [1, 1]
n_means = [2, 5]
n_variances = [1, 1]
r_probabilities = [0.2, 0.1]

generator = ComplexConfigurationGenerator(d_means, d_variances, p_means, p_variances, n_means, n_variances,
                                          r_probabilities)
pitch_checker = PitchChecker.from_configuration_generator(generator)
duration_checker = DurationChecker.from_configuration_generator(generator)
collision_checker = CollisionChecker(pitch_checker, duration_checker, [1, 1], 1)
roadmap_builder = CSpaceSampler.from_configuration_generator(generator, collision_checker)
prm = roadmap_builder.build_prm(5, 10)
print prm.nodes()
# planner = PathPlanner(prm)
# path = []
# edge_ratio = 0.1
# while len(prm.edges()) > edge_ratio*len(prm.nodes()):
#     try:
#         path = planner.generate_path(random.choice(prm.nodes()), random.choice(prm.nodes()))
#         break
#     except ValueError:
#         pass
#
# exporter = PathExporter()
# exporter.export_path(path, "testing.org")
