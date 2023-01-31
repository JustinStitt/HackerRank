# let's generate every possible permutation of four 4's and three binary ops
from itertools import product

ops = "*+-/"

d = dict()

for (op1, op2, op3) in product(ops, repeat=3):  # ('*', '-', '/')
    expression_og = f"4 {op1} 4 {op2} 4 {op3} 4"
    expression = expression_og.replace("/", "//")
    answer = eval(expression)
    d[answer] = expression_og

print(d)
