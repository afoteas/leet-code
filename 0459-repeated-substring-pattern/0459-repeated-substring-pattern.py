class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        count = len(s)
        if count < 2:
            return False
        stop = count//2
        test = ""
        i = 0
        for c in s:
            if i > stop:
                print(f"i={i}, stop = {stop}")
                return False
            test+=c
            if s.count(test)*len(test) == count:
                if len(test) == count :
                    return False
                print(f"len(test)={len(test)}, count = {count}, s.count(test) = {s.count(test)}")
                return True
            i+=1
        return False


        