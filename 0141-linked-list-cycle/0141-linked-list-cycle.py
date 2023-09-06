# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle_1(self, head: Optional[ListNode]) -> bool:
        nodes = []
        h = head
        while h:
            if h in nodes:
                return True
            else:
                nodes.append(h)
                h = h.next
        return False 
       
    def hasCycle_2(self, head: Optional[ListNode]) -> bool:
        h = head
        for i in range (10001):
            if not h:
                return False
            else:
                h = h.next    
        return True       

    def hasCycle(self, head: Optional[ListNode]) -> bool:
        h1 = head
        if not head or not head.next:
            return False
        h2 = head.next
        while h1 and h2:
            if h1 == h2:
                return True
            else:
                h1 = h1.next
                if not h2.next:
                    return False
                else:    
                    h2 = h2.next.next    
        return False       