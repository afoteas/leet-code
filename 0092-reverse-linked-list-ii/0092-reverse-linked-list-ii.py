# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right or not head:
            return head
        else:
            lp = None
            rn = None
            re = []
            i = 1
            temp = head
            while temp:
                if lp or left == 1:
                    re.append(temp)
                if i+1 == left:
                    lp = temp
                elif i == (right+1):
                    rn = temp
                    re.pop()
                    break
                i+=1
                temp = temp.next
            
            if not lp:
                head = re.pop()
                temp = head
            else:
                temp = lp
            while re:
                temp.next = re.pop()
                temp = temp.next
            temp.next = rn
            return head

                


                

        