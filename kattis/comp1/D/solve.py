import sys
import math

lines = [line.rstrip() for line in sys.stdin.readlines()]

syms = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '"
assert len(syms) == 28, "alphabet length must be 28"

# 15 fps
s, e = 0, 27


def solve(line):
    pickups = len(line)
    curr = 0
    going_to = 1
    total_dist = 0

    while going_to < len(line):
        me = ord(line[curr]) - 65
        to = ord(line[going_to]) - 65
        if to == -33:
            to = 26
        if to == -26:
            to = 27
        if me == -33:
            me = 26
        if me == -26:
            me = 27
        # print(f"{to=}, {me=}, {line[curr]=}, {line[going_to]=}, {ord(line[curr])=}")

        # going left
        raw_dist = abs(to - me)
        # try left wrap, right wrap
        raw_dist = min(raw_dist, me + abs(e - to) + 1, abs(me - e) + to + 1)
        total_dist += raw_dist * math.pi * 60 / 28 / 15 + 1
        curr = going_to
        going_to = going_to + 1
    # total_dist *= (math.pi * 60.0) / 28 / 15
    # total_dist += pickups
    print("{:.10f}".format(total_dist))


for line in lines:
    solve(line)
