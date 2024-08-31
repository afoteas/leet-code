class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        int ret {0};
        function<void(int,int)> dfs = [this, &grid, x, y, &dfs](int i, int j) {
            if(i==x || j==y || i<0 || j<0 || grid[i][j]=='0') {
                return;
            }
            grid[i][j]='0';
            dfs(i+1,j);
            dfs(i,j+1);
            dfs(i-1,j);
            dfs(i,j-1);
        };
        for(int i=0; i<x; i++){
            for(int j=0;j<y;j++) {
                if(grid[i][j]=='1') {
                    ret++;
                    dfs(i,j);
                }

            }
        }
        return ret;
    }
};