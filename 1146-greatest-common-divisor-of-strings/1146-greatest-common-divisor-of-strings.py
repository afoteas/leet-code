class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        s = str1 if len(str1) < len(str2) else str2
        t = ""
        ret = ""
        for c in s:
            t +=c
            if str1.replace(t,"") == "" and str2.replace(t,"") == "":
                ret = t
        return ret

        