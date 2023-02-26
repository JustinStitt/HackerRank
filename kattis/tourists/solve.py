from collections import defaultdict
from dataclasses import dataclass
from queue import Queue
import sys

lines = [line.rstrip() for line in sys.stdin.readlines()]
n = int(lines[0])

G = defaultdict(lambda: set())

for x in lines[1:]:
    u, v = [int(k) for k in x.split()]
    G[u].add(v)
    G[v].add(u)  # bidirectional

# mults = range(curr * 2, n + 1, curr)


@dataclass
class State:
    idx: int
    path: list

    def __iter__(self):
        return iter((self.idx, self.path))


Q = Queue()
starting = State(1, [1])
Q.put(starting)  # start, length
dists = {}  # dists[(1, 3)] = dist from 1 to 3
connects = defaultdict(lambda: set())

while not Q.empty():
    curr = Q.get()
    idx, path = curr

    for neighbor in G[idx]:
        if neighbor in path:
            continue
        for (i, prev) in enumerate(path):
            dists[(prev, neighbor)] = len(path) - i + 1
            dists[(neighbor, prev)] = len(path) - i + 1
            connects[neighbor].add(prev)
            connects[prev].add(neighbor)
        next_state = State(neighbor, path + [neighbor])
        Q.put(next_state)


def getDistFrom(u, v):
    global dists, connects
    lookup = dists.get((u, v), None)
    if lookup:
        return lookup
    else:
        # find something that connects to what we want
        best = (0, 10**18)
        for conn in connects[v]:
            if conn not in connects[u]:
                continue
            if dists[(v, conn)] < best[1]:
                best = (conn, dists[(v, conn)])
            # return dists[(u, 1)] + dists[(1, v)] - 1  # using 1 twice so sub 1
        return getDistFrom(u, best[0]) + getDistFrom(best[0], v) - 1


# print(dists)
# print(connects)
# if no (u, v) exists in dists then use (u, 1) (1, v)
total = 0
for u in range(1, n // 2 + 2):  # !! technically only need n // 2
    # for each number, find the multiples
    mults = range(u * 2, n + 1, u)
    for mult in mults:  # dist
        ans = getDistFrom(u, mult)
        total += ans
        dists[(u, mult)] = ans
        dists[(mult, u)] = ans
        # print(f"{u=}, {mult=}, {ans=}")

print(total)
