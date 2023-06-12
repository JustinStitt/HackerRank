from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
MOD1 = 10**18 + 7
MOD2 = 2**31 - 1


class Solution:
    def hash_tree(self, root, memo=dict()) -> int:
        if root is None:
            return -1
        if memo.get(root, None):
            return memo[root]

        left = self.hash_tree(root.left, memo)
        right = self.hash_tree(root.right, memo)

        left = (left << 5) % MOD1
        right = (right << 7) % MOD2

        result = ((left ^ 27) * (right + 13 + root.val)) % (MOD1 ^ MOD2)
        memo[root] = result
        return result

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        stk = [root]

        while len(stk):
            curr = stk.pop()
            if curr is None:
                continue
            if self.hash_tree(curr) == self.hash_tree(subRoot):
                return True

            stk.extend([curr.left, curr.right])
        return False
