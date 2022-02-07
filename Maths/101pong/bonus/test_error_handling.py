import unittest
from error_handling import *


class Test_error_handling(unittest.TestCase):
    def test_no_arguments(self):
        argv = ["./101pong"]
        self.assertRaises(SystemExit, error_handling, argv)

    def test_not_enough_arguments(self):
        argv = ["./101pong", "1", "2", "3"]
        self.assertRaises(SystemExit, error_handling, argv)

    def test_too_many_arguments(self):
        argv = ["./101pong", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]
        self.assertRaises(SystemExit, error_handling, argv)

    def test_incorrect_argument(self):
        argv = ["./101pong", "1", "2", "3", "TEST", "5", "6", "7"]
        self.assertRaises(SystemExit, error_handling, argv)

    def test_negative_time_shift(self):
        argv = ["./101pong", "1", "2", "3", "4", "5", "6", "-42"]
        self.assertRaises(SystemExit, error_handling, argv)

    def test_float_time_shift(self):
        argv = argv = ["./101pong", "1", "2", "3", "4", "5", "6", "7.62"]
        self.assertRaises(SystemExit, error_handling, argv)


if __name__ == "__main__":
    unittest.main()
