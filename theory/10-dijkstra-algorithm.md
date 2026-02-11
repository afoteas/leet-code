# Dijkstra's Algorithm

## Overview
Dijkstra's algorithm finds the shortest path from a single source node to all other nodes in a weighted graph with **non-negative** edge weights.

### Key Idea
Think of it like exploring a map where you always visit the closest unvisited location first. By doing this greedily, you're guaranteed to find the shortest path to each destination.

### Why It Works (Greedy Choice Property)
When we pick the node with the smallest distance from the priority queue, we've already found the shortest path to it. Why? Because:
1. All edge weights are non-negative
2. Any other path to this node would have to go through other unvisited nodes
3. Those nodes have larger distances (they're still in the queue)
4. Adding positive weights to larger distances can't make them smaller

This is why **negative edges break Dijkstra** - they violate this assumption!

## How It Works: Step-by-Step

### Conceptual Process
1. **Initialize**: Set distance to start = 0, all others = ∞
2. **Pick closest**: Choose unvisited node with smallest distance
3. **Relax edges**: For each neighbor, check if going through current node is shorter
4. **Update**: If shorter path found, update distance and add to queue
5. **Repeat**: Until all nodes visited or queue empty

### Visual Example
```
Graph:        A --4-- B
              |      /|
              2    1  |
              |  /    3
              C --5-- D

Starting from A:

Step 1: Start at A (dist = 0)
  Distances: A=0, B=∞, C=∞, D=∞
  
Step 2: Visit A's neighbors (B and C)
  - A→B: 0+4=4, update B=4
  - A→C: 0+2=2, update C=2
  Distances: A=0, B=4, C=2, D=∞
  Queue: [(2,C), (4,B)]
  
Step 3: Pick C (smallest distance = 2)
  - C→B: 2+1=3 < 4, update B=3
  - C→D: 2+5=7, update D=7
  Distances: A=0, B=3, C=2, D=7
  Queue: [(3,B), (7,D)]
  
Step 4: Pick B (distance = 3)
  - B→D: 3+3=6 < 7, update D=6
  Distances: A=0, B=3, C=2, D=6
  Queue: [(6,D)]
  
Step 5: Pick D (distance = 6)
  - No unvisited neighbors
  Final: A=0, B=3, C=2, D=6
```

## Algorithm

### Template with Detailed Comments
```cpp
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& graph, int start) {
    // Distance array: dist[i] = shortest distance from start to node i
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;  // Distance to self is 0
    
    // Min heap: {distance, node}
    // We use greater<> to make it a MIN heap (smallest distance at top)
    // Store pairs as {distance, node} so it sorts by distance first
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        // Get node with minimum distance (greedy choice)
        auto [d, u] = pq.top();
        pq.pop();
        
        // OPTIMIZATION: Skip if we've already found a better path to u
        // This happens because we may add the same node multiple times
        // with different distances to the queue
        if (d > dist[u]) continue;
        
        // "Relax" all edges from u
        // Relaxation: Check if going through u gives a shorter path
        for (auto [v, weight] : graph[u]) {
            // If path through u is shorter than current best to v
            if (dist[u] + weight < dist[v]) {
                // Update shortest distance to v
                dist[v] = dist[u] + weight;
                // Add v to queue with new distance
                // Note: We DON'T remove old entries, we just ignore them later
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;  // dist[i] = shortest path from start to i
}
```

### Why Priority Queue?
The priority queue ensures we always process the node with the smallest **tentative** distance next. This greedy approach guarantees we find the optimal path because:
- When we pop a node from the queue, its distance is final (can't be improved)
- All shorter paths have already been explored
- Any longer path would come from nodes still in the queue

### Graph Representation
```cpp
// Adjacency list: graph[u] = list of {neighbor, edge_weight} pairs
vector<vector<pair<int,int>>> graph(n);

// Add directed edge from u to v with weight w
graph[u].push_back({v, weight});

// For undirected graph, add edge in both directions
graph[u].push_back({v, weight});
graph[v].push_back({u, weight});
```

### Understanding the Key Check: `if (d > dist[u]) continue;`

This line is crucial but often confusing. Here's why we need it:

**Problem**: We may add the same node to the priority queue multiple times with different distances.

**Example**:
```
Node A: distance 10
We discover A can be reached with distance 5, add (5, A) to queue
Later discover A can be reached with distance 3, add (3, A) to queue
Queue now has: (10, A), (5, A), (3, A)
```

**Solution**: When we pop (5, A), we check: is 5 > dist[A]? 
- If yes (dist[A] is already 3), skip it - we already processed A with better distance
- If no, process it normally

**Why not use visited set instead?**
```cpp
// This approach is also valid but slightly less efficient
vector<bool> visited(n, false);
if (visited[u]) continue;
visited[u] = true;
```
The `d > dist[u]` check is more flexible for problems where you might visit nodes multiple times with different states.

## Complete Example: Network Delay Time

```cpp
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Build graph
    vector<vector<pair<int,int>>> graph(n + 1);
    for (auto& edge : times) {
        int u = edge[0], v = edge[1], w = edge[2];
        graph[u].push_back({v, w});
    }
    
    // Dijkstra
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Find maximum distance
    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        maxDist = max(maxDist, dist[i]);
    }
    
    return maxDist;
}
```

## Variations

### With Path Reconstruction
```cpp
pair<vector<int>, vector<int>> dijkstraWithPath(int n, vector<vector<pair<int,int>>>& graph, int start) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[start] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, weight] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    return {dist, parent};
}

vector<int> reconstructPath(vector<int>& parent, int start, int end) {
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path[0] == start ? path : vector<int>{};
}
```

### Modified for Different State Space
```cpp
// Example: Minimum cost with K stops (LeetCode #787)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> graph(n);
    for (auto& f : flights) {
        graph[f[0]].push_back({f[1], f[2]});
    }
    
    // {cost, node, stops}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, src, 0});
    
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
    dist[src][0] = 0;
    
    while (!pq.empty()) {
        auto [cost, u, stops] = pq.top();
        pq.pop();
        
        if (u == dst) return cost;
        if (stops > k) continue;
        
        for (auto [v, price] : graph[u]) {
            int newCost = cost + price;
            if (newCost < dist[v][stops + 1]) {
                dist[v][stops + 1] = newCost;
                pq.push({newCost, v, stops + 1});
            }
        }
    }
    
    return -1;
}
```

## Optimization: Visited Set
```cpp
vector<int> dijkstraOptimized(int n, vector<vector<pair<int,int>>>& graph, int start) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[start] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, weight] : graph[u]) {
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```

## Common Problems
- Network Delay Time (LeetCode #743)
- Path with Maximum Probability (LeetCode #1514)
- Cheapest Flights Within K Stops (LeetCode #787)
- Path With Minimum Effort (LeetCode #1631)
- Swim in Rising Water (LeetCode #778)

## When to Use Dijkstra

✅ **Use When:**
- Single-source shortest path
- Non-negative edge weights
- Need actual shortest distances
- Weighted graph

❌ **Don't Use When:**
- Negative edge weights (use Bellman-Ford)
- Unweighted graph (use BFS instead)
- All-pairs shortest path (use Floyd-Warshall)
- Just checking reachability (use DFS/BFS)

## Common Mistakes & How to Avoid Them

### 1. Forgetting to check if already processed
```cpp
if (d > dist[u]) continue;  // CRITICAL!
```
**Why it matters**: Without this, you'll process the same node multiple times, wasting computation and potentially getting wrong answers.

### 2. Using wrong comparator in priority queue
```cpp
// WRONG: This creates MAX heap
priority_queue<pair<int,int>> pq;

// CORRECT: This creates MIN heap
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
```
**Why it matters**: Max heap gives you the largest distance first, completely breaking the algorithm!

### 3. Not handling unreachable nodes
```cpp
if (dist[target] == INT_MAX) return -1;  // No path exists
```
**Why it matters**: In disconnected graphs, some nodes may be unreachable. Always check!

### 4. Incorrect initialization
```cpp
dist[start] = 0;  // MUST initialize start to 0
dist[other] = INT_MAX;  // Others to infinity
```
**Why it matters**: If you forget to set start = 0, algorithm won't work at all.

### 5. Wrong pair order in priority queue
```cpp
// CORRECT: {distance, node} - sorts by distance
pq.push({dist[v], v});

// WRONG: {node, distance} - sorts by node ID!
pq.push({v, dist[v]});
```
**Why it matters**: Priority queue sorts by first element. You want to sort by distance, not node ID.

### 6. Using Dijkstra with negative weights
```cpp
// DON'T DO THIS - Dijkstra doesn't work with negative edges!
// Use Bellman-Ford instead
```
**Why it matters**: Negative edges break the greedy assumption. You might visit a node, mark it as done, then later find a shorter path through a negative edge.

**Example where Dijkstra fails with negative edges**:
```
   A --1--> B
   |        |
   5       -10
   |        |
   v        v
   C <------D

Start at A:
1. Visit A (dist=0)
2. Visit B (dist=1) - mark as final ❌
3. Visit C (dist=5)
4. Visit D (dist=-5)
5. Now A→C→D→B = -5 < 1, but we already finalized B!
```

## Complexity

- **Time:** O((V + E) log V) with binary heap
- **Space:** O(V + E) for graph, O(V) for distance array

## Dijkstra vs BFS vs Bellman-Ford

| Algorithm | Use Case | Time | Negatives? |
|-----------|----------|------|------------|
| Dijkstra | Weighted, non-negative | O((V+E) log V) | ❌ |
| BFS | Unweighted | O(V + E) | N/A |
| Bellman-Ford | Weighted, with negatives | O(VE) | ✅ |

## Tips & Best Practices

### Implementation Tips
- ✅ Always use min heap: `priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>`
- ✅ Store pairs as `{distance, node}` to sort by distance
- ✅ Include the distance check: `if (d > dist[u]) continue;`
- ✅ Handle unreachable nodes by checking for `INT_MAX`

### Optimization Tips
- ✅ **Early termination**: If you only need distance to one target, return when you pop it from queue
  ```cpp
  if (u == target) return dist[u];
  ```
- ✅ **Bidirectional search**: For single source-target, run Dijkstra from both ends
- ✅ **A* algorithm**: Use heuristic to guide search toward target (when you know target location)

### Problem-Solving Tips
- ✅ **Check if BFS suffices**: If all edges have weight 1, use BFS (simpler and faster)
- ✅ **Grid problems**: Treat each cell as a node, index as `row * cols + col`
- ✅ **Multi-dimensional state**: State can be `(node, fuel_left)`, `(node, stops)`, etc.
- ✅ **Multiple sources**: Add all sources to queue with distance 0 initially

### When Dijkstra is Overkill
```cpp
// If all weights are 1, just use BFS!
queue<int> q;
vector<int> dist(n, -1);
q.push(start);
dist[start] = 0;

while (!q.empty()) {
    int u = q.front();
    q.pop();
    
    for (int v : graph[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

## Practice Strategy

### Easy Problems (Learn the Pattern)
1. Network Delay Time (LeetCode #743) - Classic Dijkstra
2. Path with Maximum Probability (LeetCode #1514) - Modified weight

### Medium Problems (Apply with Variations)
3. Cheapest Flights Within K Stops (LeetCode #787) - Multi-dimensional state
4. Path With Minimum Effort (LeetCode #1631) - Grid-based

### Hard Problems (Advanced Techniques)
5. Swim in Rising Water (LeetCode #778) - Binary search + Dijkstra
6. Minimum Cost to Make at Least One Valid Path (LeetCode #1368) - 0-1 BFS variant

## Quick Reference

```cpp
// Standard Dijkstra template - memorize this!
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& graph, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

[← Back to README](README.md)
