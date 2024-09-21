class Solution:
    def lexicalOrderGood(self, n: int) -> List[int]:
        ans = []
        def dfs(i):
            if i > n:
                return
            ans.append(i)
            for j in range(0,10):
                x=10*i+j
                if x > n:
                    break
                dfs(x)
        
        for i in range(1,10):
            if i>n:
                break
            dfs(i)
        return ans

    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        curr = 1


        while len(ans) < n:
            ans.append(curr)

            #go to next level
            if curr * 10 <= n:
                curr *= 10

            # go next in same level
            else:
                while curr % 10 == 9 or curr == n:
                    curr //= 10

                curr += 1
        
        return ans