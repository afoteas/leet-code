class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # maxProf = 0
        # for i in range(len(prices)):
        #     # tempMax = max([x - prices[i] for x in prices[i:]])
        #     tempMax = max(prices[i:]) - prices[i]
        #     if tempMax > maxProf:
        #         maxProf = tempMax
        # return maxProf       

        l,r=0,1
        maxP=0 
        while r<len(prices):
            if prices[l]<prices[r]:
                profit=prices[r]-prices[l]
                maxP=max(maxP, profit)                
            else:
                l=r 
            r+=1
        return maxP 
                