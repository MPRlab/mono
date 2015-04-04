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
from .ConfigurationGenerator import ConfigurationGenerator
import numpy as np


class ComplexConfigurationGenerator(ConfigurationGenerator):

    def __init__(self, d_means, d_variances, keys, octaves, n_means, n_variances, r_probabilities,
                 pitch_rule_checker,
                 duration_rule_checker,
                 duration_tolerances=(50, 10000),
                 pitch_tolerances=(29, 89),
                 note_tolerances=(1, 200),
                 jump_probabilities = (0.20, 0.20),
                 crab_prob = 0.1,
                 theme_prob = -0.3):
        ConfigurationGenerator.__init__(self)
        import random as r
        r.seed()
        self.generator = r.random
        self.generator_n = r.normalvariate
        self.d_means = d_means
        self.d_variances = d_variances
        self.n_means = n_means
        self.n_variances = n_variances
        self.r_probabilities = r_probabilities
        self.voices = len(self.d_means)
        self.pitch_rule_checker = pitch_rule_checker
        self.duration_rule_checker = duration_rule_checker
        self.duration_tolerances = duration_tolerances
        self.note_tolerances = note_tolerances
        self.keys = keys
        self.octaves = octaves

        self.theme_generator = ThemeProducer(crab_prob, pitch_tolerances[0], pitch_tolerances[1])
        self.theme_prob = theme_prob
        self.pitch_generators = []
        for i in range(len(d_means)):
            self.pitch_generators.append(RealisticPitchProbabilities(pitch_tolerances[0],
                                                                     pitch_tolerances[1],
                                                                     keys[i],
                                                                     octaves[i],
                                                                     jump_probabilities[i]))

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
                new_duration = int(self.get_duration(voice))
                time_filled += new_duration
                if time_filled > time_to_fill:
                    new_duration -= time_filled - time_to_fill
                    time_filled = time_to_fill
                rest_prob = self.generator()
                if rest_prob < self.r_probabilities[voice]:
                    v_smoothed_pitches.append(-1)
                else:
                    v_smoothed_pitches.append(self.get_pitch(voice))
                v_smoothed_durations.append(new_duration)
            smoothed_durations[voice] = v_smoothed_durations
            smoothed_pitches[voice] = v_smoothed_pitches
        return Configuration(q.get_voices(), smoothed_pitches, smoothed_durations)

    def get_new_configuration(self):
        pitches = []
        durations = []
        for voice in range(self.voices):
            probability = self.generator()
            if probability < self.theme_prob:
                theme_results = self.theme_generator.get_theme(self.keys[voice], self.octaves[voice])
                v_pitches = theme_results[0]
                v_durations = theme_results[1]
            else:
                v_pitches = []
                v_durations = []
                num_notes = self.get_num_notes(voice)
                for _ in range(num_notes):
                    rest_prob = self.generator
                    v_durations.append(self.get_duration(voice))
                    if rest_prob < self.r_probabilities[voice]:
                        v_pitches.append(-1)
                    else:
                        v_pitches.append(self.get_pitch(voice))
            pitches.append(v_pitches)
            durations.append(v_durations)
        return self._perform_smoothing(Configuration(self.voices, pitches, durations))

    def get_pitch(self, voice):
        return self.pitch_generators[voice].get_pitch()

    def get_duration(self, voice):
        duration = int(np.clip(self.generator_n(self.d_means[voice], self.d_variances[voice]),
                               self.duration_tolerances[0],
                               self.duration_tolerances[1]))
        return self.clip_duration(duration)

    def clip_duration(self, duration):
        return duration / int(self.duration_tolerances[0]) * int(self.duration_tolerances[0])

    def get_num_notes(self, voice):
        return int(np.clip(int(self.generator_n(self.n_means[voice], self.n_variances[voice])),
                           self.note_tolerances[0],
                           self.note_tolerances[1]))

    def print_number_of_themes(self):
        print "Number of Themes Inserted: ", self.theme_generator.inserts


class RealisticPitchProbabilities:

    def __init__(self, min_pitch, max_pitch, key, octave, jump_probability):
        import random as r
        r.seed()
        self.generator = r.random
        self.min_pitch = min_pitch
        self.max_pitch = max_pitch
        self.key = key
        self.octave = octave
        self.major_interval_probabilities = [0.0862, 0.0863, 0.2415, 0.2416, 0.3795, 0.5173, 0.5174, 0.6898,
                                             0.6899, 0.7925, 0.7926, 0.8959, 1.0000]
        self.minor_interval_probabilities = [0.0862, 0.0863, 0.2415, 0.3794, 0.3795, 0.5173, 0.5174, 0.6898,
                                             0.7924, 0.7925, 0.8958, 0.8959, 1.000]
        self.starting_pitch = {'c': 60, 'c`': 61, 'd,': 61, 'd': 62, 'd`': 63, 'e,': 63, 'e': 64, 'f': 65, 'f`': 66,
                               'g,': 66, 'g': 67, 'g`': 68, 'a,': 68, 'a': 69, 'a`': 70, 'b,': 70, 'b': 71}
        self.jump_probability = jump_probability

    def adjust_pitch(self, pitch):
        probability = self.generator()
        if probability < self.jump_probability:
            pitch -= 12
        if probability > 1 - self.jump_probability:
            pitch += 12
        while pitch > self.max_pitch:
            pitch -= 12
        return pitch

    def get_pitch(self):
        probability = self.generator()
        minor_flag = self.key == self.key.lower()
        if minor_flag:
            for i in range(len(self.minor_interval_probabilities)):
                if probability < self.minor_interval_probabilities[i]:
                    return self.adjust_pitch(self.starting_pitch[self.key.lower()] + i + self.octave * 12)
        else:
            for i in range(len(self.major_interval_probabilities)):
                if probability < self.major_interval_probabilities[i]:
                    return self.adjust_pitch(self.starting_pitch[self.key.lower()] + i + self.octave * 12)


class ThemeProducer:

    def __init__(self, crab_prob, min_pitch, max_pitch):
        import random as r
        r.seed()
        self.generator = r.random
        self.crab_prob = crab_prob
        self.theme_pitches = [64, 71, 69, 67, 66, 76, 72, 71, 69, 67, 66, 64, 66, 69, 67, 66, 67, 66, 64]
        self.theme_durations = [500, 750, 250, 500, 500, 750, 250, 500, 750, 250, 250, 250, 500, 250, 250,
                                250, 750, 250, 500]
        self.key_mappings = {'c': -4, 'd': -2, 'e': 0, 'f': 1, 'g': 3, 'a': 5, 'b,': 7}
        self.max_pitch = max_pitch
        self.min_pitch = min_pitch
        self.inserts = 0

    def get_theme(self, key, octave):
        offset = self.key_mappings[key.lower()[0]] + octave * 12
        pitches_to_return = []
        for i in range(len(self.theme_pitches)):
            temp_pitch = self.theme_pitches[i] + offset
            while temp_pitch > self.max_pitch:
                temp_pitch -= 12
            while temp_pitch < self.min_pitch:
                temp_pitch += 12
            pitches_to_return.append(temp_pitch)
        probability = self.generator()
        if probability < self.crab_prob:
            return np.array(pitches_to_return)[::-1].tolist(), np.array(self.theme_durations)[::-1].tolist()
        self.inserts += 1
        return pitches_to_return, self.theme_durations

