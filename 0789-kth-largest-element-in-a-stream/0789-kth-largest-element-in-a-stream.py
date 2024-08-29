import bisect

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.allNums = sorted(nums)
        # self.allNums.sort()
        self.k = k

        

    def add(self, val: int) -> int:
        bisect.insort(self.allNums, val)
        return self.allNums[-self.k]


        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)