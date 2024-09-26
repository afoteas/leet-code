class Solution:
    def findKthNumberSlow(self, n: int, k: int) -> int:
        self.count=0
        ret=-1
        def dfs(i:int):
            if i > n:
                return
            self.count+=1
            if self.count == k:
                self.ret=i
                return
            for j in range(10):
                x=i*10+j
                if x > n:
                    break
                dfs(x)
        
        for i in range(1,10):
            if i > n or self.count==k:
                break
            dfs(i)
        return self.ret
    
    def findKthNumberSlow2(self, n: int, k: int) -> int:
        c = 1
        m = 0
        while m < k-1:
            m+=1
            tmp=c*10
            if tmp <= n:
                c=tmp
            else:
                while c % 10 == 9 or c == n:
                    c //= 10

                c += 1
        return c

    def findKthNumber(self, n, k):
        current_prefix = 1
        k -= 1  # Decrement k to handle zero-based indexing
        
        while k > 0:
            count = self.countNumbersWithPrefix(current_prefix, n)
            if k >= count:
                current_prefix += 1  # Move to the next prefix
                k -= count
            else:
                current_prefix *= 10  # Go deeper in the current prefix
                k -= 1
        
        return current_prefix

    def countNumbersWithPrefix(self, prefix, n):
        first_number = prefix
        next_number = prefix + 1
        total_count = 0

        while first_number <= n:
            total_count += min(n + 1, next_number) - first_number
            first_number *= 10
            next_number *= 10

        return total_count


            

        