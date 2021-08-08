# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = l1
        prev = None
        # add l2 to l1 with result stored in l1
        while l1 or l2:
            if l1 and l2:
                l1.val += l2.val
                carry = l1.val // 10
                l1.val -= (10*carry)
                if not l1.next and carry > 0:
                    to_add = ListNode(carry)
                    l1.next = to_add
                elif l1.next:
                    l1.next.val += carry
                prev = l1
                l1, l2 = l1.next, l2.next
            elif not l1 and l2:
                to_add = ListNode(l2.val)
                prev.next = to_add
                prev = prev.next
                l2 = l2.next
            elif l1 and not l2:
                carry = l1.val // 10
                l1.val -= (10*carry)
                if not l1.next and carry > 0:
                    to_add = ListNode(carry)
                    l1.next = to_add
                elif l1.next:
                    l1.next.val += carry
                    l1 = l1.next
                else:
                    l1 = l1.next
        return head
