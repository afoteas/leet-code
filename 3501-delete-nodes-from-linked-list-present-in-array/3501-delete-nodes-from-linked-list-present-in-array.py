# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        ret = None
        end = None
        cur = head
        seen = []
        notSeen = []
        numsCheck = {}
        for num in nums:
            numsCheck[num] = True


        while cur.next:
            if not cur.val in numsCheck:
                if not ret:
                    ret = cur
                    end = cur
                else:
                    end.next = cur
                    end = end.next
            cur = cur.next
        if cur.val in numsCheck:
            end.next = None
        else:
            if not ret:
                ret = cur
                end = cur
            else:
                end.next = cur
        return ret



        
                
                


        