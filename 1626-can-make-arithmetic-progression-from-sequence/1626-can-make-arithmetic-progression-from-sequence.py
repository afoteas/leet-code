class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        sortedArray = sorted(arr)
        lenArray = len(arr)
        if len == 2:
            return True
        diff = sortedArray[1] - sortedArray[0]
        for i in range(2, lenArray):
            if sortedArray[i] - sortedArray[i-1] != diff:
                return False
        return True
        