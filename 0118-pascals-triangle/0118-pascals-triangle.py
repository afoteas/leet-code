class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        else:
            ret = [[1]]
            for i in range(2,numRows+1):
                temp = []
                for j in range(i):
                    if j == 0 or j == i-1:
                        temp.append(1)
                    else:
                        temp.append(ret[-1][j-1]+ret[-1][j])
                ret.append(temp)
            return ret
                    

        