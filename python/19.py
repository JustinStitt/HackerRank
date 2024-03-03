# https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1192964831/?envType=daily-question&envId=2024-03-03
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if n == 1 and not head.next:
            return None

        history = [None] * (n + 1)

        curr = head

        while curr:
            history.pop(0)
            history.append(curr)
            prev = curr
            curr = curr.next

        if history[0] is None:
            return head.next

        history[0].next = history[1].next

        return head
