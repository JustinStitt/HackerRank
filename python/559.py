"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: "Node") -> int:
        if root is None:
            return 0
        Q = [(root, 1)]
        biggest = 1

        while len(Q):
            curr, depth = Q.pop()
            if curr is None:
                continue
            biggest = max(biggest, depth)

            for child in curr.children:
                Q.insert(0, (child, depth + 1))

        return biggest
