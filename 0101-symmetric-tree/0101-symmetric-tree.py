# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def check(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if (not root1) and (not root2):
            return True
        if (not root1) or (not root2):
            return False
        if root1.val==root2.val:
            return self.check(root1.left, root2.right) and self.check(root1.right, root2.left)
        return False

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.check(root.left, root.right)

        
        