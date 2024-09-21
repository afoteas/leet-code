class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
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
        