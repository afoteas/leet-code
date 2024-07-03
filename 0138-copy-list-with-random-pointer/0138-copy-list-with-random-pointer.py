"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
import copy

class Solution:
    def copyRandomList2(self, head: 'Optional[Node]') -> 'Optional[Node]':
        dc = copy.deepcopy(head)
        return dc


    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':

        if not head:
            return None
        
        curr = head

        # add mode nodes betwwen the old ones
        while curr:
            nn=Node(curr.val)
            nn.next = curr.next
            curr.next = nn
            curr = nn.next
        
        curr = head

        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            if curr.next.next:
                curr = curr.next.next
            else:
                break
        
        curr = head
        new_head = head.next
        new_curr = new_head

        while new_curr:
            curr.next = new_curr.next
            if curr.next:
                new_curr.next = curr.next.next
            else:
                new_curr.next= None
            new_curr = new_curr.next
        
        return new_head


        
        
