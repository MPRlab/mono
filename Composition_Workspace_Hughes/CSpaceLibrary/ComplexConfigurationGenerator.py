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
import numpy as np


class ComplexConfigurationGenerator(ConfigurationGenerator):

    def __init__(self, d_means, d_variances, p_means, p_variances, n_means, n_variances, r_probabilities,
                 pitch_rule_checker, duration_rule_checker, duration_tolerances, pitch_tolerances, note_tolerances):
        ConfigurationGenerator.__init__(self)
        self.d_means = d_means
        self.d_variances = d_variances
        self.p_means = p_means
        self.p_variances = p_variances
        self.n_means = n_means
        self.n_variances = n_variances
        self.r_probabilities = r_probabilities
        self.voices = len(self.d_means)
        self.pitch_rule_checker = pitch_rule_checker
        self.duration_rule_checker = duration_rule_checker
        self.duration_tolerances = duration_tolerances
        self.pitch_tolerances = pitch_tolerances
        self.note_tolerances = note_tolerances

    def get_pitch_score(self, configuration):
        pitches = configuration.get_all_coordinates()[configuration.get_voices():]
        score = 0
        voice_score = 0
        for pitch_set in pitches:
            voice_score = self.pitch_rule_checker.check_pitch_set(pitch_set)
        score += voice_score
        return score / len(pitches)

    def get_duration_score(self, configuration):
        durations = configuration.get_all_coordinates()[:configuration.get_voices()]
        score = 0
        voice_score = 0
        for duration_set in durations:
            voice_score = self.duration_rule_checker.check_duration_set(duration_set)
        score += voice_score
        return score / len(durations)

    def _perform_smoothing(self, q):
        durations = q.get_all_coordinates()[q.get_voices():]
        pitches = q.get_all_coordinates()[:q.get_voices()]
        duration_totals = []
        duration_count = 0
        for duration_set in durations:
            total_duration = sum(duration_set)
            duration_totals.append((total_duration, duration_count))
            duration_count += 1
        sorted_durations = sorted(duration_totals, key=lambda x: -x[0])
        smoothed_durations = [0]*len(durations)
        smoothed_pitches = [0]*len(pitches)
        smoothed_durations[sorted_durations[0][1]] = durations[sorted_durations[0][1]]
        smoothed_pitches[sorted_durations[0][1]] = pitches[sorted_durations[0][1]]
        for i in range(1, len(sorted_durations)):
            voice = sorted_durations[i][1]
            v_smoothed_pitches = pitches[voice]
            v_smoothed_durations = durations[voice]
            time_to_fill = sorted_durations[0][0] - sorted_durations[i][0]
            time_filled = 0
            while time_filled < time_to_fill:
                new_duration = int(np.clip(random.normalvariate(self.d_means[voice], self.d_variances[voice]),
                                           self.duration_tolerances[0],
                                           self.duration_tolerances[1]))
                time_filled += new_duration
                if time_filled > time_to_fill:
                    new_duration -= time_filled - time_to_fill
                    time_filled = time_to_fill
                rest_prob = random.random()
                if rest_prob < self.r_probabilities[voice]:
                    v_smoothed_pitches.append(-1)
                else:
                    v_smoothed_pitches.append(int(np.clip(random.normalvariate(self.p_means[voice],
                                                                               self.p_variances[voice]),
                                                          self.pitch_tolerances[0],
                                                          self.pitch_tolerances[1])))
                v_smoothed_durations.append(new_duration)
            smoothed_durations[voice] = v_smoothed_durations
            smoothed_pitches[voice] = v_smoothed_pitches
        return Configuration(q.get_voices(), smoothed_pitches, smoothed_durations)

    def get_new_configuration(self):
        pitches = []
        durations = []
        for voice in range(self.voices):
            v_pitches = []
            v_durations = []
            num_notes = int(np.clip(int(random.normalvariate(self.n_means[voice], self.n_variances[voice])),
                                    self.note_tolerances[0],
                                    self.note_tolerances[1]))
            for _ in range(num_notes):
                rest_prob = random.random()
                v_durations.append(int(np.clip(random.normalvariate(self.d_means[voice], self.d_variances[voice]),
                                               self.duration_tolerances[0],
                                               self.duration_tolerances[1])))
                if rest_prob < self.r_probabilities[voice]:
                    v_pitches.append(-1)
                else:
                    v_pitches.append(int(np.clip(random.normalvariate(self.p_means[voice], self.p_variances[voice]),
                                                 self.pitch_tolerances[0],
                                                 self.pitch_tolerances[1])))
            pitches.append(v_pitches)
            durations.append(v_durations)
        return self._perform_smoothing(Configuration(self.voices, pitches, durations))