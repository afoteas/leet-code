# Topological Sort

## Overview
Linear ordering of vertices in a DAG (Directed Acyclic Graph) such that for every directed edge u → v, u comes before v.

## When to Use
- Course prerequisites
- Task scheduling
- Build dependencies
- Compilation order
- Any DAG ordering problem

## Approaches

### 1. Kahn's Algorithm (BFS-based)

```cpp
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    
    // Calculate indegrees
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    
    // Add all nodes with indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // If result.size() != n, graph has cycle
    return result.size() == n ? result : vector<int>{};
}
```

### 2. DFS-based

```cpp
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<int> result;
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);  // For cycle detection
    
    function<bool(int)> dfs = [&](int u) {
        visited[u] = true;
        inStack[u] = true;
        
        for (int v : graph[u]) {
            if (inStack[v]) return false;  // Cycle detected
            if (!visited[v] && !dfs(v)) return false;
        }
        
        inStack[u] = false;
        result.push_back(u);  // Add after visiting all neighbors
        return true;
    };
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && !dfs(i)) {
            return {};  // Cycle detected
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

## Complete Examples

### Course Schedule (Can Finish?)
```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        int course = pre[0], prereq = pre[1];
        graph[prereq].push_back(course);
        indegree[course]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    return count == numCourses;
}
```

### Course Schedule II (Find Order)
```cpp
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        int course = pre[0], prereq = pre[1];
        graph[prereq].push_back(course);
        indegree[course]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    return result.size() == numCourses ? result : vector<int>{};
}
```

### Alien Dictionary
```cpp
string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;
    
    // Initialize
    for (string& word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }
    
    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string& word1 = words[i];
        string& word2 = words[i + 1];
        
        // Check for invalid case
        if (word1.length() > word2.length() && 
            word1.substr(0, word2.length()) == word2) {
            return "";
        }
        
        for (int j = 0; j < min(word1.length(), word2.length()); j++) {
            if (word1[j] != word2[j]) {
                if (graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                    graph[word1[j]].insert(word2[j]);
                    indegree[word2[j]]++;
                }
                break;
            }
        }
    }
    
    // Kahn's algorithm
    queue<char> q;
    for (auto& [c, deg] : indegree) {
        if (deg == 0) {
            q.push(c);
        }
    }
    
    string result;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        result += c;
        
        for (char neighbor : graph[c]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result.length() == indegree.size() ? result : "";
}
```

## Cycle Detection

### Using Kahn's Algorithm
```cpp
bool hasCycle(int n, vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int processed = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        processed++;
        
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    return processed != n;  // Cycle exists if not all nodes processed
}
```

## Common Problems
- Course Schedule (LeetCode #207)
- Course Schedule II (LeetCode #210)
- Alien Dictionary (LeetCode #269)
- Minimum Height Trees (LeetCode #310)
- Sequence Reconstruction (LeetCode #444)

## Comparison: Kahn's vs DFS

| Feature | Kahn's (BFS) | DFS |
|---------|--------------|-----|
| Data Structure | Queue | Recursion/Stack |
| Cycle Detection | Count != n | Requires extra state |
| Implementation | More code | Less code |
| Intuition | Remove leaves | Post-order |
| Preferred | ✅ Generally easier | When recursion natural |

## Time Complexity
- **Time:** O(V + E)
- **Space:** O(V + E)

## Tips
- **Kahn's algorithm** is usually easier for interviews
- Count processed nodes to detect cycles
- Multiple valid orderings may exist
- If no cycle, at least one node with indegree 0 exists
- DFS requires reversing result at the end
- Build adjacency list carefully (direction matters!)

## Common Mistakes
1. Wrong edge direction (prereq → course, not course → prereq)
2. Forgetting to check for cycles
3. Not initializing indegree for all nodes
4. Forgetting to reverse in DFS approach

[← Back to README](README.md)
