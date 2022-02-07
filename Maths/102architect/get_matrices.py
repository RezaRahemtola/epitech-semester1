import math
from matrix import Matrix

def get_translation_matrix(i: float, j: float):
    return Matrix([
        [1, 0, i],
        [0, 1, j],
        [0, 0, 1]
    ])

def get_scaling_matrix(m: float, n: float):
    return Matrix([
        [m, 0, 0],
        [0, n, 0],
        [0, 0, 1]
    ])

def get_rotation_matrix(angle: float):
    angle = math.radians(angle)
    return Matrix([
        [math.cos(angle), -math.sin(angle), 0],
        [math.sin(angle), math.cos(angle), 0],
        [0, 0, 1]
    ])

def get_reflection_matrix(slope_angle: float):
    slope_angle = math.radians(slope_angle)
    return Matrix([
        [math.cos(2 * slope_angle), math.sin(2 * slope_angle), 0],
        [math.sin(2 * slope_angle), -math.cos(2 * slope_angle), 0],
        [0, 0, 1]
    ])
