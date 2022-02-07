from sys import exit, stderr

def check_str_is_nbr(string: str):
    try:
        float(string)
    except ValueError:
        stderr.write("bad argument: coefficients and precision must be floats.\n")
        exit(84)

def check_errors(argv: list):
    argc = len(argv)
    if argc != 8:
        stderr.write("Incorrect number of arguments.\n")
        exit(84)
    for arg in argv[2:]:
       check_str_is_nbr(arg)
    if argv[1] != "1" and argv[1] != "2" and argv[1] != "3":
        stderr.write("Incorrect method option.\n")
        exit(84)
    if int(argv[7]) < 1:
        stderr.write("Incorrect precision (should be 1 or more).\n")
        exit(84)
