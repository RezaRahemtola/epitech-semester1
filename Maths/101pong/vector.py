from math import sqrt

class Vector:
    def __init__(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)

    def add_vector(self, to_add):
        return Vector(self.x + to_add.x, self.y + to_add.y, self.z + to_add.z)

    def sub_vector(self, to_sub):
        return Vector(self.x - to_sub.x, self.y - to_sub.y, self.z - to_sub.z)

    def get_norm(self):
        return sqrt(self.x**2 + self.y**2 + self.z**2)
