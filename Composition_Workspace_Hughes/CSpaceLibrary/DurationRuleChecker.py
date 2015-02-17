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


class DurationRuleChecker:

    def __init__(self, repeat_threshold, weights):
        self.threshold = repeat_threshold
        self.weights = weights

    def check_duration_set(self, duration_set):
        repeats = 0
        count = 0
        for i in range(0, len(duration_set)-1):
            if duration_set[i] == duration_set[i+1]:
                count += 1
            else:
                count = 0
            if count >= self.threshold:
                repeats += 1
        return 1 - repeats * self.weights[0]