class Solution:
    def makeGood(self, s: str) -> str:

        if len(s) < 2:
            return s
        ret = []
        i = 0
        last = "?"
        l = len(s)
        while i < l:
            if ret and abs(ord(s[i]) - ord(ret[-1])) == 32:
                ret.pop()
            else:
                ret.append(s[i])
            i+=1
        return "".join(ret)