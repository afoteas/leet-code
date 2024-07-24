# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.m=0
        self.ret=0
        def mSmall(root):
            print("entered")
            if root.left:
                print("root.left")
                mSmall(root.left)
            if self.m == k:
                print("m == k")
                return
            self.m+=1
            self.ret = root.val
            if root.right:
                print("root.right")
                mSmall(root.right)
        mSmall(root)
        return self.ret
                

        