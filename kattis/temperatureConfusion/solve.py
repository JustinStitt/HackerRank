from math import gcd


def fToC(numer, denom):
    as_fraction = 32 * denom
    numer -= as_fraction
    numer *= 5
    denom *= 9
    return (numer, denom)


numerator, denominator = [int(x) for x in input().split("/")]

n, d = fToC(numerator, denominator)
_gcd = gcd(n, d)
print(f"{n//_gcd}/{d//_gcd}")
