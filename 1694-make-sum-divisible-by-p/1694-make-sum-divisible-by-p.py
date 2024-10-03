class Solution:
    def minSubarraySlow(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        if total < p:
            return -1
        remaining = total % p
        if not remaining:
            return 0
        counter = 1
        while remaining+p*counter <total:
            counter+=1
        for n in range(len(nums)):
            for i in range(len(nums)-n):
                for j in range(counter):
                    tmp = sum(nums[i:i+n+1])
                    if tmp == remaining+p*j and tmp < total:
                        return n+1
        return -1

    def minSubarrayNaah(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        if total < p:
            return -1
        remaining = total % p
        if not remaining:
            return 0
        counter = 1
        while remaining+p*counter <total:
            counter+=1
        for n in range(1,len(nums)+1):
            for i in range(len(nums)-n+1):
                tmp = sum(nums[i:i+n])
                if tmp < total:
                    for j in range(counter):
                        if tmp == remaining+p*j:
                            return n
        return -1

    def minSubarray(self, nums: List[int], p: int) -> int:
        totalSum = sum(nums)
        rem = totalSum % p

        if rem == 0:
            return 0

        prefixMod = {0: -1}
        prefixSum = 0
        minLength = len(nums)

        for i, num in enumerate(nums):
            prefixSum += num
            currentMod = prefixSum % p
            targetMod = (currentMod - rem + p) % p

            if targetMod in prefixMod:
                minLength = min(minLength, i - prefixMod[targetMod])

            prefixMod[currentMod] = i

        return minLength if minLength < len(nums) else -1  