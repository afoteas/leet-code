# Arrays, Strings, Hash Tables

## Overview
The foundational data structures that appear in ~40% of all interview problems.

## Key Concepts

### Arrays
- Contiguous memory allocation
- O(1) random access
- Fixed size (in C/C++ without dynamic allocation)
- Cache-friendly

### Strings
- Character arrays with null terminator in C++
- `std::string` provides dynamic sizing
- Important methods: `substr()`, `find()`, `compare()`

### Hash Tables
- O(1) average case lookup/insert/delete
- Trade space for time
- Handle collisions: chaining vs open addressing

## C++ Implementation

### std::vector
```cpp
#include <vector>

std::vector<int> arr = {1, 2, 3, 4, 5};
arr.push_back(6);           // Add element
arr.pop_back();             // Remove last
arr.size();                 // Get size
arr[0];                     // Access (no bounds check)
arr.at(0);                  // Access (with bounds check)
```

### std::string
```cpp
#include <string>

std::string s = "hello";
s += " world";              // Concatenation
s.length();                 // Get length
s.substr(0, 5);            // Substring
s.find("world");           // Find substring
```

### std::unordered_map (Hash Table)
```cpp
#include <unordered_map>

std::unordered_map<int, int> hash;
hash[key] = value;          // Insert/update
hash.count(key);            // Check existence
hash.erase(key);            // Remove
hash.find(key);             // Get iterator
```

### std::unordered_set
```cpp
#include <unordered_set>

std::unordered_set<int> set;
set.insert(5);              // Add element
set.count(5);               // Check if exists
set.erase(5);               // Remove
```

## Common Patterns

### 1. Two-Pass Hash Table
```cpp
// Count frequency
unordered_map<char, int> freq;
for (char c : s) {
    freq[c]++;
}
```

### 2. Hash Table for O(1) Lookup
```cpp
// Two Sum pattern
unordered_map<int, int> seen;
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (seen.count(complement)) {
        return {seen[complement], i};
    }
    seen[nums[i]] = i;
}
```

### 3. String Building
```cpp
// Prefer string concatenation for small strings
string result = "";
for (char c : s) {
    result += c;  // OK for small strings
}

// For large strings, use stringstream or reserve
string result;
result.reserve(1000);  // If you know the size
```

## Common Problems
- Two Sum (LeetCode #1)
- Valid Anagram (LeetCode #242)
- Group Anagrams (LeetCode #49)
- Longest Substring Without Repeating Characters (LeetCode #3)
- Subarray Sum Equals K (LeetCode #560)

## Time Complexities
| Operation | Array | String | Hash Table |
|-----------|-------|--------|------------|
| Access    | O(1)  | O(1)   | O(1) avg   |
| Insert    | O(n)  | O(n)   | O(1) avg   |
| Delete    | O(n)  | O(n)   | O(1) avg   |
| Search    | O(n)  | O(n)   | O(1) avg   |

## Tips
- Use `unordered_map` for O(1) lookups
- Use `map` (ordered) when you need sorted keys
- Strings are immutable - concatenation creates new strings
- `vector::reserve()` to avoid reallocations
- Use `emplace_back()` instead of `push_back()` for construction in-place

[← Back to README](README.md)
