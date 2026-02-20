# STL Mastery

## Overview
The C++ Standard Template Library provides containers, algorithms, and iterators for efficient programming.

## Essential Containers

### Array (Fixed Size, Stack Allocated)
```cpp
#include <array>

array<int, 5> arr = {1, 2, 3, 4, 5};
arr[0] = 10;
arr.at(1) = 20;  // With bounds checking
arr.front();
arr.back();
arr.size();  // Always 5
arr.fill(0);  // Fill all with 0
// arr.push_back(6);  // ✗ Cannot resize

// Best for: Known size, max performance
// Stack allocated, zero overhead
```

### Vector (Dynamic, Heap Allocated)
```cpp
#include <vector>

vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
v.size();
v.empty();
v.clear();
v[0];  // No bounds checking
v.at(0);  // With bounds checking
v.front();
v.back();
v.reserve(100);  // Pre-allocate
v.resize(10);

// Best for: Dynamic size, flexibility
```

### Map (Ordered)
```cpp
#include <map>

map<int, string> m;
m[1] = "one";
m.insert({2, "two"});
m.erase(1);
m.count(1);  // 0 or 1
m.find(1);  // Returns iterator
m.lower_bound(key);
m.upper_bound(key);
```

### Unordered Map (Hash Table)
```cpp
#include <unordered_map>

unordered_map<int, int> um;
um[key] = value;
um.count(key);
um.find(key);
um.erase(key);
```

### Set (Ordered)
```cpp
#include <set>

set<int> s;
s.insert(5);
s.erase(5);
s.count(5);
s.lower_bound(5);
s.upper_bound(5);
```

### Unordered Set
```cpp
#include <unordered_set>

unordered_set<int> us;
us.insert(5);
us.erase(5);
us.count(5);
```

### Deque (Double-Ended Queue)
```cpp
#include <deque>

deque<int> dq;
dq.push_back(1);   // Add to end
dq.push_front(2);  // Add to front
dq.pop_back();     // Remove from end
dq.pop_front();    // Remove from front
dq.front();
dq.back();
dq[0];  // Random access

// Best for: Need fast insertion/deletion at both ends
```

### Stack (LIFO)
```cpp
#include <stack>

stack<int> st;
st.push(1);
st.push(2);
st.top();     // Returns 2
st.pop();     // Removes 2
st.empty();
st.size();

// Best for: DFS, expression evaluation, undo operations
```

### Queue (FIFO)
```cpp
#include <queue>

queue<int> q;
q.push(1);
q.push(2);
q.front();    // Returns 1
q.back();     // Returns 2
q.pop();      // Removes 1
q.empty();
q.size();

// Best for: BFS, task scheduling
```

### Priority Queue (Max Heap by default)
```cpp
#include <queue>

// Max heap
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(5);
pq.top();     // Returns 5 (largest)
pq.pop();     // Removes 5

// Min heap
priority_queue<int, vector<int>, greater<int>> minPq;
minPq.push(3);
minPq.push(1);
minPq.top();  // Returns 1 (smallest)

// Custom comparator
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> customPq(cmp);

// Best for: Dijkstra, kth largest/smallest, median finding
```

## STL Algorithms

### Sorting
```cpp
#include <algorithm>

sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
```

### Binary Search
```cpp
#include <algorithm>

// Returns true if element exists, false otherwise
bool found = binary_search(v.begin(), v.end(), target);

// Returns iterator to first element >= target
auto it1 = lower_bound(v.begin(), v.end(), target);
// Use case: Find insertion position, count elements >= target
int pos = lower_bound(v.begin(), v.end(), target) - v.begin();

// Returns iterator to first element > target
auto it2 = upper_bound(v.begin(), v.end(), target);
// Use case: Find range of equal elements
int count = upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target);

// Example:
vector<int> v = {1, 2, 2, 2, 3, 4, 5};
binary_search(v.begin(), v.end(), 2);  // true
lower_bound(v.begin(), v.end(), 2);    // Points to first 2 (index 1)
upper_bound(v.begin(), v.end(), 2);    // Points to 3 (index 4)

// NOTE: Vector MUST be sorted for binary search!
```

