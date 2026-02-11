# STL Mastery

## Overview
The C++ Standard Template Library provides containers, algorithms, and iterators for efficient programming.

## Essential Containers

### Vector
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
binary_search(v.begin(), v.end(), target);
lower_bound(v.begin(), v.end(), target);
upper_bound(v.begin(), v.end(), target);
```

### Other Algorithms
```cpp
reverse(v.begin(), v.end());
min_element(v.begin(), v.end());
max_element(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);
next_permutation(v.begin(), v.end());
unique(v.begin(), v.end());
```

## Tips
- Use `vector` as default container
- Use `unordered_map/set` for O(1) lookup
- Use `map/set` when you need ordering
- Reserve capacity for vectors when size known
- Prefer algorithms over manual loops
- Use `emplace` over `insert` for in-place construction

[← Back to README](README.md)
