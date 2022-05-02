# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    new_list_head = None
    new_list_tail = None
    buffer = []
    
    itr = head
    while itr:
        buffer.append(itr.val)
        itr = itr.next
        if len(buffer) == k:
            for v in buffer[::-1]:
                to_add = ListNode(v)
                if new_list_head is None:
                    new_list_head = to_add
                    new_list_tail = new_list_head
                    continue
                new_list_tail.next = to_add
                new_list_tail = new_list_tail.next
            buffer = []
    
    for v in buffer:
        to_add = ListNode(v)
        new_list_tail.next = to_add
        new_list_tail = new_list_tail.next
    
    return new_list_head         

