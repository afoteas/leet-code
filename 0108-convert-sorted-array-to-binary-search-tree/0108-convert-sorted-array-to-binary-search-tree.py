# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
   
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        length = len(nums)
        if not length:
            return None
        median = length // 2
        return TreeNode(nums[median], self.sortedArrayToBST(nums[:median]), self.sortedArrayToBST(nums[median+1:]))