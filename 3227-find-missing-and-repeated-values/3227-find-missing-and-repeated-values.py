class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        ret = [i for i in range(1, n*n + 1)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] in ret:
                    ret.remove(grid[i][j])
                else:
                    ret.insert(0,grid[i][j])
        return ret

        