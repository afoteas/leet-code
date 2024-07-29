# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        delete = -101
        while head.next:
            if head.val != head.next.val and head.val != delete:
                break
            else:
                delete = head.val
                head = head.next
        if not head.next:
            if head.val == delete:
                return None
            else:
                return head

        temp = head
        last = temp
        delete = -101
        while temp.next:
            if temp.next.val == temp.val or temp.val == delete:
                delete = temp.val
                temp = last
                last.next = temp.next.next
            else:
                last=temp

            temp = temp.next

        if temp.val == delete:
            temp = last
            last.next = None
        return head