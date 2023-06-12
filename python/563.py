# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree_sum(self, root) -> int:
        if root is None:
            return 0

        return root.val + self.tree_sum(root.left) + self.tree_sum(root.right)

    def findTilt(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        total = 0

        stk = [root]

        while len(stk):
            curr = stk.pop()
            if curr is None:
                continue

            left = self.tree_sum(curr.left)
            right = self.tree_sum(curr.right)
            diff = abs(left - right)

            total += diff

            stk.extend([curr.left, curr.right])

        return total
