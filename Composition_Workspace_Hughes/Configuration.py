__author__ = 'nathan'


class Configuration:
    """
    This class is intended to be a collection of the different parameters that make up a configuration, and gives easy
    access to parameters based on voices
    """
    def __init__(self, voices, pitches, durations):
        self.voices = voices
        self.pitches = pitches
        self.durations = durations
        if len(pitches) != voices:
            raise ValueError("There should be an assigned pitch for each voice")
        if len(durations) != voices:
            raise ValueError("There should be an assigned duration for each voice")

    def get_pitch(self, voice):
        return self.pitches[voice]

    def get_duration(self, voice):
        return self.durations[voice]

    def get_all_coordinates(self):
        return self.durations + self.voices