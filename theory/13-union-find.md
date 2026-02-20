# Union-Find (Disjoint Set Union)

## Overview
Data structure that tracks elements partitioned into disjoint sets, supporting two operations:
- **Find**: Determine which set an element belongs to
- **Union**: Merge two sets

## Implementation

### Basic Template
```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### With Component Count
```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int components;
    
public:
    UnionFind(int n) : components(n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        components--;
        return true;
    }
    
    int getComponents() {
        return components;
    }
};
```

### With Set Size
```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        // Union by size
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        
        return true;
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
};
```

## Common Problems

### Number of Connected Components
```cpp
int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    
    for (auto& edge : edges) {
        uf.unite(edge[0], edge[1]);
    }
    
    return uf.getComponents();
}
```

### Number of Islands (Grid)
```cpp
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    UnionFind uf(m * n);
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                
                int idx = i * n + j;
                
                // Check neighbors
                if (i > 0 && grid[i-1][j] == '1') {
                    if (uf.unite(idx, (i-1) * n + j)) {
                        count--;
                    }
                }
                if (j > 0 && grid[i][j-1] == '1') {
                    if (uf.unite(idx, i * n + (j-1))) {
                        count--;
                    }
                }
            }
        }
    }
    
    return count;
}
```

### Redundant Connection
```cpp
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size() + 1);
    
    for (auto& edge : edges) {
        if (!uf.unite(edge[0], edge[1])) {
            return edge;  // This edge creates a cycle
        }
    }
    
    return {};
}
```

### Accounts Merge
```cpp
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    UnionFind uf(accounts.size());
    unordered_map<string, int> emailToID;
    
    // Build union-find
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];
            if (emailToID.find(email) == emailToID.end()) {
                emailToID[email] = i;
            } else {
                uf.unite(i, emailToID[email]);
            }
        }
    }
    
    // Group emails by root
    unordered_map<int, set<string>> groups;
    for (auto& [email, id] : emailToID) {
        int root = uf.find(id);
        groups[root].insert(email);
    }
    
    // Build result
    vector<vector<string>> result;
    for (auto& [id, emails] : groups) {
        vector<string> account;
        account.push_back(accounts[id][0]);  // Name
        for (string email : emails) {
            account.push_back(email);
        }
        result.push_back(account);
    }
    
    return result;
}
```

### Most Stones Removed
```cpp
int removeStones(vector<vector<int>>& stones) {
    UnionFind uf(20000);
    
    for (auto& stone : stones) {
        // Union row and column (offset column by 10000)
        uf.unite(stone[0], stone[1] + 10000);
    }
    
    unordered_set<int> uniqueRoots;
    for (auto& stone : stones) {
        uniqueRoots.insert(uf.find(stone[0]));
    }
    
    return stones.size() - uniqueRoots.size();
}
```

## When to Use Union-Find

✅ **Use When:**
- Finding connected components
- Detecting cycles in undirected graphs
- Dynamic connectivity queries
- Grouping/clustering problems
- MST (Kruskal's algorithm)

❌ **Don't Use When:**
- Directed graphs (use DFS/BFS)
- Need to find path between nodes
- Need to remove edges (union-find doesn't support)
- Tree structure queries (use tree algorithms)

## Optimizations

### Path Compression
```cpp
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Compress path
    }
    return parent[x];
}
```

### Union by Rank
```cpp
if (rank[rootX] < rank[rootY]) {
    parent[rootX] = rootY;
} else if (rank[rootX] > rank[rootY]) {
    parent[rootY] = rootX;
} else {
    parent[rootY] = rootX;
    rank[rootX]++;
}
```

### Union by Size
```cpp
if (size[rootX] < size[rootY]) {
    parent[rootX] = rootY;
    size[rootY] += size[rootX];
} else {
    parent[rootY] = rootX;
    size[rootX] += size[rootY];
}
```

## Common Problems
- Number of Connected Components (LeetCode #323)
- Redundant Connection (LeetCode #684)
- Accounts Merge (LeetCode #721)
- Number of Islands II (LeetCode #305)
- Most Stones Removed (LeetCode #947)
- Satisfiability of Equality Equations (LeetCode #990)

## Time Complexity

| Operation | Without Optimization | With Path Compression + Union by Rank |
|-----------|---------------------|---------------------------------------|
| Find | O(n) | O(α(n)) ≈ O(1) |
| Union | O(n) | O(α(n)) ≈ O(1) |

*α(n) is the inverse Ackermann function, practically constant*

## Tips
- Always use both path compression AND union by rank/size
- Initialize parent[i] = i
- For grid problems, convert 2D coordinates to 1D
- Check if elements are already in same set before union
- Track number of components if needed
- Union-Find doesn't work well with edge removal

[← Back to README](README.md)
