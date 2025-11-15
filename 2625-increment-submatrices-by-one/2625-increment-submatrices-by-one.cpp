class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1, vector<int> (n+1, 0));
        for (const auto& q : queries){
            diff[q[0]][q[1]]++;
            diff[q[2]+1][q[1]]--;
            diff[q[0]][q[3]+1]--;
            diff[q[2]+1][q[3]+1]++;
        }
        vector<vector<int>> ret(n, vector<int> (n, 0));
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1,x2,x3;
                x1 = (i == 0) ? 0 : ret[i-1][j];
                x2 = (j == 0) ? 0 : ret[i][j-1];
                x3 = (i == 0 || j == 0) ? 0 : ret[i-1][j-1];
                ret[i][j] = diff[i][j] + x1 + x2 - x3; 
            }
        }
        return ret;
    }
};