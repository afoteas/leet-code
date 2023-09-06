class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        elements = {}
        for num in nums:
            if num in elements:
                elements[num] += 1
            else:
                elements[num] = 1
        return max(elements, key=elements.get)        
