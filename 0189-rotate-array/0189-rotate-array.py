class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # l = k % len(nums)
        # for i in range(l):
        #     nums.insert(0,nums.pop())
        l = k % len(nums)
        front = nums[-l:]
        back = nums[0:-l]
        nums.clear()
        nums.extend(front)
        nums.extend(back)
