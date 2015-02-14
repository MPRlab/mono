"""
    Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
	Labrotory at Worcester Polytechnic Institute.

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

import random


class PathPlanner:
    """
    This class uses a weighted brownian motion to generate interesting paths between the start and stop of a phrase
    """
    def __init__(self, prm):
        self.prm = prm

    def generate_path(self, start, end):
        path = []
        neighbors = self.prm.neighbors(start)
        vector = self._get_weighted_vector(neighbors)
        to_explore_index = self._choose_neighbor(vector)
        if to_explore_index == -1:
            raise ValueError("Isolated Node!")
        to_explore = neighbors[to_explore_index]
        path.append(to_explore)
        while to_explore != end:
            neighbors = self.prm.neighbors(to_explore)
            vector = self._get_weighted_vector(neighbors)
            to_explore_index = self._choose_neighbor(vector)
            if to_explore == -1:
                raise ValueError("Isolated Node!")
            to_explore = neighbors[to_explore_index]
            path.append(to_explore)
        return path

    @staticmethod
    def _choose_neighbor(vector):
        guess = random.random()
        count = 0
        for value in vector:
            if guess < value:
                return count
            count += 1
        return -1  # something would go really wrong if it got here

    @staticmethod
    def _get_weighted_vector(neighbors):
        vector = []
        step = 0
        for i in range(0, len(neighbors)):
            step += 1./len(neighbors)
            vector.append(step)
        return vector
