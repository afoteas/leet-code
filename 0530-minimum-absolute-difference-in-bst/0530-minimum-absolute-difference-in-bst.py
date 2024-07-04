# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        minVal = 100000

        if not root:
            return minVal

        
        if root.left:
            curr = root.left
            while curr.right:
                curr=curr.right
            maxLeft = curr.val
            minVal = root.val - maxLeft

        if root.right:
            curr = root.right
            while curr.left:
                curr=curr.left
            minRight = curr.val
            minVal = min(minRight - root.val, minVal)
        
        if minVal == 1:
            return 1
        
        return min([self.getMinimumDifference(root.left), self.getMinimumDifference(root.right), minVal])

        