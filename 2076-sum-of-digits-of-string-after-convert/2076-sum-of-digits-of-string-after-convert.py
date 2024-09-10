class Solution:
    def getLucky(self, s: str, k: int) -> int:
        def convert(s: str) -> int:
            ret = ""
            for c in s:
                ret+=str(ord(c)-96)
            return int(ret)
        
        def transform(num:int) -> int:
            return sum([int(digit) for digit in str(num)])
        
        ret = convert(s)
        print(ret)
        for i in range(k):
            ret = transform(ret)
        
        return ret
        




        