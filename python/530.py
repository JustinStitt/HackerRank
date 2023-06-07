from collections import defaultdict


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        best = 10**18
        nodes = []

        # dfs
        stk = [root]

        while len(stk):
            curr = stk.pop()
            if curr is None:
                continue
            stk.extend([curr.left, curr.right])

            nodes.append(curr.val)

        nodes = sorted(nodes)

        for u, v in zip(nodes, nodes[1:]):
            best = min(best, abs(u - v))
            if best == 1:
                return 1

        return best
