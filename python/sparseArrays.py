# link = https://www.hackerrank.com/challenges/sparse-arrays
from collections import defaultdict

n = int(input())

lookup = defaultdict(lambda: 0)
for _ in range(n):
    lookup[input()] += 1

q = int(input())
queries = [input() for _ in range(q)]

res = []

for query in queries:
    res.append(lookup[query])

[print(x) for x in res]
