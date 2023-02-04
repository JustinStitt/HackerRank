from queue import Queue
from dataclasses import dataclass

n, s, t = [int(x) for x in input().split()]
# adj_mat = [[0 for _ in range(n)] for __ in range(n)]
adj_mat = []

for _ in range(n):
    raw = [int(x) for x in input().split()]
    adj_mat.append(raw)

sam = {}


@dataclass
class State:
    idx: int
    cost: int
    vis: set

    def __iter__(self):
        return iter((self.idx, self.cost, self.vis))


Q = Queue()
initial = State(s, 0, set())
Q.put(initial)
initial.vis.add(s)

best = 10**18

while not Q.empty():
    st = Q.get()  # also pops
    # print(f"{st=}")
    idx, cost, vis = st
    if cost >= best:
        continue
    vis.add(idx)
    if idx == t:
        best = min(best, cost)
        continue

    for (i, neighbor) in enumerate(adj_mat[idx]):
        if i == idx or i in vis:
            continue
        # otherwise, we gucci no brain rot go there
        if neighbor + cost >= best:
            continue
        new_state = State(i, cost + neighbor, set(vis))
        Q.put(new_state)

print(best)
