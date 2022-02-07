def surface_type(surface: str, param: str):
    if surface == "1":
        print(f"Sphere of radius {str(param)}")
    elif surface == "2":
        print(f"Cylinder of radius {str(param)}")
    else:
        print(f"Cone with a {str(param)} degree angle")


def passing_through_point(point: list, vector: list):
    print(f"Line passing through the point ({int(point[0])}, {int(point[1])}, {int(point[2])}) ", end="")
    print(f"and parallel to the vector ({int(vector[0])}, {int(vector[1])}, {int(vector[2])})")


def solutions(solutions: list, point: list, vector: list):
    if len(solutions) == 0:
        print("No intersection point.")
    elif len(solutions) == 1:
        print("1 intersection point:")
    elif len(solutions) == 2:
        print("2 intersection points:")

    for sol in solutions[::-1]:
        sol_point = [point[i] + sol * vector[i] for i in range(3)]
        print(f"({sol_point[0]:.3f}, {sol_point[1]:.3f}, {sol_point[2]:.3f})")