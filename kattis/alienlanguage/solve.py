def convertAlienToDecimal(number, language):
    base = len(language)
    decimal = 0
    for (idx, digit) in enumerate(number):
        exp = len(number) - idx - 1
        val = language.index(digit)
        decimal += base**exp * val
        # print(f"{val=}, {exp=}, {number=}, {language=}, {base=}, {idx=}")
    return decimal


def convertDecimalToAlien(decimal, language):
    base = len(language)
    result = numberToBase(decimal, base)
    answer = [language[digit] for digit in result]
    return "".join(answer)


def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]


cases = int(input())

for case in range(1, cases + 1):
    number, source, dest = input().split(" ")
    res = convertAlienToDecimal(number, source)
    res = convertDecimalToAlien(res, dest)
    print(f"Case #{case}: {res}")
