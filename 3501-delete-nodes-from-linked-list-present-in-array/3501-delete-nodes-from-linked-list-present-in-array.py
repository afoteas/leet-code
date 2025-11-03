# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedListDict(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
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

    def modifiedListBetter(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        # Create a set for efficient lookup of values in nums
        values_to_remove = set(nums)

        # Handle the case where the head node needs to be removed
        while head and head.val in values_to_remove:
            head = head.next

        # If the list is empty after removing head nodes, return None
        if not head:
            return None

        # Iterate through the list, removing nodes with values in the set
        current = head
        while current.next:
            if current.next.val in values_to_remove:
                # Skip the next node by updating the pointer
                current.next = current.next.next
            else:
                # Move to the next node
                current = current.next

        return head

    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        n = set(nums)
        dummy = ListNode(0)
        dummy.next = head
        curr = dummy
        while curr.next:
            if (curr.next.val in n):
                curr.next = curr.next.next
            else:
                curr = curr.next
        return dummy.next

        
                
                


        