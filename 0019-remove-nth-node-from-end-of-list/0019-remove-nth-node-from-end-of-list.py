# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        i = 1
        rn = None
        lp = None
        total = 0
        while temp:
            temp = temp.next
            total +=1
        if total == n:
            return head.next
        temp = head
        while temp:
            if i + 1 == total +1 - n:
                lp = temp
            if i == total -n +2:
                rn = temp
                break
            temp = temp.next
            i+=1
        lp.next = rn
        return head


        