__author__ = 'nathan'


if __name__ == '__main__':
    import sys
    import re
    with open(sys.argv[1], "r") as f_in:
        with open(sys.argv[2], "w") as f_out:
            for line in f_in:
                temp = re.findall('-*\d+', line)
                print int(temp[1])
                if int(temp[1]) == -1:
                    pass
                else:
                    f_out.write(line)
