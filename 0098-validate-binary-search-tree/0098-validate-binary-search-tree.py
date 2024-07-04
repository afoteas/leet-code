# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        if not root.left and not root.right:
            return True
        retL=True
        retR=True
        if root.left:
            pointer = root.left
            maxLeft=pointer.val
            while pointer:
                maxLeft=pointer.val
                pointer = pointer.right
            if maxLeft>=root.val:
                return False
            retL = self.isValidBST(root.left)
        if root.right:
            pointer = root.right
            minRight=pointer.val
            while pointer:
                minRight=pointer.val
                pointer = pointer.left
            if minRight<=root.val:
                return False
            retR = self.isValidBST(root.right)
        return retL and retR  
            
        