int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    // Initialize distance array
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    bool* visited = (bool*)malloc((n + 1) * sizeof(bool));
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[k] = 0;
    
    // Process all nodes
    for (int i = 0; i < n; i++) {
        // Find unvisited node with minimum distance
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        if (u == -1 || dist[u] == INT_MAX) return -1;
        visited[u] = true;
        
        // Relax all edges from u
        for (int j = 0; j < timesSize; j++) {
            int from = times[j][0];
            int to = times[j][1];
            int weight = times[j][2];
            
            // If edge starts from u and relaxation is possible
            if (from == u && dist[u] + weight < dist[to]) {
                dist[to] = dist[u] + weight;
            }
        }
    }
    
    // Find maximum distance (when all nodes are reached)
    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            free(dist);
            free(visited);
            return -1;  // Some node unreachable
        }
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }
    
    free(dist);
    free(visited);
    return maxDist;
}