__author__ = 'nathan'


class WesternConverter:

    def __init__(self, note_base, voices):
        self.prefix = """
        \\version "2.18.2"
        {
            \\new PianoStaff <<
        """
        self.postfix = """
            >>
        }
        """
        self.voices = voices
        self.note_base = note_base

    @staticmethod
    def map_duration(duration, time):
        duration_mapping = ["", "16", "8", "8.", "4", ("4~", "16"), "4.", ("4~", "8."), "2",
                            ("2~", "16"), ("2~", "8"), ("2~", "8."), "2.", ("2.~", "16"),
                            ("2.~", "8"), ("2.~", "8."), "1"]
        durations = []
        notes = duration_mapping[duration]
        try:
            if len(notes) == 2:
                durations.append(notes[0])
                durations.append(notes[1])
        except TypeError:
            durations.append(notes)
        rests = duration_mapping[time - duration_mapping]
        if rests == "":
            pass
        else:
            try:
                if len(notes) == 2:
                    rests.append("r" + notes[0])
                    rests.append("r" + notes[1])
            except TypeError:
                rests.append("r" + notes)
        return durations, rests

    def map_pitch(self, pitch):
        pitch_mapping = ["c", "cis", "d", "dis", "e", "f", "fis", "g", "gis", "a", "ais", "b"]
        octaves = int(abs(pitch - self.note_base) / 12)
        note = (pitch - self.note_base) % 12
        if pitch - self.note_base >= 0:
            return pitch_mapping[note] + ["'"]*(octaves + 1)
        else:
            return pitch_mapping[note] + [","]*(octaves - 1)

    @staticmethod
    def make_export(pitch, duration):
        string_value = ""
        for value in duration[0]:
            string_value += pitch + value + " "
        for value in duration[1]:
            string_value += value + " "
        return string_value + "\n"

    def export_voice(self, voice, f_out):
        voice_string = """
        \\New Staff {
        \\clef "treble"
        \\time 4/4

        """
        for i in range(0, len(voice)):
            if i != len(voice) - 1:
                time = voice[i + 1][2]
                duration = self.map_duration(voice[i][1], time)
                pitch = self.map_pitch(voice[i][0])
                to_export = self.make_export(pitch, duration)
                voice_string += to_export
            else:
                time = voice[i + 1][2]
                duration = self.map_duration(voice[i][1], time + voice[i + 1][2])
                pitch = self.map_pitch(voice[i][0])
                to_export = self.make_export(pitch, duration)
                voice_string += to_export
        voice_string += "}\n"
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
                        voices[i].append((to_analyze[0], to_analyze[1], time))
                for i in range(self.voices):
                    self.export_voice(voices[i], f_out)
                f_out.write(self.prefix)