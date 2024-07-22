# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        values = [head.val]
        pointer = head
        while pointer and pointer.next:
            if pointer.next.val in values:
                pointer.next = pointer.next.next
            else:
                values.append(pointer.next.val)
                pointer = pointer.next
        return head
                
        