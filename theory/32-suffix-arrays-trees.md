# Suffix Arrays and Trees

## Suffix Array

### Overview
Sorted array of all suffixes of a string. Used for pattern matching.

### Construction
```cpp
vector<int> buildSuffixArray(string s) {
    int n = s.length();
    vector<int> sa(n), rank(n), tmp(n);
    
    // Initial ranking
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }
    
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };
        
        sort(sa.begin(), sa.end(), cmp);
        
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        rank = tmp;
    }
    
    return sa;
}
```

### Applications
- Pattern matching
- Longest common substring
- Longest repeated substring
- String compression

## Suffix Tree

### Overview
Compressed trie of all suffixes. More complex but more powerful than suffix array.

### Properties
- O(n) construction (Ukkonen's algorithm)
- O(m) pattern search for pattern of length m
- Space: O(n)

### Applications
- Linear-time pattern matching
- Longest common substring
- Longest palindrome
- Finding all occurrences of pattern

## Common Problems
- Longest Repeated Substring (LeetCode #1062)
- Longest Duplicate Substring (LeetCode #1044)

## Note
Advanced topic, rarely appears in interviews.

[← Back to README](README.md)
