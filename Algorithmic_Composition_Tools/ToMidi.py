__author__ = 'nathan'


class MidiConveter:

    def __init__(self):
        pass

    @staticmethod
    def convert(in_filename, out_filename):
        with open(in_filename, 'r') as f_in:
            with open(out_filename, 'w') as f_out:
                pass