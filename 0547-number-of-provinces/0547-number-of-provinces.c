void dfs(int i, int** isConnected, int len, int* visit) {
    for(int j=0; j<len; ++j) {
        if(isConnected[i][j] && !visit[j]) {
            visit[j] = 1;
            dfs(j, isConnected, len, visit);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int count = 0;
    int* visit = (int*)calloc(isConnectedSize, sizeof(int));
    for(int i=0; i<isConnectedSize; i++)
    {
        if(!visit[i])
        {
            count++;
            visit[i]=1;
            dfs(i, isConnected, isConnectedSize, visit);
        }
    }
    return count;  
}