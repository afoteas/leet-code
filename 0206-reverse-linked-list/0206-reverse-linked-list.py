# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseListPop(self, head: Optional[ListNode]) -> Optional[ListNode]:
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

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev
        