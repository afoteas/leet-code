class Solution {
public:
    int countNegativesBF(vector<vector<int>>& grid) {
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

    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int shift = 0;
        for (int i=0; i < m; ++i) {
            for (int j=0; j < (n-shift); ++j) {
                cout<<"grid[i][j]=" << grid[i][j] << endl;
                if (grid[i][j] < 0) {
                    cout << "j=" << j << ",i=" << i << ",shift=" << shift << endl;
                    ans += (n-j-shift)*(m-i);
                    cout << "ans:" <<ans << endl;
                    shift = n-j;
                    break;
                }
            }
        }
        return ans;
        
    }
};