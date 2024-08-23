class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        numDict = {}
        for num in nums:
            if num in numDict:
                if numDict[num] == 2:
                    del numDict[num]
                else:
                    numDict[num]=2
            else:
                numDict[num]=1
        return list(numDict.keys())[0]
                    
        