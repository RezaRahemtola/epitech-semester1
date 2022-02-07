from sys import exit


def check_char(char):
    if char not in "0123456789.-":
        exit(84)

def error_handling(argv):
    for arg in argv[1:]:
        for char in arg:
            check_char(char)
    if len(argv) != 8 or float(argv[7]) < 0 or not argv[7].isdigit():
        exit(84)
