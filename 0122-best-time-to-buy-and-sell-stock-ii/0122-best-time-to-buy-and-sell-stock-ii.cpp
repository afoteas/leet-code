class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto mp = 0;
        auto i = 1;
        auto j = prices.size();
        while (i < j) {
            if (prices[i] > prices[i-1]) {
                mp += prices[i] - prices[i-1];
            }
            i++;
        }
        return mp;

        
    }
};


        // mp = 0
        // i = 1
        // l = len(prices)
        // while i < l:
        //     if prices[i] > prices[i-1]:
        //         mp += prices[i] - prices[i-1]
        //     i += 1    
        // return mp   