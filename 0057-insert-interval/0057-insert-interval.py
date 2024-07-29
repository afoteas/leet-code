class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        startIndex = -1
        endIndex = -1
        i=0
        for interval in intervals:
            if newInterval[0] <= interval[1] and startIndex==-1:
                print(f"here:{i},interval={interval}")
                startIndex=i
            if newInterval[1] < interval[0]:
                print("one")
                endIndex = i-1
                # endIndex=max(i-1,startIndex)
                break
            if newInterval[1] <= interval[1]:
                endIndex=i       
                print("two")     
                break
            i+=1
        if intervals[-1][1] < newInterval[1] and endIndex==-1 and startIndex != -1:
            print("entered")
            endIndex = len(intervals) - 1


        print(f"startIndex={startIndex},endIndex={endIndex}")
        if endIndex != -1 and endIndex < startIndex:
            intervals.insert(startIndex, newInterval)
        elif intervals[0][0] > newInterval[1] and endIndex==0 and startIndex == 0:
            intervals.insert(0, newInterval)
        elif startIndex==0 and endIndex==-1:
            intervals.insert(0, newInterval)
        elif startIndex==-1 and endIndex==-1:
            intervals.append(newInterval)
        elif startIndex==endIndex:
            intervals[startIndex]=[min(intervals[startIndex][0],newInterval[0]), max(intervals[startIndex][1],newInterval[1])]

        else:
            end = -1
        
            for i in range(endIndex,startIndex,-1):
                end = max(end, intervals[i][1])
                intervals.pop(i)
            intervals[startIndex]=[min(intervals[startIndex][0],newInterval[0]), max(end,newInterval[1])]
        
        return intervals
        