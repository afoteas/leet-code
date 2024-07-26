class Solution:
    def kSmallestPairsAndreas(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        i1=0
        i2=0
        j1=0
        j2=0
        l1=len(nums1)
        l2=len(nums2)
        m=1
        ret = [[nums1[0],nums2[0]]]
        while i1 < l1-1 and i2 < l2-1 and m < k:
            if nums1[i1+1] < nums2[i2+1]:
                while m < k:
                    if (nums1[j1] + nums2[i2+1]) <= (nums1[i1+1] + nums2[i2]):
                        ret.append([nums1[j1], nums2[i2+1]])
                        j1+=1
                        m+=1
                    else:
                        j1=0
                        ret.append([nums1[i1+1], nums2[i2]])
                        i1+=1
                        break
            else:
                while m < k:
                    if (nums1[i1+1] + nums2[j2]) <= (nums1[i1] + nums2[i2+1]):
                        ret.append([nums1[i1+1], nums2[j2]])
                        j2+=1
                        m+=1
                    else:
                        j2=0
                        ret.append([nums1[i1], nums2[i2+1]])
                        i2+=1  
                        break
            m+=1
        return ret

    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        result = []
        heap = []
        
        # Push the sums of each element in nums1 with the first element in nums2 into the heap
        for num in nums1:
            heapq.heappush(heap, (num + nums2[0], 0))
        
        # Pop the smallest pair from the heap and add it to the result list
        while k > 0 and heap:
            nums_sum, index = heapq.heappop(heap)
            result.append([nums_sum - nums2[index], nums2[index]])
            
            # If there are more elements in nums2, push the sum of the current element in nums1
            # with the next element in nums2 into the heap
            if index + 1 < len(nums2):
                heapq.heappush(heap, (nums_sum - nums2[index] + nums2[index + 1], index + 1))
            
            # Decrease the number of pairs to be returned
            k -= 1
        
        return result
        