from matrix import Matrix
from decrypt import *

def encrypt_encrypted(message: str, key: str):
    key_matrix = get_key_matrix(key)
    message_matrix = get_message_matrix(message, key_matrix.rows)

    if key_matrix.rows == 3:
        key_matrix = inverse_3d_matrix_encrypt_encrypted(key_matrix)
        print_key_matrix(key_matrix)
        decrypted_message = message_matrix.multiply_by(key_matrix)
        print_decrypted_message(decrypted_message)
    else:
        raise Exception("You can encrypt an encrypted matrix only with a 3x3 key")

def inverse_3d_matrix_encrypt_encrypted(matrix: Matrix):
    new_matrix = Matrix(matrix.values)
    determinant = get_3d_matrix_encrypt_encrypted_det(new_matrix)

    new_matrix = new_matrix.get_transpose()
    det_matrix = get_det_matrix(new_matrix)
    for i in range(3):
        for j in range(3):
            det_matrix.values[i][j] /= determinant
    return (det_matrix)

def get_3d_matrix_encrypt_encrypted_det(matrix: Matrix):
    first_value = get_3d_matrix_det_of_cell(matrix, 0, 0)
    second_value = get_3d_matrix_det_of_cell(matrix, 0, 1) * -1
    third_value = get_3d_matrix_det_of_cell(matrix, 0, 2)

    return (first_value + second_value + third_value)