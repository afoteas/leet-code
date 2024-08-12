class Solution:
    def numOfMinutesSlow(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        maxI = 0
        i = 0
        tt = 0
        j=0
        while i < n:
            tt+=informTime[j]
            if manager[j] == -1:
                maxI = max(tt, maxI)
                i+=1
                j=i
                tt=0
            else:
                j=manager[j]
        
        return maxI


    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        def find(i):
            if manager[i] != -1:
                informTime[i] += find(manager[i])
                manager[i] = -1
            return informTime[i]

        return max(map(find, range(n)))


        