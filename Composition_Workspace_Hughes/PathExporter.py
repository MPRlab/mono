__author__ = 'nathan'


class PathExporter:

    def __init__(self):
        pass

    @staticmethod
    def export_path(path, filename):
        with open(filename, 'w') as f:
            time = 0
            for configuration in path:
                line = "T: %d" % time
                max_duration = 0
                for i in range(configuration.get_voices()):
                    line += "|%d %d " % configuration.get_pitch(i), configuration.get_duration(i)
                    if configuration.get_duration(i) > max_duration:
                        max_duration = configuration.get_duration(i)
                    f.write(line)
                time += max_duration