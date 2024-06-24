# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sizer(self, leaf:TreeNode, pos:int) -> int:
        l = pos
        r = pos
        if leaf.left:
            l = self.sizer(leaf.left, pos+1)
        if leaf.right:
            r = self.sizer(leaf.right, pos+1)
        return max(l,r)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root:
            return self.sizer(root,1)
        else:
            return 0
        