from collections import Counter
class Solution:
    def findSubstringMine(self, s: str, words: List[str]) -> List[int]:
        l = 0
        r = 0
        ret = []
        if len(set(words)) == 1:
            words = [''.join(words)]
        m = len(s)
        n = len(words[0])
        if n*len(words)>m:
            return ret
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
                
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        l = 0
        r = 0
        ret = []
        if len(set(words)) == 1:
            words = [''.join(words)]
        m = len(s)
        n = len(words[0])
        t = n*len(words)
        if t>m:
            return ret
        word_count = Counter(words) 
        while l + n <= m:
            if s[l:l+n] in words:
                seen_words = Counter()
                seen_words[s[l:l+n]] += 1
                r=n
                while seen_words != word_count:
                    if s[l+r:l+r+n] in word_count:
                        seen_words[s[l+r:l+r+n]] += 1
                        if seen_words[s[l+r:l+r+n]] > word_count[s[l+r:l+r+n]]:
                            break
                        r+=n
                    else:
                        break
                if seen_words == word_count:
                    ret.append(l)
            l+=1
        return ret

