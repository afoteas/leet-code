class Solution:
    def reverseWords(self, s: str) -> str:
        ss = s.strip().split()
        ss.reverse()
        return " ".join(ss)

        