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
        numsDict = {}
        for num in nums:
            numsDict[num] = True

        def findVal(val):
            # if val in seen:
            #     return True
            # if val in notSeen:
            #     return False
            # if val in nums:
            #     seen.append(val)
            #     return True
            # notSeen.append(val)
            # return False
            if val in numsDict:
                return True
            else:
                return False

        while cur.next:
            if not findVal(cur.val):
                if not ret:
                    ret = cur
                    end = cur
                else:
                    end.next = cur
                    end = end.next
            cur = cur.next
        if findVal(cur.val):
            end.next = None
        else:
            if not ret:
                ret = cur
                end = cur
            else:
                end.next = cur
        return ret



        
                
                


        