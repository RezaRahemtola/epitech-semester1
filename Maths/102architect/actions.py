from transformations import *


class Action:
    def __init__(self, flag: chr, args_nb: int, consumer):
        self.flag = flag
        self.args_nb = args_nb
        self.consumer = consumer

    def increment(self, index):
        return index + self.args_nb


TRANSLATE = Action('t', 2, lambda matrix, i, j: translate(matrix, i, j))
SCALE = Action('z', 2, lambda matrix, m, n: scale(matrix, m, n))
ROTATE = Action('r', 1, lambda matrix, angle: rotate(matrix, angle))
REFLECT = Action('s', 1, lambda matrix, slope_angle: reflect(matrix, slope_angle))
