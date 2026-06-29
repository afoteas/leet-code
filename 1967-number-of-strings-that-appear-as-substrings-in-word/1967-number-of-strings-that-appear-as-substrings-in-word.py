class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ret = 0
        for p in patterns:
            if p in word:
                ret+=1
        return ret
        