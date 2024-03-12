# https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/1201180358/?envType=daily-question&envId=2024-03-12
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def go(self, curr, runs):
        if curr is None:
            if len(runs) and runs[-1][0] == 0:
                return runs[-1][1]
            return set()

        if curr.val == 0:
            return set([curr])

        for i, p in enumerate(runs):
            runs[i][0] += curr.val
            runs[i][1].add(curr)
            if runs[i][0] == 0:
                return runs[i][1]

        runs.append([curr.val, set([curr])])
        return self.go(curr.next, runs)

    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head

        while 1:
            runs = []
            to_remove = self.go(head, runs)
            if len(to_remove) == 0:
                break
            assert None not in to_remove, "bad ptr in to_remove"

            # if head is going to be removed
            while head in to_remove:
                head = head.next

            curr = head
            while curr and curr.next not in to_remove:
                curr = curr.next

            while curr and curr.next in to_remove:
                curr.next = curr.next.next

        return head
