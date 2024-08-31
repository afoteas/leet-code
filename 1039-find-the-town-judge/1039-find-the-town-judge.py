class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if not trust:
            if n>1:
                return -1
            else:
                return 1
        trusts=defaultdict(int)
        for t in trust:
            trusts[t[1]]+=1
        
        j = max(trusts, key=trusts.get)
        for t in trust:
            if t[0] == j:
                return -1
        if trusts[j]==n-1:
            return j
        else:
            return -1
        