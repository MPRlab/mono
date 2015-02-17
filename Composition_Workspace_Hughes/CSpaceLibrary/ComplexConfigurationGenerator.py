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


import random
from .Configuration import Configuration
from .ConfigurationGenerator import ConfigurationGenerator


class ComplexConfigurationGenerator(ConfigurationGenerator):

    def __init__(self, d_means, d_variances, p_means, p_variances, n_means, n_variances, r_probabilities):
        ConfigurationGenerator.__init__(self)
        self.d_means = d_means
        self.d_variances = d_variances
        self.p_means = p_means
        self.p_variances = p_variances
        self.n_means = n_means
        self.n_variances = n_variances
        self.r_probabilities = r_probabilities
        self.voices = len(self.d_means)

    def get_pitch_score(self, configuration):
        return 0.

    def get_duration_score(self, configuration):
        return 0

    def _perform_smoothing(self, q):
        durations = q.get_all_coordinates()[q.get_voices():]
        pitches = q.get_all_coordinates()[q.get_voices():]
        duration_totals = []
        duration_count = 0
        for duration_set in durations:
            total_duration = sum(duration_set)
            duration_totals.append((duration_count, total_duration))
        sorted_durations = sorted(duration_totals, key=lambda x: x[0])
        smoothed_durations = [0]*len(durations)
        smoothed_pitches = [0]*len(pitches)
        smoothed_durations[sorted_durations[0][1]] = durations[sorted_durations[0][0]]
        smoothed_pitches[sorted_durations[0][1]] = pitches[sorted_durations[0][0]]
        for i in range(1, len(sorted_durations)):
            voice = sorted_durations[i][1]
            v_smoothed_pitches = pitches[voice]
            v_smoothed_durations = durations[voice]
            time_to_fill = sorted_durations[i][0] - sorted_durations[0][0]
            time_filled = 0
            while time_filled < time_to_fill:
                new_duration = random.normalvariate(self.d_means[voice], self.d_variances[voice])
                time_filled += new_duration
                if time_filled > time_to_fill:
                    new_duration -= time_filled - time_to_fill
                    time_filled = time_to_fill
                rest_prob = random.random()
                if rest_prob > self.r_probabilities[voice]:
                    v_smoothed_pitches.append(-1)
                else:
                    v_smoothed_pitches.append(random.normalvariate(self.p_means[voice], self.p_variances[voice]))
                v_smoothed_durations.append(new_duration)
        return Configuration(q.get_voices(), smoothed_pitches, smoothed_durations)

    def get_new_configuration(self):
        pitches = []
        durations = []
        for voice in range(self.voices):
            v_pitches = []
            v_durations = []
            num_notes = random.normalvariate(self.n_means[voice], self.n_variances[voice])
            for _ in range(num_notes):
                rest_prob = random.random()
                if rest_prob > self.r_probabilities[voice]:
                    v_durations.append(random.normalvariate(self.d_means[voice], self.d_variances[voice]))
                    v_pitches.append(-1)
                else:
                    v_durations.append(random.normalvariate(self.d_means[voice], self.d_variances[voice]))
                    v_pitches.append(random.normalvariate(self.d_means[voice], self.d_variances[voice]))
            pitches.append(v_pitches)
            durations.append(v_durations)
        return self._perform_smoothing(Configuration(self.voices, pitches, durations))