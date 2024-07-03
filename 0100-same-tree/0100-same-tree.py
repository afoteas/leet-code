# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (not p) and (not q):
            return True
        elif (not p) and q:
            return False
        elif (not q) and p:
            return False
        elif p.val != q.val:
            return False

        istl = self.isSameTree(p.left, q.left)
        istr = self.isSameTree(p.right, q.right)
        if istl and istr:
            return True
        else:
            return False
            
        # if p.left and q.left and p.right and q.right:
        #     istl = self.isSameTree(p.left, q.left)
        #     istr = self.isSameTree(p.right, q.right)
        #     if istl and istr:
        #         return True
        #     else:
        #         return False
        # elif p.left and q.left:
        #     return self.isSameTree(p.left, q.left)
        # elif p.right and q.right:
        #     return self.isSameTree(p.right, q.right)
        # elif p.left or q.left or p.right or q.right:
        #     return False
        # else:
        #     return True

            


        