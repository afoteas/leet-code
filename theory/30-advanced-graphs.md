# Advanced Graphs

## Bellman-Ford Algorithm

### Overview
Single-source shortest path that handles negative edge weights.

### Implementation
```cpp
vector<int> bellmanFord(int n, vector<tuple<int,int,int>>& edges, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            // Negative cycle detected
            return {};
        }
    }
    
    return dist;
}
```

### Time Complexity
- O(V × E)

## Floyd-Warshall Algorithm

### Overview
All-pairs shortest path using dynamic programming.

### Implementation
```cpp
vector<vector<int>> floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    return dist;
}
```

### Time Complexity
- O(V³)

## Strongly Connected Components

### Kosaraju's Algorithm
```cpp
void dfs1(int u, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs1(v, graph, visited, st);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& graphRev, vector<bool>& visited) {
    visited[u] = true;
    // Process node in SCC
    for (int v : graphRev[u]) {
        if (!visited[v]) {
            dfs2(v, graphRev, visited);
        }
    }
}

int findSCCs(int n, vector<vector<int>>& graph) {
    // Build reverse graph
    vector<vector<int>> graphRev(n);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            graphRev[v].push_back(u);
        }
    }
    
    // First DFS to fill stack
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i, graph, visited, st);
        }
    }
    
    // Second DFS on reverse graph
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            dfs2(u, graphRev, visited);
            sccCount++;
        }
    }
    
    return sccCount;
}
```

## Tarjan's Algorithm (SCC)
Find SCCs in single DFS pass.

## Articulation Points and Bridges
Find critical nodes/edges whose removal disconnects graph.

[← Back to README](README.md)
