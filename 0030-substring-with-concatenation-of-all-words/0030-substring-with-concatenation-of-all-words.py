class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        m = len(s)
        n = len(words[0])
        l = 0
        r = 0
        ret = []
        # if m == len(words):
        #     return [0]
        if len(set(words)) == 1:
            words = [''.join(words)]
        n = len(words[0])
        while l + n <= m:
            if s[l:l+n] in words:
                tmp = list(words)
                tmp.remove(s[l:l+n])
                r=n
                while len(tmp) > 0:
                    if s[l+r:l+r+n] in tmp:
                        tmp.remove(s[l+r:l+r+n])
                        r+=n
                    else:
                        break
                if len(tmp) == 0:
                    ret.append(l)
            l+=1
        return ret
                


