# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        levels = []
        def kfun(node: Optional[TreeNode], level:int):
            if len(levels) == level:
                levels.append(node.val)
            else:
                levels[level] += node.val

            if node.left:
                kfun(node.left, level+1)
            if node.right:
                kfun(node.right, level+1)
            
        kfun(root, 0)
        if len(levels) < k:
            return -1
        levels.sort(reverse = True)
        return levels[k-1]
        