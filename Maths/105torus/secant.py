from torus import Torus
from calculs import compute_torus, get_truncated_float, compute_prime_torus
from sys import stderr, exit

def secant(torus: Torus, interval: list):
    xn_minus_1, xn = interval
    divide = compute_torus(torus, xn) - compute_torus(torus, xn_minus_1)
    if compute_prime_torus(torus, xn) == 0:
        stderr.write("The solution diverge.")
        exit(84)
    if divide == 0:
        stderr.write("Zero division error.")
        exit(84)
    xn_plus_1 = xn - (compute_torus(torus, xn) * (xn - xn_minus_1)) / divide
    print(f"x = {get_truncated_float(xn_plus_1, torus.n)}")
    if abs(compute_torus(torus, xn_plus_1)) > (10 ** -torus.n): #### à check ####
        secant(torus, [xn, xn_plus_1])
