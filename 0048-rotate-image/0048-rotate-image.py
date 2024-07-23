class Solution:
    def rotateArray(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        start, stop = 0 , len(matrix) - 1

        while start < stop:
            # print(f"start={start}, stop={stop}")
            for i in range(0, stop - start):
                temp = []
                temp.append(matrix[start][start+i])
                temp.append(matrix[start+i][stop])
                temp.append(matrix[stop][stop-i])
                temp.append(matrix[stop-i][start])
                # print(temp)
                matrix[start+i][stop] = temp[0]
                matrix[stop][stop-i] = temp[1]
                matrix[stop-i][start] = temp[2]
                matrix[start][start+i] = temp[3]
            start+=1
            stop-=1

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        start, stop = 0 , len(matrix) - 1

        while start < stop:
            # print(f"start={start}, stop={stop}")
            for i in range(0, stop - start):
                temp = matrix[start][start+i]
                # print(temp)
                matrix[start][start+i] = matrix[stop-i][start]
                matrix[stop-i][start] = matrix[stop][stop-i]
                matrix[stop][stop-i] = matrix[start+i][stop]
                matrix[start+i][stop] = temp
                
                
                
            start+=1
            stop-=1
    