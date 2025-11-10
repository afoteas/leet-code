class Solution:
    def minOperationsSlow(self, nums: List[int]) -> int:
        ret = 0
        i = 0
        l = len(nums)
        z = [e for e, val in enumerate(nums) if val == 0]
        # print(z)
        while i < l:
            # print(f"zeros_before={z}")
            if nums[i] == 0:
                i += 1
                continue
            if not len(z):
                j = l-1
            else:
                for x, y in enumerate(z):
                    if y > i:
                        # print("break")
                        break
                if y > i:
                    j = y
                    z = z[x:]
                else:
                    j = l-1
                    z = []
            # print(f"zeros_after={z}")
            # print(f"i={i}, j={j}")


            if i == j:
                sub = nums[i]
            else:
                sub = min(nums[i:j])
            op = False
            for k in range(i,j+1):
                # print(f"sub={sub}")
                if nums[k] == sub:
                    nums[k] = 0
                    z.append(k)
                    # print(f"op set to True for sub={sub}, i={i} and j={j}")
                    op = True
            z.sort()
            if op:
                ret += 1
        return ret

    def minOperations(self, nums):
        stack = [0] * (len(nums) + 1)
        top = 0
        ans = 0

        for num in nums:
            while stack[top] > num:
                top -= 1
                ans += 1
            if stack[top] != num:
                top += 1
                stack[top] = num

        return ans + top
                


        