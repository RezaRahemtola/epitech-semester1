from sys import exit


def display_help():
    print("USAGE\n\t./104intersection opt xp yp zp xv yv zv p")
    print("DESCRIPTION\n\topt\t\tsurface option: 1 for a sphere, 2 for a cylinder, 3 for a cone")
    print("\t(xp, yp, zp)\tcoordinates of a point by which the light ray passes through")
    print("\t(xv, yv, zv)\tcoordinates of a vector parallel to the light ray")
    print("\tp\t\tparameter: radius of the sphere, radius of the cylinder, or angle formed by the cone and the Z-axis")


def check_opt_param(opt: str):
    if opt != "1" and opt != "2" and opt != "3":
        print(f"Invalid surface: got {opt} but expected 1, 2 or 3.")
        exit(84)


def check_str_is_nbr(string: str):
    try:
        float(string)
    except ValueError:
        print("bad argument: point and vector coordinates must be float.")
        exit(84)


def check_last_param(p: str, opt: str):
    if (opt == "1" or opt == "2") and float(p) <= 0:
        print("Invalid radius argument.")
        exit(84)
    elif opt == "3" and (float(p) <= 0 or float(p) >= 90):
        print("Invalid angle argument.")
        exit(84)


def check_errors(argv: list):
    argc = len(argv)
    if argc == 2 and argv[1] == "-h":
        display_help()
        exit(0)
    elif argc != 9:
        print(f"Error: got {str(argc)} arguments but expected 9.")
        exit(84)
    check_opt_param(argv[1])
    for arg in argv[2:]:
        check_str_is_nbr(arg)
    vector = [float(argv[5]), float(argv[6]), float(argv[7])]
    if vector[0] == vector[1] == vector[2] == 0:
        print("bad arguments: vector cannot be null")
        exit(84)
    check_last_param(p=argv[8], opt=argv[1])
