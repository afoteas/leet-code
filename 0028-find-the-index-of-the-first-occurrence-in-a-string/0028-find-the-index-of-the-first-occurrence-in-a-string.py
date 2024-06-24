class Solution:
    def strStr2(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

    def strStr(self, haystack: str, needle: str) -> int:
        hl=len(haystack)
        nl=len(needle)
        for i in range(0,hl-nl+1):
            if haystack[i:i+nl] == needle:
                return i
        return -1