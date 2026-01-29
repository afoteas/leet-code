# Algorithm Theory and Examples

This document provides theory, examples, and key concepts for common algorithm categories used in competitive programming and technical interviews.

## Table of Contents
- [Hash Table](#hash-table)
- [Array](#array)
- [Sliding Window](#sliding-window)
- [Two Pointers](#two-pointers)
- [Sorting](#sorting)
- [Stack](#stack)
- [Queue](#queue)
- [Recursion](#recursion)
- [Divide and Conquer](#divide-and-conquer)
- [Dynamic Programming](#dynamic-programming)
- [Binary Search](#binary-search)
- [Linked List](#linked-list)
- [Tree](#tree)
- [Binary Tree](#binary-tree)
- [Binary Search Tree](#binary-search-tree)
- [Depth-First Search (DFS)](#depth-first-search-dfs)
- [Breadth-First Search (BFS)](#breadth-first-search-bfs)
- [Heap (Priority Queue)](#heap-priority-queue)
- [Trie](#trie)
- [Bit Manipulation](#bit-manipulation)
- [Backtracking](#backtracking)
- [Graph](#graph)
- [Topological Sort](#topological-sort)
- [Union Find](#union-find)
- [Greedy](#greedy)

---

## Hash Table

### Theory
A hash table (or hash map) is a data structure that implements an associative array, mapping keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

**Time Complexity:**
- Average: O(1) for insert, delete, and search
- Worst: O(n) when all keys hash to the same bucket

**Space Complexity:** O(n)

### Example: Two Sum
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}
```

### Use Cases
- Fast lookups (checking if element exists)
- Counting frequencies
- Storing key-value pairs
- Detecting duplicates
- Caching/memoization

---

## Array

### Theory
An array is a collection of elements stored at contiguous memory locations. It's one of the most fundamental data structures.

**Time Complexity:**
- Access: O(1)
- Search: O(n)
- Insert/Delete at end: O(1) amortized
- Insert/Delete at arbitrary position: O(n)

**Space Complexity:** O(n)

### Example: Maximum Subarray (Kadane's Algorithm)
```cpp
int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
```

### Use Cases
- Storing sequential data
- Random access needed
- Fixed-size collections
- Matrix operations

---

## Sliding Window

### Theory
The sliding window technique is used to perform operations on a specific window size of an array or string. The window slides through the data structure to solve problems efficiently.

**Time Complexity:** O(n) - each element is visited at most twice
**Space Complexity:** O(1) to O(k) depending on the problem

### Example: Maximum Sum of Subarray of Size K
```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    if (arr.size() < k) {
        return -1;
    }
    
    int window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    int max_sum = window_sum;
    
    for (int i = k; i < arr.size(); i++) {
        window_sum = window_sum - arr[i-k] + arr[i];
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}
```

### Use Cases
- Finding subarrays/substrings with specific properties
- Maximum/minimum in sliding windows
- String pattern matching
- Longest/shortest substring problems

---

## Two Pointers

### Theory
The two pointers technique uses two pointers to iterate through a data structure, typically an array or linked list. Pointers can move in the same direction or opposite directions.

**Time Complexity:** O(n)
**Space Complexity:** O(1)

### Example: Container With Most Water
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    
    while (left < right) {
        int width = right - left;
        max_area = max(max_area, min(height[left], height[right]) * width);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}
```

### Use Cases
- Pair finding problems
- Removing duplicates from sorted array
- Palindrome checking
- Partitioning arrays
- Merging sorted arrays

---

## Sorting

### Theory
Sorting algorithms arrange elements in a specific order (ascending or descending). Common algorithms include Quick Sort, Merge Sort, Heap Sort, and built-in sorts.

**Time Complexity:**
- Quick Sort: O(n log n) average, O(n²) worst
- Merge Sort: O(n log n) always
- Heap Sort: O(n log n) always
- Counting Sort: O(n + k) where k is range

**Space Complexity:** O(1) to O(n) depending on algorithm

### Example: Merge Intervals
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged = {intervals[0]};
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    
    return merged;
}
```

### Use Cases
- Organizing data
- Finding kth largest/smallest element
- Interval problems
- Meeting room scheduling
- Binary search prerequisite

---

## Stack

### Theory
A stack is a Last-In-First-Out (LIFO) data structure. Elements are added and removed from the same end (top).

**Operations:**
- Push: O(1)
- Pop: O(1)
- Peek: O(1)

**Space Complexity:** O(n)

### Example: Valid Parentheses
```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
    
    for (char c : s) {
        if (mapping.find(c) != mapping.end()) {
            char top = st.empty() ? '#' : st.top();
            if (!st.empty()) st.pop();
            if (mapping[c] != top) {
                return false;
            }
        } else {
            st.push(c);
        }
    }
    
    return st.empty();
}
```

### Use Cases
- Expression evaluation
- Parentheses matching
- Undo mechanisms
- Function call management (recursion)
- Backtracking
- Next greater element problems

---

## Queue

### Theory
A queue is a First-In-First-Out (FIFO) data structure. Elements are added at the rear and removed from the front.

**Operations:**
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

**Space Complexity:** O(n)

### Example: Moving Average
```cpp
class MovingAverage {
private:
    int size;
    queue<int> q;
    double sum;
    
public:
    MovingAverage(int size) : size(size), sum(0.0) {}
    
    double next(int val) {
        q.push(val);
        sum += val;
        
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        
        return sum / q.size();
    }
};
```

### Use Cases
- BFS traversal
- Task scheduling
- Buffer management
- Level order traversal
- Rate limiting

---

## Recursion

### Theory
Recursion is a method where a function calls itself to solve smaller instances of the same problem. It requires a base case to stop recursion and a recursive case to break down the problem.

**Time Complexity:** Varies (often exponential without memoization)
**Space Complexity:** O(n) for call stack depth

### Example: Fibonacci
```cpp
int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    // Recursive case
    return fibonacci(n-1) + fibonacci(n-2);
}

// Optimized with memoization
unordered_map<int, int> memo;

int fibonacci_memo(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    if (n <= 1) {
        return n;
    }
    memo[n] = fibonacci_memo(n-1) + fibonacci_memo(n-2);
    return memo[n];
}
```

### Use Cases
- Tree/graph traversal
- Divide and conquer problems
- Backtracking
- Mathematical computations
- Permutations and combinations

---

## Divide and Conquer

### Theory
Divide and conquer breaks a problem into smaller subproblems, solves them recursively, and combines their solutions.

**Steps:**
1. Divide: Break problem into subproblems
2. Conquer: Solve subproblems recursively
3. Combine: Merge solutions

**Time Complexity:** Often O(n log n)

### Example: Merge Sort
```cpp
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);
    return result;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
}
```

### Use Cases
- Merge sort, quick sort
- Binary search
- Finding closest pair of points
- Matrix multiplication
- Maximum subarray problems

---

## Dynamic Programming

### Theory
Dynamic Programming (DP) solves complex problems by breaking them down into simpler subproblems and storing their solutions to avoid redundant calculations.

**Approaches:**
- Top-down (Memoization): Recursion + caching
- Bottom-up (Tabulation): Iterative with table

**Time Complexity:** O(n²) to O(n³) typically
**Space Complexity:** O(n) to O(n²)

### Example: Climbing Stairs
```cpp
int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

### Example: Longest Common Subsequence
```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### Use Cases
- Optimization problems
- Counting problems
- String matching (LCS, edit distance)
- Knapsack problems
- Path finding in grids

---

## Binary Search

### Theory
Binary search is an efficient algorithm for finding an item in a sorted array by repeatedly dividing the search interval in half.

**Time Complexity:** O(log n)
**Space Complexity:** O(1) iterative, O(log n) recursive

### Example: Binary Search
```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
```

### Example: Find First and Last Position
```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    auto findBound = [&](bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    };
    
    return {findBound(true), findBound(false)};
}
```

### Use Cases
- Searching in sorted arrays
- Finding boundaries
- Square root calculation
- Search in rotated sorted array
- Optimization problems with monotonic property

---

## Linked List

### Theory
A linked list is a linear data structure where elements are stored in nodes, and each node points to the next node.

**Types:**
- Singly Linked List
- Doubly Linked List
- Circular Linked List

**Time Complexity:**
- Access: O(n)
- Search: O(n)
- Insert/Delete at head: O(1)
- Insert/Delete at position: O(n)

### Example: Reverse Linked List
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* n = nullptr) : val(x), next(n) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current) {
        ListNode* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    
    return prev;
}
```

### Example: Detect Cycle (Floyd's Algorithm)
```cpp
bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}
```

### Use Cases
- Dynamic memory allocation
- Implementing stacks, queues
- Undo functionality
- Music playlist
- Browser history

---

## Tree

### Theory
A tree is a hierarchical data structure with a root node and child nodes forming a parent-child relationship.

**Properties:**
- Each node has at most one parent
- No cycles
- N nodes have N-1 edges

**Common Operations:** O(h) where h is height

### Example: Tree Node Definition
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) 
        : val(x), left(l), right(r) {}
};
```

### Use Cases
- File systems
- Organization hierarchies
- HTML DOM
- Database indexing
- Decision trees

---

## Binary Tree

### Theory
A binary tree is a tree where each node has at most two children (left and right).

**Types:**
- Full: Every node has 0 or 2 children
- Complete: All levels filled except possibly last
- Perfect: All internal nodes have 2 children, all leaves at same level
- Balanced: Height difference between subtrees ≤ 1

### Example: Maximum Depth
```cpp
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

### Example: Level Order Traversal
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }
    
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int level_size = q.size();
        vector<int> level;
        
        for (int i = 0; i < level_size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(level);
    }
    
    return result;
}
```

### Use Cases
- Expression trees
- Huffman coding
- Decision trees
- Game trees (minimax)

---

## Binary Search Tree

### Theory
A Binary Search Tree (BST) is a binary tree where:
- Left subtree values < node value
- Right subtree values > node value
- Both subtrees are also BSTs

**Time Complexity:**
- Average: O(log n) for search, insert, delete
- Worst: O(n) when tree becomes skewed

### Example: Validate BST
```cpp
bool isValidBST(TreeNode* root) {
    function<bool(TreeNode*, long, long)> validate = 
        [&](TreeNode* node, long low, long high) {
        if (!node) {
            return true;
        }
        
        if (node->val <= low || node->val >= high) {
            return false;
        }
        
        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    };
    
    return validate(root, LONG_MIN, LONG_MAX);
}
```

### Example: Insert Node
```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}
```

### Use Cases
- Database indexing
- Maintaining sorted data
- Priority queues
- Symbol tables in compilers

---

## Depth-First Search (DFS)

### Theory
DFS explores as far as possible along each branch before backtracking. Can be implemented recursively or with a stack.

**Traversal Orders:**
- Preorder: Root → Left → Right
- Inorder: Left → Root → Right
- Postorder: Left → Right → Root

**Time Complexity:** O(V + E) for graphs, O(n) for trees
**Space Complexity:** O(h) where h is height

### Example: DFS on Graph
```cpp
void dfs(unordered_map<int, vector<int>>& graph, int start, 
         unordered_set<int>& visited) {
    visited.insert(start);
    cout << start << endl;
    
    for (int neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}
```

### Example: Path Sum
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }
    
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}
```

### Use Cases
- Finding paths
- Detecting cycles
- Topological sorting
- Solving mazes
- Connected components

---

## Breadth-First Search (BFS)

### Theory
BFS explores all neighbors at the present depth before moving to nodes at the next depth level. Uses a queue.

**Time Complexity:** O(V + E) for graphs, O(n) for trees
**Space Complexity:** O(w) where w is maximum width

### Example: BFS on Graph
```cpp
void bfs(unordered_map<int, vector<int>>& graph, int start) {
    unordered_set<int> visited;
    queue<int> q;
    
    visited.insert(start);
    q.push(start);
    
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << endl;
        
        for (int neighbor : graph[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

### Example: Shortest Path in Binary Matrix
```cpp
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) {
        return -1;
    }
    
    int n = grid.size();
    queue<tuple<int, int, int>> q;  // row, col, distance
    q.push({0, 0, 1});
    grid[0][0] = 1;
    
    vector<pair<int, int>> directions = {
        {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
    };
    
    while (!q.empty()) {
        auto [row, col, dist] = q.front();
        q.pop();
        
        if (row == n-1 && col == n-1) {
            return dist;
        }
        
        for (auto [dr, dc] : directions) {
            int r = row + dr, c = col + dc;
            if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
                grid[r][c] = 1;
                q.push({r, c, dist + 1});
            }
        }
    }
    
    return -1;
}
```

### Use Cases
- Shortest path in unweighted graphs
- Level order traversal
- Finding nearest neighbors
- Web crawling
- Social network connections

---

## Heap (Priority Queue)

### Theory
A heap is a complete binary tree where each node satisfies the heap property:
- Max Heap: Parent ≥ children
- Min Heap: Parent ≤ children

**Time Complexity:**
- Insert: O(log n)
- Extract min/max: O(log n)
- Peek: O(1)
- Heapify: O(n)

### Example: Kth Largest Element
```cpp
int findKthLargest(vector<int>& nums, int k) {
    // Use min heap of size k
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (int num : nums) {
        heap.push(num);
        if (heap.size() > k) {
            heap.pop();
        }
    }
    
    return heap.top();
}
```

### Example: Merge K Sorted Lists
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
    
    // Add first element from each list
    for (ListNode* lst : lists) {
        if (lst) {
            heap.push(lst);
        }
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    while (!heap.empty()) {
        ListNode* node = heap.top();
        heap.pop();
        current->next = node;
        current = current->next;
        
        if (node->next) {
            heap.push(node->next);
        }
    }
    
    return dummy->next;
}
```

### Use Cases
- Priority scheduling
- Finding kth smallest/largest
- Median maintenance
- Dijkstra's algorithm
- Huffman coding

---

## Trie

### Theory
A trie (prefix tree) is a tree data structure used to store strings where each path from root to leaf represents a word. Nodes share common prefixes.

**Time Complexity:**
- Insert: O(m) where m is word length
- Search: O(m)
- Delete: O(m)

**Space Complexity:** O(ALPHABET_SIZE * m * n)

### Example: Implement Trie
```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end;
    
    TrieNode() : is_end(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};
```

### Use Cases
- Autocomplete
- Spell checker
- IP routing tables
- Dictionary implementation
- Word search games

---

## Bit Manipulation

### Theory
Bit manipulation involves operations on individual bits. Common operations include AND, OR, XOR, NOT, and bit shifts.

**Common Tricks:**
- `x & (x-1)`: Remove rightmost set bit
- `x & -x`: Get rightmost set bit
- `x ^ x`: Always 0
- `x ^ 0`: Always x
- XOR for finding unique element

**Time Complexity:** O(1) per operation

### Example: Single Number
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
```

### Example: Count Set Bits
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;  // Remove rightmost set bit
        count++;
    }
    return count;
}
```

### Example: Power of Two
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### Use Cases
- Set operations
- Counting bits
- Finding unique elements
- Bit masking
- Optimization (space/time)

---

## Backtracking

### Theory
Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally and abandoning solutions that fail to satisfy constraints.

**Time Complexity:** Often exponential O(2^n) or O(n!)
**Space Complexity:** O(n) for recursion depth

### Example: Permutations
```cpp
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    
    function<void(vector<int>&, vector<int>&)> backtrack = 
        [&](vector<int>& path, vector<int>& remaining) {
        if (remaining.empty()) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < remaining.size(); i++) {
            path.push_back(remaining[i]);
            vector<int> newRemaining;
            for (int j = 0; j < remaining.size(); j++) {
                if (j != i) newRemaining.push_back(remaining[j]);
            }
            backtrack(path, newRemaining);
            path.pop_back();
        }
    };
    
    vector<int> path;
    backtrack(path, nums);
    return result;
}
```

### Example: N-Queens
```cpp
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    
    function<bool(int, int)> is_valid = [&](int row, int col) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check diagonals
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    };
    
    function<void(int)> backtrack = [&](int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (is_valid(row, col)) {
                board[row][col] = 'Q';
                backtrack(row + 1);
                board[row][col] = '.';
            }
        }
    };
    
    backtrack(0);
    return result;
}
```

### Use Cases
- Constraint satisfaction problems
- Sudoku solver
- N-Queens problem
- Generating permutations/combinations
- Maze solving
- Graph coloring

---

## Graph

### Theory
A graph is a non-linear data structure consisting of vertices (nodes) and edges connecting them.

**Types:**
- Directed vs Undirected
- Weighted vs Unweighted
- Cyclic vs Acyclic
- Connected vs Disconnected

**Representations:**
- Adjacency Matrix: O(V²) space
- Adjacency List: O(V + E) space

### Example: Graph Representation
```cpp
// Adjacency List
unordered_map<char, vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {'A', 'D', 'E'}},
    {'C', {'A', 'F'}},
    {'D', {'B'}},
    {'E', {'B', 'F'}},
    {'F', {'C', 'E'}}
};

// Adjacency Matrix
int n = 4;
vector<vector<int>> matrix(n, vector<int>(n, 0));
matrix[0][1] = 1;  // Edge from 0 to 1
```

### Example: Number of Islands
```cpp
int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    
    function<void(int, int)> dfs = [&](int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        dfs(i+1, j);
        dfs(i-1, j);
        dfs(i, j+1);
        dfs(i, j-1);
    };
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                dfs(i, j);
                count++;
            }
        }
    }
    
    return count;
}
```

### Use Cases
- Social networks
- Road networks
- Web page links
- Dependency resolution
- Network flow

---

## Topological Sort

### Theory
Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge (u, v), vertex u comes before v.

**Requirements:** Graph must be a DAG
**Time Complexity:** O(V + E)
**Space Complexity:** O(V)

### Example: Course Schedule (Kahn's Algorithm)
```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(numCourses, 0);
    
    // Build graph
    for (auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
        indegree[prereq[0]]++;
    }
    
    // Find all nodes with no incoming edges
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return count == numCourses;
}
```

### Example: Using DFS
```cpp
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    for (auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
    }
    
    vector<int> visited(numCourses, 0);  // 0: unvisited, 1: visiting, 2: visited
    vector<int> result;
    
    function<bool(int)> dfs = [&](int node) {
        if (visited[node] == 1) {  // Cycle detected
            return false;
        }
        if (visited[node] == 2) {  // Already processed
            return true;
        }
        
        visited[node] = 1;
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor)) {
                return false;
            }
        }
        
        visited[node] = 2;
        result.push_back(node);
        return true;
    };
    
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i)) {
            return {};
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

### Use Cases
- Task scheduling
- Build systems (Makefile)
- Course prerequisites
- Dependency resolution
- Compilation order

---

## Union Find

### Theory
Union Find (Disjoint Set Union) is a data structure that keeps track of elements partitioned into disjoint sets. Supports two operations:
- Find: Determine which set an element belongs to
- Union: Merge two sets

**Optimizations:**
- Path compression
- Union by rank/size

**Time Complexity:** Nearly O(1) with optimizations (α(n))

### Example: Union Find Implementation
```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
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
    
    bool unionSets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        
        if (root_x == root_y) {
            return false;
        }
        
        // Union by rank
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
        
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### Example: Number of Connected Components
```cpp
int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    
    for (auto& edge : edges) {
        uf.unionSets(edge[0], edge[1]);
    }
    
    unordered_set<int> roots;
    for (int i = 0; i < n; i++) {
        roots.insert(uf.find(i));
    }
    
    return roots.size();
}
```

### Use Cases
- Detecting cycles in undirected graphs
- Finding connected components
- Kruskal's MST algorithm
- Network connectivity
- Image processing (connected regions)

---

## Greedy

### Theory
Greedy algorithms make locally optimal choices at each step with the hope of finding a global optimum. They don't always guarantee optimal solutions but work well for certain problems.

**Key Property:** Greedy choice property and optimal substructure

**Time Complexity:** Varies by problem

### Example: Jump Game
```cpp
bool canJump(vector<int>& nums) {
    int max_reach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > max_reach) {
            return false;
        }
        max_reach = max(max_reach, i + nums[i]);
        
        if (max_reach >= nums.size() - 1) {
            return true;
        }
    }
    
    return true;
}
```

### Example: Activity Selection
```cpp
int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<pair<int, int>> meetings;
    for (int i = 0; i < start.size(); i++) {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    
    int count = 1;
    int last_end = meetings[0].first;
    
    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i].second > last_end) {
            count++;
            last_end = meetings[i].first;
        }
    }
    
    return count;
}
```

### Example: Minimum Coins
```cpp
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    int count = 0;
    
    for (int coin : coins) {
        if (amount == 0) {
            break;
        }
        count += amount / coin;
        amount %= coin;
    }
    
    return amount == 0 ? count : -1;
}
```

### Use Cases
- Activity selection
- Huffman coding
- Fractional knapsack
- Dijkstra's shortest path
- Prim's and Kruskal's MST
- Job scheduling

---

## Summary

This document covers the fundamental algorithmic concepts and data structures commonly used in competitive programming and technical interviews. Each topic includes:
- Theoretical foundations
- Time and space complexity analysis
- Practical code examples
- Common use cases

**Tips for Problem Solving:**
1. Understand the problem thoroughly
2. Identify patterns and constraints
3. Choose appropriate data structure
4. Start with brute force, then optimize
5. Consider edge cases
6. Test with examples
7. Analyze time and space complexity

**Common Problem-Solving Patterns:**
- Two Pointers: When dealing with sorted arrays or strings
- Sliding Window: For contiguous subarray/substring problems
- Fast & Slow Pointers: For cycle detection
- In-place Reversal: For linked list problems
- BFS: For shortest path or level-by-level processing
- DFS: For exploring all paths or backtracking
- Dynamic Programming: For optimization problems with overlapping subproblems
- Greedy: When local optimum leads to global optimum

