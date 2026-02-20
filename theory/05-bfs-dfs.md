# BFS/DFS (Breadth-First Search / Depth-First Search)

## Overview
Fundamental graph traversal algorithms used for exploring nodes and edges.

## Depth-First Search (DFS)

### When to Use
- Exploring all paths
- Backtracking problems
- Cycle detection
- Topological sorting
- Connected components

### Recursive DFS Template
```cpp
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    
    // Process node
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
```

### Iterative DFS Template
```cpp
void dfs(int start, vector<vector<int>>& graph) {
    stack<int> st;
    vector<bool> visited(graph.size(), false);
    
    st.push(start);
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (visited[node]) continue;
        visited[node] = true;
        
        // Process node
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}
```

## Breadth-First Search (BFS)

### When to Use
- Shortest path (unweighted)
- Level-order traversal
- Finding nearest/closest
- Minimum steps/operations

### BFS Template
```cpp
void bfs(int start, vector<vector<int>>& graph) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Process node
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### BFS with Levels
```cpp
int bfsLevels(int start, vector<vector<int>>& graph) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    
    q.push(start);
    visited[start] = true;
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            
            // Process node at this level
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        level++;
    }
    
    return level;
}
```

## Matrix/Grid Traversal

### DFS on Grid
```cpp
void dfs(vector<vector<int>>& grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
        return;
    }
    
    grid[row][col] = 0;  // Mark as visited
    
    // 4 directions
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}
```

### BFS on Grid
```cpp
int bfsGrid(vector<vector<int>>& grid, int startRow, int startCol) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            auto [row, col] = q.front();
            q.pop();
            
            if (/* reached target */) {
                return steps;
            }
            
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        steps++;
    }
    
    return -1;
}
```

## Backtracking

Backtracking is a DFS-based technique for exploring all possible solutions by building them incrementally and abandoning (backtracking) when constraints are violated.

### Core Concept
1. **Choose:** Make a choice (add element to current solution)
2. **Explore:** Recursively explore with that choice
3. **Unchoose:** Undo the choice (backtrack) and try another

### General Backtracking Template
```cpp
void backtrack(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
    // Base case: found a solution
    if (index == nums.size()) {
        result.push_back(path);
        return;
    }
    
    // Try all possibilities
    for (int i = index; i < nums.size(); i++) {
        // Choose
        path.push_back(nums[i]);
        
        // Explore
        backtrack(i + 1, nums, path, result);
        
        // Unchoose (backtrack)
        path.pop_back();
    }
}
```

### Permutations Template
**Goal:** Generate all distinct orderings of elements (order matters)

**Key idea:** Use `used[]` array to track which elements are already in current path. Since permutations care about order, we explore ALL positions, not just forward positions.

**Example:** `[1,2,3]` → `[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]`

```cpp
void permuteHelper(vector<int>& nums, vector<bool>& used, 
                   vector<int>& path, vector<vector<int>>& result) {
    // Base case: all elements used, solution complete
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    
    // Try each element we haven't used yet
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            // Choose: add element to current permutation
            path.push_back(nums[i]);
            used[i] = true;
            
            // Explore: recursively build rest of permutation
            permuteHelper(nums, used, path, result);
            
            // Unchoose: remove element and mark as unused
            path.pop_back();
            used[i] = false;
        }
    }
}
```

**Time:** O(n! × n) - n! permutations, each takes O(n) to copy  
**Space:** O(n) for recursion depth + used array

### Combinations Template
**Goal:** Generate all ways to choose k elements from n elements (order doesn't matter)

**Key idea:** Use `start` index to only explore forward. This prevents duplicates since `[1,2]` and `[2,1]` are the same combination. Only build combinations in increasing order.

**Example:** Choose 2 from `[1,2,3]` → `[1,2], [1,3], [2,3]`

```cpp
void combineHelper(int start, int k, vector<int>& path, 
                   vector<vector<int>>& result) {
    // Base case: selected k elements
    if (path.size() == k) {
        result.push_back(path);
        return;
    }
    
    // Try elements starting from 'start' to avoid duplicates
    for (int i = start; i <= n; i++) {
        // Choose: add element to current combination
        path.push_back(i);
        
        // Explore: choose remaining elements from i+1 onwards
        combineHelper(i + 1, k, path, result);
        
        // Unchoose: remove element and try next
        path.pop_back();
    }
}
```

**Time:** O(C(n,k) × k) - C(n,k) combinations, each takes O(k) to copy  
**Space:** O(k) for recursion depth

### Subsets Template
**Goal:** Generate all possible subsets (power set) - every combination of any length

**Key idea:** Add current path as a solution BEFORE exploring. This naturally generates subsets of all sizes: empty set, singles, pairs, etc. Use `index` to build subsets in increasing order and avoid duplicates.

**Example:** `[1,2]` → `[], [1], [2], [1,2]`

```cpp
void subsetsHelper(int index, vector<int>& nums, vector<int>& path, 
                   vector<vector<int>>& result) {
    // Add current subset (even if empty) as a valid solution
    result.push_back(path);
    
    // Try adding each remaining element and explore
    for (int i = index; i < nums.size(); i++) {
        // Choose: include nums[i] in current subset
        path.push_back(nums[i]);
        
        // Explore: extend subset with remaining elements
        subsetsHelper(i + 1, nums, path, result);
        
        // Unchoose: exclude nums[i] and try next element
        path.pop_back();
    }
}
```

**Time:** O(2^n × n) - 2^n subsets, each takes O(n) to copy  
**Space:** O(n) for recursion depth

### Iterative Backtracking with Stack
```cpp
void backtrackIterative(vector<int>& nums, vector<vector<int>>& result) {
    struct State {
        int index;
        vector<int> path;
    };
    
    stack<State> st;
    st.push({0, {}});
    
    while (!st.empty()) {
        State current = st.top();
        st.pop();
        
        // Base case: found a solution
        if (current.index == nums.size()) {
            result.push_back(current.path);
            continue;
        }
        
        // Try all possibilities (push in reverse order for correct order)
        for (int i = nums.size() - 1; i >= current.index; i--) {
            State next = current;
            next.path.push_back(nums[i]);
            next.index = i + 1;
            st.push(next);
        }
    }
}
```

### When to Use Iterative Backtracking
- **Recursion depth limits** on large inputs
- **Explicit state control** needed
- **Debugging** complex recursive logic
- **Memory constraints** (iterative may be more efficient)

> **Note:** Recursive backtracking is usually preferred for its clarity and simplicity.

### Classic Problems
- Permutations (LeetCode #46)
- Combinations (LeetCode #77)
- Subsets (LeetCode #78)
- N-Queens (LeetCode #51)
- Sudoku Solver (LeetCode #37)
- Word Search (LeetCode #79)
- Generate Parentheses (LeetCode #22)
- Palindrome Partitioning (LeetCode #131)

### Key Tips
- Use `path` vector to track current solution
- Backtrack by removing last element: `path.pop_back()`
- Use `used` array for permutations to avoid duplicates
- Use `start` index for combinations to avoid duplicates
- Prune early when constraints are violated
- Watch time complexity: can be O(n!) for permutations

## Common Problems
- Number of Islands (LeetCode #200)
- Clone Graph (LeetCode #133)
- Course Schedule (LeetCode #207)
- Binary Tree Level Order Traversal (LeetCode #102)
- Surrounded Regions (LeetCode #130)
- Word Ladder (LeetCode #127)

## Comparison

| Feature | DFS | BFS |
|---------|-----|-----|
| Data Structure | Stack (or recursion) | Queue |
| Memory | O(h) where h = height | O(w) where w = max width |
| Shortest Path | ❌ No | ✅ Yes (unweighted) |
| All Paths | ✅ Yes | ❌ Not practical |
| Backtracking | ✅ Natural | ❌ Not suitable |

## Time Complexity
- **Time:** O(V + E) where V = vertices, E = edges
- **Space:** 
  - DFS: O(h) recursion depth
  - BFS: O(w) queue width

## Tips
- Use BFS for shortest path in unweighted graphs
- Use DFS for exploring all possibilities (backtracking)
- For grids, mark cells as visited to avoid revisiting
- Consider using directions array for cleaner code
- Watch out for disconnected components

[← Back to README](README.md)