### Linear Search (No Sorting Required)
```cpp
#include <algorithm>

// Find first occurrence (returns iterator)
auto it = find(v.begin(), v.end(), value);
if (it != v.end()) {
    int index = it - v.begin();  // Found at this index
    int val = *it;  // The value
} else {
    // Not found
}
// Time: O(n), works on unsorted data

// Find with custom condition
auto it2 = find_if(v.begin(), v.end(), [](int x) { return x > 10; });
// Finds first element > 10

// Find element NOT matching condition
auto it3 = find_if_not(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
// Finds first odd number

// Count occurrences
int cnt = count(v.begin(), v.end(), value);

// Count with condition
int evenCnt = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

// Check if any element satisfies condition
bool hasPositive = any_of(v.begin(), v.end(), [](int x) { return x > 0; });

// Check if all elements satisfy condition
bool allPositive = all_of(v.begin(), v.end(), [](int x) { return x > 0; });

// Check if none satisfy condition
bool noneNegative = none_of(v.begin(), v.end(), [](int x) { return x < 0; });
```

### Other Algorithms
```cpp
#include <algorithm>
#include <numeric>  // For accumulate

// Reverse elements in-place
reverse(v.begin(), v.end());
// Example: {1,2,3} → {3,2,1}

// Find minimum element (returns iterator)
auto minIt = min_element(v.begin(), v.end());
int minVal = *minIt;  // Dereference to get value
int minIdx = minIt - v.begin();  // Get index

// Find maximum element (returns iterator)
auto maxIt = max_element(v.begin(), v.end());
int maxVal = *maxIt;

// Sum all elements (third parameter is initial value)
int sum = accumulate(v.begin(), v.end(), 0);
// For long long: accumulate(v.begin(), v.end(), 0LL);

// Generate next permutation (in lexicographical order)
vector<int> v = {1, 2, 3};
do {
    // Process permutation
} while(next_permutation(v.begin(), v.end()));
// Generates: {1,2,3} → {1,3,2} → {2,1,3} → {2,3,1} → {3,1,2} → {3,2,1}

// Remove consecutive duplicates (returns new end iterator)
auto newEnd = unique(v.begin(), v.end());
v.erase(newEnd, v.end());  // Actually remove them
// Example: {1,1,2,2,3} → {1,2,3}
// NOTE: Vector MUST be sorted first for removing all duplicates!

// Other useful algorithms:
replace(v.begin(), v.end(), old, new);  // Replace all occurrences
fill(v.begin(), v.end(), value);   // Fill with value
copy(v1.begin(), v1.end(), v2.begin());  // Copy elements
swap(v1, v2);  // Swap two containers
```

## Container Selection Guide

| Need | Use |
|------|-----|
| Fixed size, max performance | `array` |
| Dynamic array | `vector` |
| Fast both ends | `deque` |
| LIFO (Last In First Out) | `stack` |
| FIFO (First In First Out) | `queue` |
| Always get min/max | `priority_queue` |
| Fast lookup, no order | `unordered_map/set` |
| Ordered data | `map/set` |

## Performance Comparison

| Operation | array | vector | deque | stack/queue | priority_queue |
|-----------|-------|--------|-------|-------------|----------------|
| Access | O(1) | O(1) | O(1) | O(1) top | O(1) top |
| Insert front | - | O(n) | O(1) | - | - |
| Insert back | - | O(1)* | O(1) | O(1) | O(log n) |
| Remove front | - | O(n) | O(1) | O(1) | - |
| Remove back | - | O(1) | O(1) | O(1) | O(log n) |
| Memory | Stack | Heap | Heap | Heap | Heap |

*Amortized O(1) for vector push_back

## Tips
- Use `array` when size known at compile time (fastest)
- Use `vector` as default dynamic container
- Use `deque` for queue/stack if you need both ends
- Use `unordered_map/set` for O(1) lookup
- Use `map/set` when you need ordering
- Use `priority_queue` for always getting min/max
- Reserve capacity for vectors when size known
- Prefer algorithms over manual loops
- Use `emplace` over `insert` for in-place construction

[← Back to README](README.md)
