# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        retList = []
        def it(root: Optional[TreeNode], retList:List[int]):
            if root:
                it(root.left, retList)
                retList.append(root.val)
                it(root.right,retList)
        it(root, retList)
        return retList
        

        