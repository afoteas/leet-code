class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int W = A[0].size();
        vector<int> dp(W, 1);
        
        for (int i = W - 2; i >= 0; i--) {
            for (int j = i + 1; j < W; j++) {
                bool valid = true;
                for (const string& row : A) {
                    if (row[i] > row[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        int maxDp = *max_element(dp.begin(), dp.end());
        return W - maxDp;
    }
};