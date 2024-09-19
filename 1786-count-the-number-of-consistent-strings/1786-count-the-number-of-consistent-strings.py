class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ret = 0
        for w in words:
            for c in w:
                if not c in allowed:
                    break
            else:
                ret+=1
        return ret
        