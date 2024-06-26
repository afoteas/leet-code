# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        temp = dummy
        rem = 0
        while l1 and l2:
            temp.val = l1.val + l2.val + rem
            rem = temp.val // 10
            temp.val -=rem*10
            l1 = l1.next
            l2 = l2.next
            if l1 or l2 or rem:
                temp.next = ListNode()
            temp = temp.next
        while l1:
            temp.val = l1.val + rem
            rem = temp.val // 10
            temp.val -=rem*10
            l1 = l1.next
            if l1 or rem:
                temp.next = ListNode()
                temp = temp.next
        while l2:
            temp.val = l2.val + rem
            rem = temp.val // 10
            temp.val -=rem*10
            l2 = l2.next
            if l2 or rem:
                temp.next = ListNode()
                temp = temp.next
        if rem:
            temp.val=rem
        return dummy

        
            

        