class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        int res = 0;
        function<void(int, int)> dfs = [&dfs, &grid, m, n, &area](int i, int j) {
            if (i >= 0 && i < m && j >=0 && j < n && grid[i][j]) {
                grid[i][j] = 0;
                area++;
                dfs(i+1,j);
                dfs(i-1,j);
                dfs(i,j+1);
                dfs(i,j-1);
            }
        };

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    area = 0;
                    dfs(i,j);
                    res = res > area? res:area;
                }
            }
        }
        return res;
        
    }
};