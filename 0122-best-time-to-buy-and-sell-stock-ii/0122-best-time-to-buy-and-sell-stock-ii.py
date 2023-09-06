class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mp = 0
        i = 1
        l = len(prices)
        while i < l:
            if prices[i] > prices[i-1]:
                mp += prices[i] - prices[i-1]
            i += 1    
        return mp    
