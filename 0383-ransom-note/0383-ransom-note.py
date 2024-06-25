class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        lm = list(magazine)
        for l in ransomNote:
            if l in lm:
                lm.remove(l)
            else:
                return False
        return True

        