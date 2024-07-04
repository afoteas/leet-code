# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSumParent(self, root: Optional[TreeNode], targetSum: int, parentSum: int) -> bool:
        print(parentSum)
        if (not root.left) and (not root.right):
            return parentSum + root.val == targetSum
        if root.left:
            ret = self.hasPathSumParent(root.left, targetSum, parentSum+root.val)
            if ret:
                return True
        if root.right:
            ret = self.hasPathSumParent(root.right, targetSum, parentSum+root.val)
            if ret:
                return True


    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        if root.left:
            print("left")
            ret = self.hasPathSumParent(root.left, targetSum, root.val)
            if ret:
                return True
        if root.right:
            print("right")
            ret = self.hasPathSumParent(root.right, targetSum, root.val)
            if ret:
                return True
        if (not root.right) and (not root.left):
            return root.val == targetSum

        