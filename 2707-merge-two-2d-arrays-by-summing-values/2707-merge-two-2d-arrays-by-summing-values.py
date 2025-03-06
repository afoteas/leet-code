class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        merged_array = nums1+nums2
        merged_array.sort()
        ret = []
        for n in merged_array:
            if not ret:
                ret.append(n)
            else:
                if ret[-1][0] == n[0]:
                    ret[-1][1] += n[1]
                else:
                    ret.append(n)

        return ret




        