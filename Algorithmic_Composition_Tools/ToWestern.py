__author__ = 'nathan'

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


class WesternConverter:

    def __init__(self, note_base, voices):
        self.prefix = """\\version "2.18.2"\n{\n\t\\new PianoStaff <<\n"""
        self.postfix = """\t>>\n}\n"""
        self.voices = voices
        self.note_base = note_base

    @staticmethod
    def map_duration(duration, time):
        duration_mapping = ["", "16", "8", "8.", "4", ("4~", "16"), "4.", ("4~", "8."), "2",
                            ("2~", "16"), ("2~", "8"), ("2~", "8."), "2.", ("2.~", "16"),
                            ("2.~", "8"), ("2.~", "8."), "1"]
        durations = []
        durations_r = []
        notes = duration_mapping[duration]
        if not isinstance(notes, basestring):
            durations.append(notes[0])
            durations.append(notes[1])
        else:
            durations.append(notes)
        rests = duration_mapping[time - duration]
        if rests == "":
            pass
        else:
            if not isinstance(rests, basestring):
                durations_r.append("r" + rests[0])
                durations_r.append("r" + rests[1])
            else:
                durations_r.append("r" + str(rests))
        return durations, durations_r

    def map_pitch(self, pitch):
        pitch_mapping = ["c", "cis", "d", "dis", "e", "f", "fis", "g", "gis", "a", "ais", "b"]
        octaves = int(abs(pitch - self.note_base) / 12)
        note = (pitch - self.note_base) % 12
        if pitch - self.note_base >= 0:
            return pitch_mapping[note] + "'"*(octaves + 1)
        else:
            return pitch_mapping[note] + ","*(octaves - 1)

    @staticmethod
    def make_export(pitch, duration):
        string_value = "\t\t"
        for value in duration[0]:
            string_value += pitch + value + " "
        for value in duration[1]:
            string_value += value + " "
        return string_value + "\n"

    def export_voice(self, voice, f_out):
        voice_string = """\t\\new Staff {\n\t\t\\clef "treble"\n\t\t\\time 4/4\n"""
        for i in range(0, len(voice)):
            if i != len(voice) - 1:
                time = voice[i + 1][2] - voice[i][2]
                duration = self.map_duration(voice[i][1], time)
                pitch = self.map_pitch(voice[i][0])
                to_export = self.make_export(pitch, duration)
                voice_string += to_export
            else:
                duration = self.map_duration(voice[i][1], voice[i][1])
                pitch = self.map_pitch(voice[i][0])
                to_export = self.make_export(pitch, duration)
                voice_string += to_export
        voice_string += "\t}\n"
        f_out.write(voice_string)

    def convert(self, in_filename, out_filename):
        with open(in_filename, 'r') as f_in:
            with open(out_filename, 'w') as f_out:
                f_out.write(self.prefix)
                voices = {}
                for i in range(self.voices):
                    voices[i] = []
                for line in f_in:
                    time = int(line.split(" ")[1])
                    voice_values = line.split("|")[1:]
                    for i in range(self.voices):
                        to_analyze = voice_values[i][:-1].split(" ")
                        voices[i].append((int(to_analyze[0]), int(to_analyze[1]), time))
                for i in range(self.voices):
                    self.export_voice(voices[i], f_out)
                f_out.write(self.postfix)
