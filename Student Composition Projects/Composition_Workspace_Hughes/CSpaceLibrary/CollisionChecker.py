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

from .Configuration import Configuration
import numpy as np
import random


class CollisionChecker:
    """
    This class defines the configuration space of the composition by creating a probabilistic model for whether a
    configuration should be included or excluded from the sampled representation of the space. This probabilistic model
    depends on the following different parameters: the pitch difference between voices, the difference in duration
    between voices, whether a pitch fits within the key of the voice, and whether the duration fits within the assumed
    duration of the given voice.
    """
    def __init__(self, pitch_checker, duration_checker, weights, tolerance):
        self.pitch_checker = pitch_checker
        self.duration_checker = duration_checker
        self.weights = weights
        self.tolerance = tolerance
        self.verbose = False

    def is_valid(self, q):
        score = 0.
        score += self.weights[0] * self.pitch_checker.check_pitch(q)
        score += self.weights[1] * self.duration_checker.check_duration(q)
        score = np.clip(score, 0, 1)
        guess = random.random()
        if self.verbose:
            print "\t" + "-"*40
            print "\tTotal Score:", score, " Probability:", guess
        if guess > score:
            return False
        else:
            return True

    @staticmethod
    def distance(q1, q2):
        # coordinates1 = q1.get_all_coordinates()
        # coordinates2 = q2.get_all_coordinates()
        # distance_sum = 0.
        # for i in range(0, len(coordinates1)):
        #     distance_sum += (coordinates1[i] + coordinates2[i])**2
        # return distance_sum**0.5
        return 0

    def path(self, q1, q2):
        guess = random.random()
        if guess < 0.7:
            return False
        # distance = self.distance(q1, q2)
        # steps = int(distance / self.tolerance)
        # start = np.array(q1.get_all_coordinates())
        # end = np.array(q2.get_all_coordinates())
        # vector = end - start
        # unit_vector = vector / distance
        # distance_to_check = self.tolerance
        # if self.verbose:
        #     print "*"*80
        #     print "Starting Collision Checking: "
        #     print "\tStart:", q1
        #     print "\tEnd:", q2
        #     print ""
        #     print "Number of steps to check: ", steps
        #     print ""
        #
        # for i in range(steps):
        #     coordinates_to_check = start + unit_vector * distance_to_check
        #     configuration_to_check = Configuration(q1.get_voices(),
        #                                            coordinates_to_check[:q1.get_voices()],
        #                                            coordinates_to_check[q1.get_voices():])
        #     if self.verbose:
        #         print "Step", str(i) + ")", configuration_to_check
        #     if not self.is_valid(configuration_to_check):
        #         if self.verbose:
        #             print ""
        #             print "Ending Collision Checking"
        #             print "Status: Failed"
        #             print "*"*80
        #         return False
        #     distance_to_check += self.tolerance
        # if self.verbose:
        #     print ""
        #     print "Ending Collision Checking"
        #     print "Status: Succeeded"
        #     print "*"*80
        return True

    def enable_verbose(self):
        self.verbose = True

    def disable_verbose(self):
        self.verbose = False