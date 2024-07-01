class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        inter = [intervals[0]]
        for i in intervals:
            if i[0] <= inter[-1][1]:
                if i[1] <= inter[-1][1]:
                    continue
                inter[-1] = [inter[-1][0],i[1]]
            else:
                inter.append(i)
        return inter


        