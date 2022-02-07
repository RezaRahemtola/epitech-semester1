from torus import Torus
from calculs import *
from sys import exit, stderr

def newton(torus: Torus, interval: float):
    print(f"x = {get_truncated_float(interval, torus.n)}")
    prime = compute_prime_torus(torus, interval)
    if prime == 0:
        stderr.write("Zero division error.")
        exit(84)
    interval_n1 = interval - compute_torus(torus, interval) / prime
    if abs(compute_torus(torus, interval)) > (10 ** -torus.n): #### à check ####
        newton(torus, interval_n1)
