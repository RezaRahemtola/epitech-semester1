def compute_torus(torus, x):
    return (torus.a4 * x ** 4 + torus.a3 * x ** 3 + torus.a2 * x ** 2 + torus.a1 * x + torus.a0)

def compute_prime_torus(torus, x):
    return (4 * torus.a4 * x ** 3 + 3 * torus.a3 * x ** 2 + 2 * torus.a2 * x + torus.a1)

def get_truncated_float(nb: float, precision: int):
    nb_round = round(nb, precision)
    result = str(nb_round)
    decimals = result.split(".")[1]
    original_decimals = str(nb).split(".")[1]
    if precision >= len(original_decimals):
        return (str(nb))
    while precision > len(decimals):
        result += "0"
        decimals = result.split(".")[1]
    return (result)
