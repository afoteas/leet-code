# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        matrix = [[-1 for _ in range(n)] for _ in range(m)]
        m_min, m_max = 0, n-1
        n_min, n_max = 0, m-1
        while head:
            for i in range(m_min, m_max+1):
                if head:
                    matrix[n_min][i]=head.val
                    head = head.next
                else:
                    break
            n_min+=1
            for i in range(n_min, n_max+1):
                if head:
                    matrix[i][m_max]=head.val
                    head = head.next
                else:
                    break
            m_max-=1
            for i in range(m_max, m_min-1, -1):
                if head:
                    matrix[n_max][i]=head.val
                    head = head.next
                else:
                    break
            n_max-=1
            for i in range(n_max, n_min-1,-1):
                if head:
                    matrix[i][m_min]=head.val
                    head = head.next
                else:
                    break
            m_min+=1

        return matrix
        