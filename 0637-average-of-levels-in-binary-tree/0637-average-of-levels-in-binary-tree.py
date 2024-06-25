# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self,levels={}):
        self.levels = {}

    def traverser(self, leaf: Optional[TreeNode], level:int) -> None:
        if level in self.levels:
            self.levels[level] = [self.levels[level][0]+leaf.val, self.levels[level][1]+1]
        else:
            self.levels[level] =[leaf.val,1]
        if leaf.left:
            self.traverser(leaf.left,level+1)
        if leaf.right:
            self.traverser(leaf.right,level+1)            

    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        self.traverser(root,0)
        res = []
        for value in self.levels.values():
            res.append(value[0]/value[1])
        return res




        