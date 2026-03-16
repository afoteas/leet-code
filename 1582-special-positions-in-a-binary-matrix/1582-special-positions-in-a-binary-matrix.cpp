class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        vector<int> ones(n,0);
        vector<int> candidates;
        for(int i = 0; i < m; ++i) {
            vector<int> temp = {};
            for(int j=0; j < n; ++j) {
                if(mat[i][j] == 1) {
                    temp.push_back(j);
                    ones[j] += 1;
                }
            }
            if(temp.size() == 1) candidates.push_back(temp[0]);
        }
        for(auto&v:candidates) {
            if(ones[v] == 1) ans++;
        }
        return ans;
        
    }
};