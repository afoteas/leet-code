import heapq
import random
class Solution:
    def findKthLargestSorted(self, nums: List[int], k: int) -> int:
        return sorted(nums,reverse=True)[k-1]

    def findKthLargestList(self, nums: List[int], k: int) -> int:
        kthList = nums[:k]
        kthList.sort(reverse=True)
        for num in nums[k:]:
            if kthList[-1] < num:
                kthList[-1] = num
                kthList.sort(reverse=True)
        return kthList[-1]


    def findKthLargestHeap(self, nums: List[int], k: int) -> int:
        heap = nums[:k]
        heapq.heapify(heap)
        
        for num in nums[k:]:
            if num > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, num)
        
        return heap[0]

    
    def findKthLargestRandom(self, nums: List[int], k: int) -> int:
        pivot = random.choice(nums)
        lows, highs = [], []
        for el in nums:
            if el < pivot:
                lows.append(el)
            if el > pivot:
                highs.append(el)

        if k <= len(highs):
            return self.findKthLargest(highs, k)
        elif len(nums) - k + 1 <= len(lows):
            return self.findKthLargest(lows, len(lows) - len(nums) + k)
        else:
            return pivot

    def heapify(self, arr, N, i):
        largest = i  # Initialize largest as root
        l = 2 * i + 1     # left = 2*i + 1
        r = 2 * i + 2     # right = 2*i + 2

        # See if left child of root exists and is
        # greater than root
        if l < N and arr[largest] < arr[l]:
            largest = l

        # See if right child of root exists and is
        # greater than root
        if r < N and arr[largest] < arr[r]:
            largest = r

        # Change root, if needed
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]  # swap

            # Heapify the root.
            self.heapify(arr, N, largest)

    # The main function to sort an array of given size


    def findKthLargest(self, nums: List[int], k: int) -> int:
        N = len(nums)

        # Build a maxheap.
        for i in range(N//2 - 1, -1, -1):
            self.heapify(nums, N, i)
        added = 0
        # One by one extract elements
        for i in range(N-1, 0, -1):
            nums[i], nums[0] = nums[0], nums[i]  # swap
            added +=1
            if added == k:
                break
            self.heapify(nums, i, 0)
        return nums[len(nums)-k]

