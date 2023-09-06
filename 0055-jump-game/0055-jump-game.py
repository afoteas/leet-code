class Solution:
    def canJumpTime(self, nums: List[int]) -> bool:
        i = 0
        l = len(nums)
        j = []
        if l == 1:
            return True
        while i < l-1:
            if len(j) == 0 or j[-1] > 0:
                j.append(nums[i])
                i = sum(j)
            elif j[0] == 0:
                return False       
            else:
                j.pop()
                j[-1] -= 1
                i = sum(j)
        return True    

    def canJumpWorse(self, nums: List[int]) -> bool:
        z = {}
        i = -1
        l = len(nums)
        print(f"l={l}")
        while i < l-1:
            i += 1
            tl = 0
            if nums[i] == 0:
                ti = i
                tl += 1
                i += 1
                while i < l and nums[i] == 0 :
                    tl += 1
                    i += 1
                z[ti]=tl
                ti = 0

        print(f"z={z}")
        return False      


    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        i = 0
        j = i
        for i in range(len(nums)):
            if j > i+nums[i]:
                pass
            else:
                j = i+nums[i]
            i+=1
            if i > j:
                break
            if j >= len(nums)-1:
                return True
        return False

