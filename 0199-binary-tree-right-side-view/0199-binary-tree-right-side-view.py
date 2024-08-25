# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ret = []
        levels = {}
        def addLevels(node:Optional[TreeNode],level:int):
            if level in levels:
                levels[level].append(node.val)
            else:
                levels[level] = [node.val]
            if node.left:
                addLevels(node.left,level+1)
            if node.right:
                addLevels(node.right,level+1)
        addLevels(root,0)
        for values in levels.values():
            ret.append(values[-1])
        return ret
        



        