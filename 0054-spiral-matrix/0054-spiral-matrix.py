class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        retList = []
        size_v = len(matrix)
        size_h = len(matrix[0])
        depth_v = size_v // 2
        depth_h = size_h // 2
        for d in range(max([depth_v,depth_h])):
            if d < depth_v and d < depth_h:
                i = d
                # print("one")
                for j in range(d, size_h-d):
                    retList.append(matrix[i][j])
                    # print(matrix[i][j])
                j = size_h - d  - 1
                # print("two")
                for i in range(d+1, size_v-d-1):
                    retList.append(matrix[i][j])
                    # print(matrix[i][j])
                i = size_v-d-1
                # print("three")
                for j in range(size_h-d-1,d-1,-1):
                    retList.append(matrix[i][j])
                    # print(matrix[i][j])
                j = d
                # print(f"four, d={d}")
                for i in range(size_v-d-2,d, -1):
                    retList.append(matrix[i][j])
                    # print(matrix[i][j])
            elif d == depth_v and not size_v == 2:
                i = d
                # print("extra1")
                for j in range(d, size_h-d):
                    retList.append(matrix[i][j])
                    # print(matrix[i][j])
                break
            elif d >= depth_h and not size_h == 2:
                # print(f"extra2, size_v={size_v}, size_h={size_h}")
                j = size_h - d  - 1
                for i in range(d, size_v-d):
                    retList.append(matrix[i][j])
                    # print(matrix[i][j])
                break
        if size_v == size_h and size_v%2:
            retList.append(matrix[depth_v][depth_v])
            
        return retList
                
        