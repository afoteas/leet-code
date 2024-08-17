class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2) {
            return n;
        }
        std::map<int, int> dp = {{1,1},{2,2}};
        for(int i=3; i<n+1; i++) {
            dp[i]=dp[i-1] + dp[i-2];
        }
        return dp[n];
        
    }
};

//    def climbStairsDP(self, n: int) -> int:
        // if n in [1, 2]:
        //     return n
        // dp = {1:1,2:2}
        // for i in range(3,n+1):
        //     dp[i]=dp[i-1] + dp[i-2]
        // return dp[n]