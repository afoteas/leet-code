"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        def md(root: 'Node', level:int) -> int:
            levels = []
            if root.children:
                for c in root.children:
                    levels.append(md(c,level+1))
                return max(levels)
            else:
                return level+1
        
        levels = []
        if not root:
            return 0
        if root.children:
            for c in root.children:
                levels.append(md(c,1))
            return max(levels)
        else:
            return 1
        
        