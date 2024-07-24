# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        temp = head
        num = 1
        while temp.next:
            temp = temp.next
            num+=1
        temp.next = head
        l = k % num
        temp = head
        for i in range(num-l-1):
            temp = temp.next
        ret = temp.next
        temp.next = None
        return ret




        