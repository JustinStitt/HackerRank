from collections import defaultdict


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        freq_map = defaultdict(lambda: int())

        # any traversal works just fine, let's do BFS
        Q = [root]
        while len(Q):
            curr = Q.pop()
            if curr is None:
                continue
            freq_map[curr.val] += 1

            Q.append(curr.left)
            Q.append(curr.right)

        mode_amnt = max(freq_map.values())
        ans = [x for x in freq_map.keys() if freq_map[x] == mode_amnt]
        return ans
