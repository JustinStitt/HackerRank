import sys
from collections import defaultdict

lines = [line.rstrip() for line in sys.stdin.readlines()]

def solve(line):
    line = line.replace(' ', '')
    for l in range(1, len(line)):
        freq = defaultdict(lambda: int())
        local_max = -1 # !! -1 fucky?
        for (i, v) in enumerate(line):
            substr = line[i: i+l]
            freq[substr] += 1
            local_max = max(local_max, freq[substr])
        if local_max <= 1:
            return
        print(local_max)

for line in lines:

    solve(line)
    if line != lines[-1]:
        print()
