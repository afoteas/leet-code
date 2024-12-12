class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        verticals = set()
        for i in range(m):
            new = [index for index, value in enumerate(matrix[i]) if value == 0 and index not in verticals]
            verticals.update(new)
            for ii in range(0,i):
                for jj in new:
                    matrix[ii][jj] = 0
            if 0 in matrix[i]:
                matrix[i] = [0]*n
            else:
                for jj in verticals:
                    matrix[i][jj] = 0

        