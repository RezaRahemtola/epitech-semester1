from matrix import Matrix
from sys import exit

def inverse_2d_matrix(matrix: Matrix):
    new = Matrix(matrix.values)
    determinant = (new.values[0][0] * new.values[1][1]) - (new.values[0][1] * new.values[1][0])

    if determinant == 0:
        exit(84)
    new.values[0][0], new.values[1][1] = new.values[1][1], new.values[0][0]
    new.values[0][1] *= -1
    new.values[1][0] *= -1
    for i, row in enumerate(new.values):
        for j in range(len(row)):
            new.values[i][j] *= (1 / determinant)
    return (new)

def inverse_3d_matrix(matrix: Matrix):
    new = Matrix(matrix.values)

    determinant = get_3d_matrix_det(new)
    if determinant == 0:
        exit(84)
    new = new.get_transpose()
    det_matrix = get_det_matrix(new)
    for i in range(3):
        for j in range(3):
            det_matrix.values[i][j] /= determinant
    return (det_matrix)

def get_3d_matrix_det_of_cell(matrix: Matrix, searched_row: int, searched_column: int):
    elements = []
    for row, row_values in enumerate(matrix.values):
        for column, value in enumerate(row_values):
            if row is not searched_row and column is not searched_column:
                elements.append(value)

    return (elements[0] * elements[3]) - (elements[1] * elements[2])

def get_3d_matrix_det(matrix: Matrix):
    first_value = get_3d_matrix_det_of_cell(matrix, 0, 0) * matrix.values[0][0]
    second_value = get_3d_matrix_det_of_cell(matrix, 0, 1) * matrix.values[0][1] * -1
    third_value = get_3d_matrix_det_of_cell(matrix, 0, 2) * matrix.values[0][2]

    return (first_value + second_value + third_value)


def get_det_matrix(matrix: Matrix):
    cofactors = Matrix([[1, -1, 1], [-1, 1, -1], [1, -1, 1]])
    result = []
    sub_result = []

    for i in range(3):
        for j in range(3):
            sub_result.append(get_3d_matrix_det_of_cell(matrix, i, j) * cofactors.values[i][j])
        result.append(sub_result)
        sub_result = []
    return Matrix(result)