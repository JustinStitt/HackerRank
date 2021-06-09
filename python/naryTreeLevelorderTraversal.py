"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return []
        Q = [root]
        ret = []
        while len(Q) > 0:
            ret.append([node.val for node in Q])
            Q = [child for node in Q for child in node.children if child]
        return ret
