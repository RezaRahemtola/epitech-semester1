import sys


def check_args_nbr(argv):
    if len(argv) < 5:
        sys.exit(84)


def check_str_is_nbr(string):
    try:
        float(string)
    except ValueError:
        sys.exit(84)


def check_flag_args(argv, argc, i):
    if (argv[i] == "-t" or argv[i] == "-z") and i + 2 < argc:
        check_str_is_nbr(argv[i + 1])
        check_str_is_nbr(argv[i + 2])
        return 2
    elif (argv[i] == "-r" or argv[i] == "-s") and i + 1 < argc:
        check_str_is_nbr(argv[i + 1])
        return 1
    else:
        sys.exit(84)


def check_error(argv):
    check_args_nbr(argv)
    flags = ["-t", "-z", "-r", "-s"]
    argc = len(argv)
    skip = 0
    check_str_is_nbr(argv[1])
    check_str_is_nbr(argv[2])
    for i in range(3, argc):
        if skip > 0:
            skip -= 1
            continue
        if argv[i] not in flags:
            sys.exit(84)
        skip += check_flag_args(argv, argc, i)
