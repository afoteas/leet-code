class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto &r:grid) {
            for(auto &v:r) {
                if(v <0) {
                    ans ++;
                }
            }
        }
        return ans;
        
    }
};