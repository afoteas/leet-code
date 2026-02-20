# Minimum Spanning Tree (MST)

## Overview
Subset of edges connecting all vertices with minimum total weight (no cycles).

## Kruskal's Algorithm

### Overview
Greedy algorithm using Union-Find.

### Implementation
```cpp
class UnionFind {
    // ... (implementation from topic 12)
};

int kruskal(int n, vector<tuple<int,int,int>>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), 
         [](auto& a, auto& b) { return get<2>(a) < get<2>(b); });
    
    UnionFind uf(n);
    int mstWeight = 0;
    int edgesUsed = 0;
    
    for (auto [u, v, w] : edges) {
        if (uf.unite(u, v)) {
            mstWeight += w;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }
    
    return edgesUsed == n - 1 ? mstWeight : -1;
}
```

### Time Complexity
- O(E log E) for sorting
- O(E α(V)) for union-find
- **Total**: O(E log E)

## Prim's Algorithm

### Overview
Greedy algorithm using priority queue.

### Implementation
```cpp
int prim(int n, vector<vector<pair<int,int>>>& graph) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    pq.push({0, 0});  // {weight, node}
    int mstWeight = 0;
    
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if (inMST[u]) continue;
        
        inMST[u] = true;
        mstWeight += w;
        
        for (auto [v, weight] : graph[u]) {
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }
    
    return mstWeight;
}
```

### Time Complexity
- O((V + E) log V) with binary heap

## When to Use

- **Kruskal's**: Sparse graphs, need edge list
- **Prim's**: Dense graphs, adjacency list

## Applications
- Network design
- Clustering
- Approximation algorithms
- Circuit design

[← Back to README](README.md)
