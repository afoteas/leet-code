# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        self.complete = 0
        def isComplete(root):
            if not root:
                return
            else:
                self.complete+=1
                isComplete(root.left)
                isComplete(root.right)
        
        isComplete(root)
        return self.complete
        