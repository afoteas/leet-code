class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        digitList=["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        ret = list(digitList[int(digits[0])-2])
        for digit in digits[1:]:
            print("here1")
            retret = []
            for char in digitList[int(digit)-2]:
                print("here2")
                
                for re in ret:
                    print(f"here3, re= {re}")
                    retret.append(f"{re}{char}")
            ret = retret
        return ret
        