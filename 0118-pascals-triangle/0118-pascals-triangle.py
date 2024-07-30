class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1],[1,1]]
        else:
            ret = [[1]]
            for i in range(3,numRows+2):
                temp = []
                for j in range(i-1):
                    if j == 0 or j == i-2:
                        temp.append(1)
                    else:
                        temp.append(ret[-1][j-1]+ret[-1][j])
                ret.append(temp)
            return ret
                    

        