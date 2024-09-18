# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        retVal = 0
        if not root:
            return retVal
        bfsList = [[root,1]]
        while bfsList:
            tmp = bfsList.pop(0)
            if (not tmp[0].left) and (not tmp[0].right):
                retval = tmp[1]
                break
            if tmp[0].left:
                bfsList.append([tmp[0].left,tmp[1]+1])
            if tmp[0].right:
                bfsList.append([tmp[0].right,tmp[1]+1])
            retval = tmp[1]+1
        return retval
        





        