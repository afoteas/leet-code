class Solution:
    def repeatedSubstringPatternStupid(self, s: str) -> bool:
        count = len(s)
        if count < 2:
            return False
        stop = count//2
        test = ""
        i = 0
        for c in s:
            if i > stop:
                return False
            test+=c
            if s.count(test)*len(test) == count:
                if len(test) == count :
                    return False
                return True
            i+=1
        return False


    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in(s+s)[1:-1]
        