class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        l = 0
        r = 0
        ret = []
        if len(set(words)) == 1:
            words = [''.join(words)]
        m = len(s)
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
                    l+=min(n,len(set(words)))-1
            l+=1
        return ret
                


