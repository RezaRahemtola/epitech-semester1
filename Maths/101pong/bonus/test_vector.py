import unittest
from vector import Vector


class Test_vectors(unittest.TestCase):
    def test_add_vector(self):
        v1 = Vector(1, 2, 3)
        v2 = Vector(4, 5, 6)
        v_result = v1.add_vector(v2)
        self.assertEqual(v_result.x, 5)
        self.assertEqual(v_result.y, 7)
        self.assertEqual(v_result.z, 9)

    def test_sub_vector(self):
        v1 = Vector(1, 2, 3)
        v2 = Vector(4, 5, 6)
        v_result = v1.sub_vector(v2)
        self.assertEqual(v_result.x, -3)
        self.assertEqual(v_result.y, -3)
        self.assertEqual(v_result.z, -3)

    def test_get_norm(self):
        v1 = Vector(1, 2, 3)
        result = v1.get_norm()
        self.assertAlmostEqual(result, 3.7416573867739)


if __name__ == "__main__":
    unittest.main()
