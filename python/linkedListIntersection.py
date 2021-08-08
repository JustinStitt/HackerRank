# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        alpha, beta = headA, headB
        seen = set()
        # run alpha through entirety of list A and store references
        while alpha:
            seen.add(alpha)
            alpha = alpha.next
        # now run through entirety of list B and check for collision in seen
        while beta:
            if beta in seen:
                return beta
            beta = beta.next
        return None # we did not find an intersection
