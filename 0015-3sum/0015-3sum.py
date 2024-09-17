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


    def threeSumBetter(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()
        n=len(nums)
        for i in range(n-1):
            a = nums[i]
            if a > 0:
                break
            if i > 0 and a == nums[i-1]:
                continue
            j=i+1
            k=n-1
            while j<k:
                b,c = nums[j],nums[k]
                cont = False
                if j > i+1 and nums[j-1] == b:
                    j+=1
                    cont = True
                if k < n-1 and c == nums[k+1]:
                    k-=1
                    cont = True
                if cont: continue
                # if a + b > 0:
                #     break
                target = a + b + c
                if target == 0:
                    ret.append([a, b, c])
                    k-=1
                    j+=1
                elif target>0:
                    k-=1
                else:
                    j+=1      
        return ret

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i, a in enumerate(nums):
            if a > 0:
                break

            if i > 0 and a == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1
            while l < r:
                b, c = nums[l], nums[r]
                threeSum = a + b + c
                if threeSum > 0:
                    r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    res.append([a, b, c])
                    l += 1
                    r -= 1
                    # while nums[r] == nums[r + 1] and l < r:
                    #     r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                        
        return res      




        