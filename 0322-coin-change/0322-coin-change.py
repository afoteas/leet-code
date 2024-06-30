class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
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

        
        