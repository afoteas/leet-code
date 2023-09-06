class Solution:
    def hIndexOk(self, citations: List[int]) -> int:
        citations.sort()
        l = len(citations)
        lt = l-1
        while lt >= 0:
            if citations[lt] > l-lt:
                lt -=1
            elif citations[lt] == l-lt:
                return l-lt
            else:
                return l-lt-1
        return min(len(citations),citations[0])        


    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        l = len(citations)
        if citations[l-1] == 0:
            return 0
        p = 1
        tl = l >> 1
        ti  = -1
        while tl != ti:
            ti = tl
            p += 1
            if citations[tl] > l - tl:
                if tl - l >> p > 0:
                    tl -= l >> p
                else:
                    break    
            else:
                if tl + l >> p < l:
                    tl += l >> p
                else:
                    break
        while tl >= 0:
            if citations[tl] > l-tl:
                tl -=1
            elif citations[tl] == l-tl:
                return l-tl
            else:
                return l-tl-1
        return min(l,citations[0])     

    def hIndexBad(self, citations: List[int]) -> int:
        hi = {}
        for i in citations:
            for j in range (i + 1):
                if j in hi:
                    hi[j] += 1
                else:
                     hi[j] = 1   
        if len(hi) == 1:
            return 0
        for i in range(max(citations), -1, -1):
            if hi[i] - i >= 0:
                return i 

        return 0        

    def hIndexDict(self, citations: List[int]) -> int:
        hi = {}
        h = 0
        for i in citations:
            for j in range (h, i + 1):
                if j in hi:
                    hi[j] += 1
                else:
                     hi[j] = 1
                if hi[j] == j:
                    h = j        
        return h               


    def hIndexArray(self, citations: List[int]) -> int:
        hi = [0] * 5000
        h = 0
        for i in citations:
            for j in range (h, i + 1):
                hi[j] += 1
                if hi[j] == j:
                    h = j        
        return h  