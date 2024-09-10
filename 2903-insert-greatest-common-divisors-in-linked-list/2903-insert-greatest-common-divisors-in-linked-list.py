# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
      
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # def gcd(a, b):
        #     while b:
        #         a, b = b, a%b
        #     return a

        temp = head
        while temp.next:
            l = temp
            r = temp.next
            m = ListNode(math.gcd(l.val, r.val))
            l.next = m
            m.next = r
            temp = r
        return head




        