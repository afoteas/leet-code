class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        mapa = {}
        ss=s.split(" ")
        if len(ss) != len(pattern):
            return False
        for i in range(0,len(pattern)):
            if pattern[i] in mapa:
                if mapa[pattern[i]] != ss[i]:
                    return False
            else:
                if ss[i] in mapa.values():
                    return False
                mapa[pattern[i]] = ss[i]
        return True


        