class Solution:
    def coinChange1(self, coins: List[int], amount: int) -> int:
        @cache
        def internal(coins, amount):
            if amount == 0:
                return 0
            if amount < 0:
                return float('inf')
            min_steps = float('inf')
            for coin in coins:
                steps = internal(coins, amount - coin)
                if steps != float('inf'):
                    min_steps = min(min_steps, steps + 1)
            return min_steps

        result = internal(tuple(coins), amount)
        return result if result != float('inf') else -1

    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0] + ([float('inf')] * amount)
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        if dp[-1] == float('inf'):
            return -1
        return dp[-1]
        
        