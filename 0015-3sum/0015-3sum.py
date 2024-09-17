class Solution:
    def threeSumTimeout(self, nums: List[int]) -> List[List[int]]:
        ret = set()
        for i in range(0,len(nums)):
            for j in range(i+1, len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        ret.add(tuple(sorted((nums[i], nums[j], nums[k]))))
        return list(ret)

    def threeSumNot(self, nums: List[int]) -> List[List[int]]:
        oneDict = defaultdict(list)
        for i in range(len(nums)):
            oneDict[nums[i]].append(i)
        ret = set()

        # twoDict = defaultdict(list)
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                t = -nums[i]-nums[j]
                if t in oneDict:
                    for k in oneDict[t]:
                        if not k in [i,j]:
                            ret.add(tuple(sorted((nums[i], nums[j], t))))
        
        return list(ret)


    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()
        n=len(nums)
        for i in range(n-1):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j=i+1
            k=n-1
            while j<k:
                if j > i+1 and nums[j-1] == nums[j]:
                    j+=1
                    if k < n-1 and nums[k] == nums[k+1]:
                        k-=1
                    continue
                if k < n-1 and nums[k] == nums[k+1]:
                    k-=1
                    if j > i+1 and nums[j-1] == nums[j]:
                        j+=1
                    continue
                target = nums[j] + nums[k] + nums[i]
                if target == 0:
                    ret.append([nums[i], nums[j], nums[k]])
                    k-=1
                    j+=1
                elif target>0:
                    k-=1
                else:
                    j+=1      
        return ret
            




        