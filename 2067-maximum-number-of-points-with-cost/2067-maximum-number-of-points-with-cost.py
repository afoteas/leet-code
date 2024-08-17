import operator
# index, value = max(enumerate(my_list), key=operator.itemgetter(1))
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        rows, cols = len(points), len(points[0])
        for i in range(1,rows):
            right = [0]*cols
            right[-1] = points[i-1][-1]
            for j in range(cols-2,-1,-1):
                right[j]=max(right[j+1]-1, points[i-1][j])
            left = points[i-1][0]
            points[i][0] = max(left,right[0]) + points[i][0]
            for j in range(1, cols):
                left = max(left-1, points[i-1][j])
                points[i][j]=max(left,right[j])+points[i][j]
        return max(points[-1])
    
    def maxPointsSlow(self, points: List[List[int]]) -> int:
        rows, cols = len(points), len(points[0])
        multiadd = lambda a,b: map(operator.add, a,b)
        @cache
        def mask(pos:int) -> List[int]:
            return [-abs(i - pos) for i in range(cols)]

        for i in range(1,rows):
            for j in range(cols):
                points[i][j]=max(multiadd(points[i-1], mask(j)))+points[i][j]
        return max(points[-1])

                


