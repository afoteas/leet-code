class Solution:
    def canConstructOne(self, ransomNote: str, magazine: str) -> bool:
        lm = list(magazine)
        for l in ransomNote:
            if l in lm:
                lm.remove(l)
            else:
                return False
        return True

    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for l in ransomNote:
            if l in magazine:
                magazine = magazine.replace(l,"",1)
            else:
                return False
        return True

    def canConstructFast(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        for i in set(ransomNote):
            if magazine.count(i) < ransomNote.count(i):
                return False
        return True        