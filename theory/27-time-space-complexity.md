# Time/Space Complexity

## Overview
Analysis of algorithm efficiency in terms of time and space.

## Big O Notation

### Common Time Complexities (Best to Worst)
- **O(1)**: Constant - array access, hash table lookup
- **O(log n)**: Logarithmic - binary search
- **O(n)**: Linear - array traversal
- **O(n log n)**: Linearithmic - merge sort, heap sort
- **O(n²)**: Quadratic - nested loops, bubble sort
- **O(2^n)**: Exponential - recursive fibonacci
- **O(n!)**: Factorial - permutations

### Graph
```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2^n) < O(n!)
```

## Calculating Complexity

### Rules
1. Drop constants: O(2n) → O(n)
2. Drop smaller terms: O(n² + n) → O(n²)
3. Different inputs use different variables: O(a + b)

### Examples
```cpp
// O(n)
for (int i = 0; i < n; i++) {
    // O(1) operation
}

// O(n²)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) operation
    }
}

// O(log n)
while (n > 1) {
    n /= 2;
}

// O(n log n)
for (int i = 0; i < n; i++) {
    int m = n;
    while (m > 1) {
        m /= 2;
    }
}
```

## Space Complexity

### Analysis
- Input space (doesn't count)
- Auxiliary space (algorithm uses)
- Total space = Input + Auxiliary

### Examples
```cpp
// O(1) space
int sum(int n) {
    return n * (n + 1) / 2;
}

// O(n) space
vector<int> createArray(int n) {
    return vector<int>(n);
}

// O(n) space (recursion stack)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## Amortized Analysis

### Example: Dynamic Array
- Most insertions: O(1)
- Occasional resize: O(n)
- **Amortized**: O(1) per insertion

## Common Data Structure Complexities

| Structure | Access | Search | Insert | Delete | Space |
|-----------|--------|--------|--------|--------|-------|
| Array | O(1) | O(n) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(n) | O(1) | O(1) | O(n) |
| Hash Table | - | O(1)* | O(1)* | O(1)* | O(n) |
| Binary Search Tree | O(log n)* | O(log n)* | O(log n)* | O(log n)* | O(n) |
| Heap | - | O(n) | O(log n) | O(log n) | O(n) |

*Average case

[← Back to README](README.md)
