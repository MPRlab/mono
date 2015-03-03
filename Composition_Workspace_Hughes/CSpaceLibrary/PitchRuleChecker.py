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


class PitchRuleChecker:

    def __init__(self, skip_threshold, weights):
        self.threshold = skip_threshold
        self.weights = weights

    def check_pitch_set(self, pitch_set):
        total_skips = 0
        largest_skip = 0
        skip_history = []
        skip_directions = []
        prev = 0
        next_element = 1
        while next_element < len(pitch_set):
            if pitch_set[prev] == -1:
                prev += 1
                next_element += 1
            elif pitch_set[next_element] == -1:
                next_element += 1
            else:
                skip = abs(pitch_set[next_element]-pitch_set[prev]) - 1
                if skip < 0:
                    skip = 0
                total_skips += skip
                if skip > largest_skip:
                    largest_skip = skip
                skip_history.append(skip)
                if pitch_set[next_element] > pitch_set[prev]:
                    skip_directions.append(1)
                elif pitch_set[next_element] < pitch_set[prev]:
                    skip_directions.append(-1)
                else:
                    skip_directions.append(0)
                prev = next_element
                next_element += 1

        directional_violations = 0
        triad_violations = 0
        for i in range(0, len(skip_history) -1):
            if skip_history[i] > self.threshold and skip_directions[i+1] != -skip_directions[i]:
                directional_violations += 1
            if skip_directions[i] == skip_directions[i+1] and skip_directions[i] != 0:
                if skip_history[i] == 4:
                    if skip_history[i + 1] == 5:
                        pass
                    else:
                        triad_violations += 1
                elif skip_history[i] == 5:
                    if skip_history[i+1] == 4:
                        pass
                    else:
                        triad_violations += 1
        return (1 - total_skips*self.weights[0] - largest_skip*self.weights[1] -
                directional_violations * self.weights[2] - triad_violations * self.weights[3])
