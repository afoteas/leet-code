void dfs(int i, int j, int** grid, int m, int n,int *area) {
    if (i >= 0 && i < m && j >=0 && j < n && grid[i][j]) {
        grid[i][j] = 0;
        (*area)++;
        dfs(i+1,j,grid,m,n,area);
        dfs(i-1,j,grid,m,n,area);
        dfs(i,j+1,grid,m,n,area);
        dfs(i,j-1,grid,m,n,area);
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    printf("%d,%d", gridSize,*gridColSize);
    int area = 0;
    int res = 0;
    for(int i=0;i<gridSize;i++) {
        for(int j=0;j<*gridColSize;j++) {
            if(grid[i][j]) {
                area = 0;
                dfs(i,j,grid,gridSize,*gridColSize, &area);
                res = res > area? res:area;
            }
        }
    }
    return res;

}
