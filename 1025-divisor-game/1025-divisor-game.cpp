class Solution {
public:

    bool divisorGameHack(int n) {
        return(n%2==0);
    }

    bool divisorGame(int n) {
        vector<int> dp(n+1,0);
        for(int i=2;i<n+1;i++) {
            for(int j=1;j<i;j++) {
                if(i%j==0)dp[i] = dp[i] | !dp[i-j];
            }
        }
        return dp[n];
        
    }
};