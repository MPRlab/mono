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
from CSpaceLibrary.SimpleVoiceGenerator import SimpleVoiceGenerator
import random


"""
Main file to generate a composition
"""
voice1_generator = SimpleVoiceGenerator(40, 8, 4, 2, 0, 61, 1, 16)
voice2_generator = SimpleVoiceGenerator(25, 15, 8, 2, 0, 61, 1, 16)
generators = [voice1_generator, voice2_generator]
collision_checker = CollisionChecker(generators, [1, 1], 1)
roadmap_builder = CSpaceSampler(generators, collision_checker)
prm = roadmap_builder.build_prm(100, 100)
print prm.edges()
planner = PathPlanner(prm)
path = []
edge_ratio = 0.1
while len(prm.edges()) > edge_ratio*len(prm.nodes()):
    try:
        path = planner.generate_path(random.choice(prm.nodes()), random.choice(prm.nodes()))
        break
    except ValueError:
        pass

exporter = PathExporter()
exporter.export_path(path, "testing.org")
