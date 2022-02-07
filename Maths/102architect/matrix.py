class Matrix:
    def __init__(self, values: list):
        last_value = len(values[0])
        for row in values:
            if last_value != len(row):
                raise Exception("Error: Matrix with uncoherent rows length.")
            else:
                last_value = len(row)
        self.values = values
        self.rows = len(values)
        self.columns = len(values[0])

    def multiply_by(self, factor):
        if self.columns != factor.rows:
            raise Exception("Error: Matrices with different rows and columns.")
        result = []
        for row in self.values:
            line_result = []
            for col_nbr in range(factor.columns):
                col = factor.get_column(col_nbr)
                value = sum([row[i] * col[i] for i in range(len(row))])
                line_result.append(value)
            result.append(line_result)
        return Matrix(result)

    def get_column(self, col_index):
        result = []
        for i, value in enumerate(self.values):
            result.append(self.values[i][col_index])
        return result

    def print(self):
        for row in self.values:
            print(f"{r2d(row[0]):.2f}\t{r2d(row[1]):.2f}\t{r2d(row[2]):.2f}")

def r2d(number: float):
    return float(f"{number:.2f}") + 0
