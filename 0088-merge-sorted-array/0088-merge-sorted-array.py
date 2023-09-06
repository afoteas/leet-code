class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = 0
        while i < m:
            j=0
            while j < n:
                if nums1[i] >= nums2[j]:
                    nums1.insert(i,nums2.pop(j))
                    nums1.pop()
                    m += 1
                    n -= 1
                j += 1
            i += 1   
        while n > 0:
            nums1.insert(i,nums2.pop(0))
            nums1.pop()
            i += 1
            n -= 1