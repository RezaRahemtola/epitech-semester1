from matrix import Matrix
from encrypt import get_key_matrix, print_key_matrix
from inverse_matrix import *


def get_message_matrix(message: str, nb_col: int):
    result = []
    index = 0

    message = message.split()
    while len(message) % nb_col != 0:
        message.append("0")
    while index < len(message):
        result.append([int(message[index + i]) for i in range(nb_col)])
        index += nb_col
    return Matrix(result)

def print_decrypted_message(decrypted_message: Matrix):
    print("\nDecrypted message:")
    for row in decrypted_message.values:
        for elem in row:
            if int(round(elem)) != 0:
                print(chr(int(round(elem))), end="")
    print()

def decrypt(message: str, key: str):
    key_matrix = get_key_matrix(key)
    message_matrix = get_message_matrix(message, key_matrix.rows)

    if key_matrix.rows == 1:
        key_matrix.values[0][0] = 1 / key_matrix.values[0][0]
    if key_matrix.rows == 2:
        key_matrix = inverse_2d_matrix(key_matrix)
    if key_matrix.rows == 3:
        key_matrix = inverse_3d_matrix(key_matrix)
    if key_matrix.rows >= 1 and key_matrix.rows <= 3:
        print_key_matrix(key_matrix)
        decrypted_message = message_matrix.multiply_by(key_matrix)
        print_decrypted_message(decrypted_message)
