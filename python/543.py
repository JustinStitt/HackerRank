# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self, root) -> int:
        if root is None:
            return 0
        return 1 + max(self.depth(root.left), self.depth(root.right))

    def traverse(self, root, bests: list[int]):
        if root is None:
            return

        left_depth = self.depth(root.left)
        right_depth = self.depth(root.right)

        bests.append(left_depth + right_depth)

        self.traverse(root.left, bests)
        self.traverse(root.right, bests)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        bests = []

        self.traverse(root, bests)
        print(bests)
        return max(bests)
