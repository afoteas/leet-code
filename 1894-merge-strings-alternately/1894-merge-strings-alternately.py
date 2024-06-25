class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ret=""
        stop=min(len(word1),len(word2))
        for i in range(0,stop):
            ret+=word1[i]
            ret+=word2[i]
        ret+=word1[stop:]
        ret+=word2[stop:]
        return ret