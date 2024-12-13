class Solution:
    def gcdOfStringsSlow(self, str1: str, str2: str) -> str:
        s = str1 if len(str1) < len(str2) else str2
        t = ""
        ret = ""
        for c in s:
            t +=c
            if str1.replace(t,"") == "" and str2.replace(t,"") == "":
                ret = t
        return ret

    def gcdOfStrings(self, str1: str, str2: str) -> str:

        if str1 + str2 != str2 + str1:
            return ""


        def gcd(a, b):
            while b:
                a,b = b,a%b
            return a
        
        gcd_length = gcd(len(str1), len(str2))

        return str1[:gcd_length]
        