import sys
from math import *

# from pprint import pprint as pprint
# from sympy.ntheory.modular import crt


def solve():
    x = int(input())
    assert x > 0
    regular_count = len(bin(x)) - 2
    special_count = regular_count - 1

    # special case
    if x & (x + 1) == 0:
        print("0" * regular_count)
    else:
        first_in_range = 2**special_count - 1
        offset = x - first_in_range
        print(bin(offset)[2:].zfill(special_count))


if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        solve()
    # solve()
