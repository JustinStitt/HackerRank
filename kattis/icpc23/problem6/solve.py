from dataclasses import dataclass
p, s, t = [int(x) for x in input().split()]

coders = [] # [(8, 3, 7), (6, 9, 12)]

for _ in range(p):
    [coders.append(int(x)) for x in input().split()]

@dataclass
class State:
    solved: int = 0
    cost: int = 0

    def __gt__(self, rhs):
        if self.solved > rhs.solved:
            return True
        if self.solved == rhs.solved:
            return self.cost < rhs.cost
        return False

dp = [State()] * (t + 1)

for x in range(1, t+1):
    # best we can do is previous dp (x-1) or new selection plus old dp
    for (i, coder) in enumerate(coders):
        idx = i // 3 # get layer index
        previous = dp[x-1]
        # idk how to memoize the states of this. i.e: problems already solved and stuff
