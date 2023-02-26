from queue import Queue
from dataclasses import dataclass

# mini-max
n, m = [int(x) for x in input().split()]


# construct entire mini-max tree
@dataclass
class Node:
    s1: int
    s2: int
    player: int
    value: int
    neighbors: list

    def __iter__(self):
        return iter((self.s1, self.s2, self.player, self.value, self.neighbors))


root = Node(n, m, 0, -1, neighbors=[])
Q = Queue()
Q.put(root)

while not Q.empty():
    node = Q.get()
    s1, s2, player, value, neighbors = node
    if s1 == 0 or s2 == 0:
        node.value = player
        continue
    larger = s1 if s1 > s2 else s2
    smaller = s1 if s1 < s2 else s2
    # take multiple of smaller from larger (construct children)
    for multiple in range(smaller, larger + 1, smaller):
        next_player = 1 if player == 0 else 0
        child = Node(smaller, larger - multiple, next_player, -1, neighbors=[])
        neighbors.append(child)
        Q.put(child)

# now perform mini-max algo (dfs)
def mini_max(curr, is_min) -> int:
    if not curr:
        print("how did we get here?")
        return None
    if not len(curr.neighbors):  # is a leaf node
        return curr.value

    values = [mini_max(child, not is_min) for child in curr.neighbors]
    return min(values) if is_min else max(values)


result = mini_max(root, is_min=False)
print("win" if result == 1 else "lose")
