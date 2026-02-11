# Network Flow

## Overview
Algorithms for finding maximum flow in a flow network.

## Ford-Fulkerson / Edmonds-Karp

### Concept
- Find augmenting paths from source to sink
- Update residual graph
- Repeat until no more paths

### Edmonds-Karp Implementation (BFS)
```cpp
int maxFlow(vector<vector<int>>& capacity, int source, int sink) {
    int n = capacity.size();
    vector<vector<int>> residual = capacity;
    int totalFlow = 0;
    
    while (true) {
        // BFS to find augmenting path
        vector<int> parent(n, -1);
        queue<pair<int,int>> q;
        q.push({source, INT_MAX});
        
        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();
            
            for (int v = 0; v < n; v++) {
                if (parent[v] == -1 && residual[u][v] > 0) {
                    parent[v] = u;
                    int newFlow = min(flow, residual[u][v]);
                    if (v == sink) {
                        goto found;
                    }
                    q.push({v, newFlow});
                }
            }
        }
        break;  // No more paths
        
        found:
        // Update residual capacities
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            pathFlow = min(pathFlow, residual[parent[v]][v]);
        }
        
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        
        totalFlow += pathFlow;
    }
    
    return totalFlow;
}
```

### Time Complexity
- O(V × E²)

## Applications
- Maximum bipartite matching
- Minimum cut
- Airline scheduling
- Image segmentation
- Baseball elimination

## Note
Very rare in coding interviews. More common in competitive programming.

[← Back to README](README.md)
