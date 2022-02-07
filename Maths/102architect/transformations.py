from get_matrices import *

def translate(matrix, i: int, j: int):
    translation_matrix = get_translation_matrix(i, j)
    print(f"Translation along vector ({int(i)}, {int(j)})")
    if matrix is not None:
        return translation_matrix.multiply_by(matrix)
    else:
        return translation_matrix

def scale(matrix, m: int, n: int):
    scaling_matrix = get_scaling_matrix(m, n)
    print(f"Scaling by factors {int(m)} and {int(n)}")
    if matrix is not None:
        return scaling_matrix.multiply_by(matrix)
    else:
        return scaling_matrix

def rotate(matrix, angle: int):
    rotation_matrix = get_rotation_matrix(angle)
    print(f"Rotation by a {int(angle)} degree angle")
    if matrix is not None:
        return rotation_matrix.multiply_by(matrix)
    else:
        return rotation_matrix

def reflect(matrix, slope_angle: int):
    reflection_matrix = get_reflection_matrix(slope_angle)
    print(f"Reflection over an axis with an inclination angle of {int(slope_angle)} degrees")
    if matrix is not None:
        return reflection_matrix.multiply_by(matrix)
    else:
        return reflection_matrix