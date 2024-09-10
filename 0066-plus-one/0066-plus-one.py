class Solution:
    def plusOneString(self, digits: List[int]) -> List[int]:
        return [int(x) for x in str(int("".join([str(x) for x in digits]))+1)]
    
    
    def plusOne(self, digits: List[int]) -> List[int]:
        r = 1
        for i in range(len(digits)-1,-1,-1):
            t = digits[i]+r
            digits[i]=t%10
            r = 1 if t > 9 else 0
        if r:
            digits.insert(0,1)
        return digits

    

        