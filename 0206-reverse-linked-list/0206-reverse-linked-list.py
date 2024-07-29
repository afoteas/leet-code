# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        l = []
        if not head:
            return None
        while head:
            l.append(head)
            head=head.next
        head= l.pop()
        temp = head
        while l:
            temp.next = l.pop()
            temp = temp.next
        temp.next= None
        return head

        