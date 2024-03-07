# https://leetcode.com/problems/middle-of-the-linked-list/submissions/1196386512/?envType=daily-question&envId=2024-03-07
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nodes = []

        curr = head
        while curr:
            nodes.append(curr)
            curr = curr.next

        return nodes[len(nodes) // 2]
