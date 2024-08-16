class Solution:
    def toLowerCase(self, s: str) -> str:
        ret = ""
        for c in s:
            if ord(c) < 91 and ord(c)>64:
                ret+=chr(ord(c)+32)
            else:
                ret+=c
        return ret

        