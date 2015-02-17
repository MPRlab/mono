__author__ = 'nathan'

from ToWestern import WesternConverter
import sys
import os


def main(argv):

    if len(argv) != 5:
        print "Invalid Usage!"
        print "Usage Instructions: python ConverterTool.py PitchBase Voices InFile OutFile"
    else:
        converter = WesternConverter(int(argv[1]), int(argv[2]))
        converter.convert(os.path.expanduser(argv[3]), os.path.expanduser(argv[4]))


if __name__ == '__main__':
    main(sys.argv)
