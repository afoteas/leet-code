# Two Pointers / Sliding Window

## Overview
Two powerful optimization techniques that reduce **O(n²)** brute force solutions to **O(n)** by intelligently moving pointers through data.

### The Core Insight
**Brute Force**: Check every pair/subarray → O(n²)
```cpp
// Check all pairs
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        // Process pair/subarray [i, j]
    }
}
// Time: O(n²) - wasteful!
```

**Two Pointers/Sliding Window**: Move pointers smartly → O(n)
```cpp
// Each pointer moves through array at most once
int left = 0;
for (int right = 0; right < n; right++) {
    // Process in one pass
    while (/* condition */) left++;
}
// Time: O(n) - efficient!
```

**Why It Works**: We maintain **invariants** that let us skip impossible combinations.

## Two Pointers Pattern

### Three Types

**1. Opposite Direction** (converging pointers)
```
Array: [1, 2, 3, 4, 5, 6, 7, 8]
        ↑                    ↑
       left                right
       
Move toward each other based on condition
Use case: Two Sum in sorted array, palindrome check
```

**2. Same Direction** (fast and slow)
```
Array: [1, 2, 3, 4, 5, 6, 7, 8]
        ↑  ↑
      slow fast
      
Fast pointer explores, slow pointer follows
Use case: Remove duplicates, linked list cycle
```

**3. Sliding Window** (expanding/contracting)
```
Array: [1, 2, 3, 4, 5, 6, 7, 8]
           ↑        ↑
         left     right
         
Window [left, right] slides or expands
Use case: Subarray problems, substring problems
```

### When to Use Two Pointers

✅ **Sorted array** → Opposite direction
✅ **Palindrome** → Opposite direction  
✅ **Remove duplicates** → Same direction
✅ **Find pair with sum** → Opposite direction
✅ **Linked list cycle** → Fast & slow (Floyd's algorithm)

### Template: Opposite Direction
```cpp
int left = 0, right = n - 1;

while (left < right) {
    int sum = arr[left] + arr[right];  // Or other condition
    
    if (sum == target) {
        // Found answer!
        return {left, right};
    } 
    else if (sum < target) {
        left++;   // Need larger sum
    } 
    else {
        right--;  // Need smaller sum
    }
}
```

### Example: Two Sum in Sorted Array

**Visual Walkthrough**
```
Array: [2, 7, 11, 15], Target: 9

Step 1: [2, 7, 11, 15]   left=0, right=3
         ↑           ↑
        sum = 2 + 15 = 17 > 9
        Too large! Move right pointer left
        
Step 2: [2, 7, 11, 15]   left=0, right=2
         ↑      ↑
        sum = 2 + 11 = 13 > 9
        Still too large! Move right left again
        
Step 3: [2, 7, 11, 15]   left=0, right=1
         ↑  ↑
        sum = 2 + 7 = 9 ✓
        Found it!
```

**Why This Works**
- Array is sorted
- If sum too large → right-- (only way to decrease)
- If sum too small → left++ (only way to increase)
- We never miss the answer because we eliminate impossible pairs

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        
        if (sum == target) {
            return {left + 1, right + 1};  // 1-indexed
        } 
        else if (sum < target) {
            // Need larger sum → move left pointer right
            left++;
        } 
        else  {
            // Need smaller sum → move right pointer left
            right--;
        }
    }
    
    return {};  // No solution
}
```

## Sliding Window Pattern

### The Window Concept
A "window" is a **contiguous subarray** that slides or expands through the array.

```
Fixed Window (size k=3):
Array: [1, 3, 2, 6, -1, 4, 1, 8, 2]
       [1, 3, 2] 6, -1, 4, 1, 8, 2     sum=6
        1,[3, 2, 6]-1, 4, 1, 8, 2     sum=11
        1, 3,[2, 6,-1] 4, 1, 8, 2     sum=7
           ...
Window slides right, maintaining size k

