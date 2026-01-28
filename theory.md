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
```python
def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []
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
```python
def maxSubArray(nums):
    max_sum = current_sum = nums[0]
    for num in nums[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum
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
```python
def maxSumSubarray(arr, k):
    if len(arr) < k:
        return -1
    
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    for i in range(k, len(arr)):
        window_sum = window_sum - arr[i-k] + arr[i]
        max_sum = max(max_sum, window_sum)
    
    return max_sum
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
```python
def maxArea(height):
    left, right = 0, len(height) - 1
    max_area = 0
    
    while left < right:
        width = right - left
        max_area = max(max_area, min(height[left], height[right]) * width)
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_area
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
```python
def merge(intervals):
    if not intervals:
        return []
    
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    
    for current in intervals[1:]:
        if current[0] <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], current[1])
        else:
            merged.append(current)
    
    return merged
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
```python
def isValid(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    
    for char in s:
        if char in mapping:
            top = stack.pop() if stack else '#'
            if mapping[char] != top:
                return False
        else:
            stack.append(char)
    
    return not stack
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
```python
from collections import deque

class MovingAverage:
    def __init__(self, size):
        self.size = size
        self.queue = deque()
        self.sum = 0
    
    def next(self, val):
        self.queue.append(val)
        self.sum += val
        
        if len(self.queue) > self.size:
            self.sum -= self.queue.popleft()
        
        return self.sum / len(self.queue)
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
```python
def fibonacci(n):
    # Base cases
    if n <= 1:
        return n
    # Recursive case
    return fibonacci(n-1) + fibonacci(n-2)

# Optimized with memoization
def fibonacci_memo(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fibonacci_memo(n-1, memo) + fibonacci_memo(n-2, memo)
    return memo[n]
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
```python
def mergeSort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])
    
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result
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
```python
def climbStairs(n):
    if n <= 2:
        return n
    
    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 2
    
    for i in range(3, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]
```

### Example: Longest Common Subsequence
```python
def longestCommonSubsequence(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]
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
```python
def binarySearch(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1
```

### Example: Find First and Last Position
```python
def searchRange(nums, target):
    def findBound(isFirst):
        left, right = 0, len(nums) - 1
        result = -1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                result = mid
                if isFirst:
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return result
    
    return [findBound(True), findBound(False)]
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
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head):
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev
```

### Example: Detect Cycle (Floyd's Algorithm)
```python
def hasCycle(head):
    if not head or not head.next:
        return False
    
    slow = fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return True
    
    return False
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
```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
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
```python
def maxDepth(root):
    if not root:
        return 0
    return 1 + max(maxDepth(root.left), maxDepth(root.right))
```

### Example: Level Order Traversal
```python
from collections import deque

def levelOrder(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        level = []
        
        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level)
    
    return result
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
```python
def isValidBST(root):
    def validate(node, low=float('-inf'), high=float('inf')):
        if not node:
            return True
        
        if node.val <= low or node.val >= high:
            return False
        
        return (validate(node.left, low, node.val) and
                validate(node.right, node.val, high))
    
    return validate(root)
```

### Example: Insert Node
```python
def insertIntoBST(root, val):
    if not root:
        return TreeNode(val)
    
    if val < root.val:
        root.left = insertIntoBST(root.left, val)
    else:
        root.right = insertIntoBST(root.right, val)
    
    return root
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
```python
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    
    visited.add(start)
    print(start)
    
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    
    return visited
```

### Example: Path Sum
```python
def hasPathSum(root, targetSum):
    if not root:
        return False
    
    if not root.left and not root.right:
        return root.val == targetSum
    
    return (hasPathSum(root.left, targetSum - root.val) or
            hasPathSum(root.right, targetSum - root.val))
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
```python
from collections import deque

def bfs(graph, start):
    visited = set([start])
    queue = deque([start])
    
    while queue:
        vertex = queue.popleft()
        print(vertex)
        
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    
    return visited
```

### Example: Shortest Path in Binary Matrix
```python
def shortestPathBinaryMatrix(grid):
    if grid[0][0] == 1:
        return -1
    
    n = len(grid)
    queue = deque([(0, 0, 1)])  # row, col, distance
    grid[0][0] = 1
    
    directions = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
    
    while queue:
        row, col, dist = queue.popleft()
        
        if row == n-1 and col == n-1:
            return dist
        
        for dr, dc in directions:
            r, c = row + dr, col + dc
            if 0 <= r < n and 0 <= c < n and grid[r][c] == 0:
                grid[r][c] = 1
                queue.append((r, c, dist + 1))
    
    return -1
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
```python
import heapq

def findKthLargest(nums, k):
    # Use min heap of size k
    heap = []
    
    for num in nums:
        heapq.heappush(heap, num)
        if len(heap) > k:
            heapq.heappop(heap)
    
    return heap[0]
```

### Example: Merge K Sorted Lists
```python
def mergeKLists(lists):
    heap = []
    
    # Add first element from each list
    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst.val, i, lst))
    
    dummy = ListNode(0)
    current = dummy
    
    while heap:
        val, i, node = heapq.heappop(heap)
        current.next = node
        current = current.next
        
        if node.next:
            heapq.heappush(heap, (node.next.val, i, node.next))
    
    return dummy.next
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
```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True
    
    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end
    
    def startsWith(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True
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
```python
def singleNumber(nums):
    result = 0
    for num in nums:
        result ^= num
    return result
```

### Example: Count Set Bits
```python
def hammingWeight(n):
    count = 0
    while n:
        n &= n - 1  # Remove rightmost set bit
        count += 1
    return count
```

### Example: Power of Two
```python
def isPowerOfTwo(n):
    return n > 0 and (n & (n - 1)) == 0
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
```python
def permute(nums):
    result = []
    
    def backtrack(path, remaining):
        if not remaining:
            result.append(path[:])
            return
        
        for i in range(len(remaining)):
            backtrack(path + [remaining[i]], 
                     remaining[:i] + remaining[i+1:])
    
    backtrack([], nums)
    return result
```

### Example: N-Queens
```python
def solveNQueens(n):
    result = []
    board = [['.'] * n for _ in range(n)]
    
    def is_valid(row, col):
        # Check column
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        
        # Check diagonals
        for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
            if board[i][j] == 'Q':
                return False
        
        for i, j in zip(range(row-1, -1, -1), range(col+1, n)):
            if board[i][j] == 'Q':
                return False
        
        return True
    
    def backtrack(row):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        
        for col in range(n):
            if is_valid(row, col):
                board[row][col] = 'Q'
                backtrack(row + 1)
                board[row][col] = '.'
    
    backtrack(0)
    return result
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
```python
# Adjacency List
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# Adjacency Matrix
n = 4
matrix = [[0] * n for _ in range(n)]
matrix[0][1] = 1  # Edge from 0 to 1
```

### Example: Number of Islands
```python
def numIslands(grid):
    if not grid:
        return 0
    
    count = 0
    
    def dfs(i, j):
        if (i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or
            grid[i][j] == '0'):
            return
        
        grid[i][j] = '0'
        dfs(i+1, j)
        dfs(i-1, j)
        dfs(i, j+1)
        dfs(i, j-1)
    
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '1':
                dfs(i, j)
                count += 1
    
    return count
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
```python
from collections import deque, defaultdict

def canFinish(numCourses, prerequisites):
    graph = defaultdict(list)
    indegree = [0] * numCourses
    
    # Build graph
    for course, prereq in prerequisites:
        graph[prereq].append(course)
        indegree[course] += 1
    
    # Find all nodes with no incoming edges
    queue = deque([i for i in range(numCourses) if indegree[i] == 0])
    count = 0
    
    while queue:
        node = queue.popleft()
        count += 1
        
        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    
    return count == numCourses
```

### Example: Using DFS
```python
def findOrder(numCourses, prerequisites):
    graph = defaultdict(list)
    for course, prereq in prerequisites:
        graph[prereq].append(course)
    
    visited = [0] * numCourses  # 0: unvisited, 1: visiting, 2: visited
    result = []
    
    def dfs(node):
        if visited[node] == 1:  # Cycle detected
            return False
        if visited[node] == 2:  # Already processed
            return True
        
        visited[node] = 1
        for neighbor in graph[node]:
            if not dfs(neighbor):
                return False
        
        visited[node] = 2
        result.append(node)
        return True
    
    for i in range(numCourses):
        if not dfs(i):
            return []
    
    return result[::-1]
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
```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        
        if root_x == root_y:
            return False
        
        # Union by rank
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
        
        return True
    
    def connected(self, x, y):
        return self.find(x) == self.find(y)
```

### Example: Number of Connected Components
```python
def countComponents(n, edges):
    uf = UnionFind(n)
    
    for u, v in edges:
        uf.union(u, v)
    
    return len(set(uf.find(i) for i in range(n)))
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
```python
def canJump(nums):
    max_reach = 0
    
    for i in range(len(nums)):
        if i > max_reach:
            return False
        max_reach = max(max_reach, i + nums[i])
        
        if max_reach >= len(nums) - 1:
            return True
    
    return True
```

### Example: Activity Selection
```python
def maxMeetings(start, end):
    meetings = sorted(zip(start, end), key=lambda x: x[1])
    count = 1
    last_end = meetings[0][1]
    
    for s, e in meetings[1:]:
        if s > last_end:
            count += 1
            last_end = e
    
    return count
```

### Example: Minimum Coins
```python
def coinChange(coins, amount):
    coins.sort(reverse=True)
    count = 0
    
    for coin in coins:
        if amount == 0:
            break
        count += amount // coin
        amount %= coin
    
    return count if amount == 0 else -1
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

