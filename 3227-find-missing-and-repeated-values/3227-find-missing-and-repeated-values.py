class Solution:
    def findMissingAndRepeatedValuesSlow(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        ret = [i for i in range(1, n*n + 1)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] in ret:
                    ret.remove(grid[i][j])
                else:
                    ret.insert(0, grid[i][j])
        return ret

    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        nums = [1 for i in range(1, n*n + 1)]
        a = None
        b = None
        for i in range(n):
            for j in range(n):
                if nums[grid[i][j]-1]:
                    nums[grid[i][j]-1] -= 1
                else:
                    a = grid[i][j]
        print(nums)
        b = nums.index(1) + 1
        return [a, b]
        