Variable Window:
Array: [a, b, c, a, b, c, b, b]
       [a, b, c] ← all unique, expand
       [a, b, c, a] ← duplicate 'a', contract from left
       ...
Window expands/contracts based on condition
```

### When to Use Sliding Window

✅ **Contiguous subarray/substring** required
✅ **"Find max/min/longest/shortest subarray that..."**
✅ **Keywords**: "consecutive", "contiguous", "window of size k"
✅ **All subarrays** but with optimization (not checking all pairs)

### Pattern 1: Fixed-Size Window

**Problem Type**: "Find max sum of subarray of length k"

```cpp
// Example: Max sum of k consecutive elements
int maxSum(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    
    // Step 1: Compute sum of first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    
    // Step 2: Slide the window
    for (int i = k; i < n; i++) {
        // Slide: Remove leftmost, add rightmost
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}

// Time: O(n) - each element added/removed once
// Space: O(1)
```

**Visual Example**:
```
Array: [2, 1, 5, 1, 3, 2], k = 3

Window 1: [2, 1, 5] → sum = 8
Window 2: [1, 5, 1] → sum = 8 - 2 + 1 = 7
Window 3: [5, 1, 3] → sum = 7 - 1 + 3 = 9 ← max
Window 4: [1, 3, 2] → sum = 9 - 5 + 2 = 6

Max = 9
```

### Pattern 2: Variable-Size Window

**Problem Type**: "Find longest/shortest subarray satisfying condition"

**The Two-Pointer Dance**:
1. **Expand** right pointer to explore new elements
2. **Contract** left pointer when window becomes invalid
3. **Track** the best window seen so far

```cpp
// General template
int left = 0, result = 0;
// State tracking (hash map, counters, etc.)

for (int right = 0; right < n; right++) {
    // Step 1: Add arr[right] to window
    // Update window state
    
    // Step 2: Shrink window while invalid
    while (/* window is invalid */) {
        // Remove arr[left] from window
        left++;
    }
    
    // Step 3: Update result if current window is valid
    result = max(result, right - left + 1);
}

return result;
```

### Fixed-Size Window Template
```cpp
int windowSum = 0;
for (int i = 0; i < k; i++) {
    windowSum += arr[i];
}

int maxSum = windowSum;
for (int i = k; i < n; i++) {
    windowSum = windowSum - arr[i - k] + arr[i];
    maxSum = max(maxSum, windowSum);
}
```

### Example: Longest Substring Without Repeating Characters

**Visual Simulation**
```
String: "abcabcbb"

Step 1: "a|bcabcbb"       window="a"        maxLen=1
         ↑
        left=0, right=0
        
Step 2: "ab|cabcbb"       window="ab"       maxLen=2
         ↑ ↑
        left=0, right=1
        
Step 3: "abc|abcbb"       window="abc"      maxLen=3
         ↑  ↑
        left=0, right=2
        
Step 4: "abc|a|bcbb"      'a' repeats!
         ↑   ↑           Contract: remove 'a' from left
        left=0, right=3  window="bca"       maxLen=3
                ↑
               new left=1
               
Step 5: "abc|ab|cbb"      'b' repeats!
            ↑  ↑         Contract: remove 'b','c' from left  
           left=1 right=4 window="cab"      maxLen=3
                  ↑
                 new left=3
                 
... continues ...

Final maxLen = 3 ("abc" or "bca" or "cab")
```

**Why It Works**:
- Right expands window → adds new character
- If duplicate found → left contracts until no duplicates
- Each character added/removed at most once → O(n)

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;  // Tracks characters in current window
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        // Expand: Try to add s[right]
        
        // Contract: While s[right] already in window
        while (window.count(s[right])) {
            window.erase(s[left]);  // Remove from left
            left++;                 // Shrink window
        }
        
        // Now s[right] not in window, safe to add
        window.insert(s[right]);
        
        // Update max length seen
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

// Time: O(n) - each character enters/exits window once
// Space: O(min(n, k)) - k = alphabet size
```

## Common Patterns & Mistakes

### Mistake 1: Not Resetting Window Properly
```cpp
// WRONG - Window state not maintained correctly
while (window invalid) {
    left++;  // Forgot to remove arr[left] from window state!
}

// CORRECT
while (window invalid) {
    // MUST update state before moving pointer
    removeFromWindow(arr[left]);
    left++;
}
```

### Mistake 2: Checking Condition After Loop
```cpp
// WRONG - Can miss the last window
for (int right = 0; right < n; right++) {
    add(arr[right]);
    while (invalid) {
        remove(arr[left++]);
    }
}
// Missing: check if current window is best!

// CORRECT
for (int right = 0; right < n; right++) {
    add(arr[right]);
    while (invalid) {
        remove(arr[left++]);
    }
    updateResult();  // Check INSIDE loop
}
```

### Mistake 3: Wrong Window Size Calculation
```cpp
// Window size = right - left + 1

window = [3, 1, 4, 1, 5]
         ↑        ↑
       left=0  right=4
       
Size = 4 - 0 + 1 = 5 ✓
NOT right - left = 4 ✗
```

### Pattern Recognition

**Two Pointers (Opposite)**
- "Find pair with sum = k" in **sorted** array
- "Is palindrome?"
- "Remove element" with two pointers

**Two Pointers (Same Direction)**  
- "Remove duplicates"
- "Move zeros to end"
- Fast & slow (cycle detection)

**Sliding Window (Fixed)**
- "Max sum of k consecutive elements"
- "Avg of k consecutive elements"

**Sliding Window (Variable)**
- "Longest substring with..."
- "Shortest subarray with sum ≥ k"
- "Min window substring"

## Practice Strategy

### Level 1: Two Pointers Basics
1. **Two Sum II** (LeetCode #167) - Sorted array, opposite pointers
2. **Valid Palindrome** (LeetCode #125) - Opposite pointers
3. **Remove Duplicates from Sorted Array** (LeetCode #26) - Same direction

### Level 2: Fixed Window
4. **Maximum Average Subarray I** (LeetCode #643) - Fixed window basics
5. **Min Sub Array Len** (LeetCode #209) - Variable window intro

### Level 3: Variable Window  
6. **Longest Substring Without Repeating Characters** (LeetCode #3) - Classic
7. **Longest Repeating Character Replacement** (LeetCode #424) - With constraint
8. **Permutation in String** (LeetCode #567) - Sliding + hash map

### Level 4: Advanced
9. **Minimum Window Substring** (LeetCode #76) - Hard but important
10. **Sliding Window Maximum** (LeetCode #239) - With deque
11. **Subarrays with K Different Integers** (LeetCode #992) - Tricky

## Quick Reference

### Two Pointers Template
```cpp
// Opposite direction
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // process
        left++; right--;
    } else if (need_larger) {
        left++;
    } else {
        right--;
    }
}
```

### Fixed Window Template
```cpp
for (int i = 0; i < k; i++) sum += arr[i];
int maxSum = sum;
for (int i = k; i < n; i++) {
    sum = sum - arr[i-k] + arr[i];
    maxSum = max(maxSum, sum);
}
```

### Variable Window Template
```cpp
int left = 0, result = 0;
for (int right = 0; right < n; right++) {
    addToWindow(arr[right]);
    while (windowInvalid()) {
        removeFromWindow(arr[left++]);
    }
    result = max(result, right - left + 1);
}
```

## Time & Space Complexity

| Pattern | Time | Space | Notes |
|---------|------|-------|-------|
| Two Pointers | O(n) | O(1) | Each pointer moves once |
| Fixed Window | O(n) | O(1) | Slide through array once |
| Variable Window | O(n) | O(k) | k = window state size |
| Window + Hash Map | O(n) | O(k) | k = unique elements |

[← Back to README](README.md)
