from matrix import Matrix


def get_key_matrix(key: str):
    square_size = 1
    result = []
    index = 0

    while square_size**2 < len(key):
        square_size += 1
    key += "\0" * (square_size**2 - len(key))
    while len(result) < square_size:
        result.append([ord(key[index + i]) for i in range(square_size)])
        index += square_size
    return Matrix(result)


def get_message_matrix(message: str, nb_col: int):
    result = []
    index = 0

    while len(message) % nb_col != 0:
        message += "\0"
    while index < len(message):
        result.append([ord(message[index + i]) for i in range(nb_col)])
        index += nb_col
    return Matrix(result)


def print_key_matrix(key_matrix: Matrix):
    print("Key matrix:")
    for row in key_matrix.values:
        for i, value in enumerate(row):
            print(str(value), end="\t" if i != len(row) - 1 else "\n")


def print_encrypted_message(message: Matrix):
    print("\nEncrypted message:")
    for i, row in enumerate(message.values):
        for j, elem in enumerate(row):
            end_str = "\n" if j == len(row) - 1 and i == len(message.values) - 1 else " "
            print(str(elem), end=end_str)


def encrypt(message: str, key: str):
    key_matrix = get_key_matrix(key)
    print_key_matrix(key_matrix)
    message_matrix = get_message_matrix(message, len(key_matrix.values))
    encrypted_message = message_matrix.multiply_by(key_matrix)
    print_encrypted_message(encrypted_message)
