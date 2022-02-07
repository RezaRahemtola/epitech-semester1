from torus import Torus
from calculs import compute_torus, get_truncated_float

def bisection(torus: Torus, interval: list):
    a, b = interval
    c = (a + b) / 2
    print(f"x = {get_truncated_float(c, torus.n)}")
    if abs(compute_torus(torus, c)) > pow(10, -torus.n):
        if compute_torus(torus, a) * compute_torus(torus, c) < 0:
            bisection(torus, [a, c])
        else:
            bisection(torus, [c, b])
