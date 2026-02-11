# Binary Search

## Overview
Binary search is an efficient **O(log n)** search algorithm that works on **sorted** arrays by repeatedly dividing the search space in half.

### The Core Idea
*"Cut the problem in half, over and over, until you find what you're looking for."*

### Why So Fast?
```
Linear search: Check each element one by one
Array of 1,000,000 elements: Up to 1,000,000 comparisons ❌

Binary search: Eliminate half each time
Array of 1,000,000 elements: Only ~20 comparisons! ✓

Why? log₂(1,000,000) ≈ 20
```

### Visual Example
```
Array: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
Target: 13

Step 1: [1, 3, 5, 7, 9, |11|, 13, 15, 17, 19]
        left=0, right=9, mid=4 (value=9)
        9 < 13, search right half
        
Step 2: [11, |13|, 15, 17, 19]
        left=5, right=9, mid=7 (value=15)
        15 > 13, search left half
        
Step 3: [11, |13|]
        left=5, right=6, mid=5 (value=11)
        11 < 13, search right half
        
Step 4: [|13|]
        left=6, right=6, mid=6 (value=13)
        Found! ✓
        
Only 4 comparisons instead of scanning all elements!
```

## Basic Template

### Standard Binary Search with Detailed Explanation
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0;                    // Start of search space
    int right = nums.size() - 1;     // End of search space
    
    // CRITICAL: Use <= not <
    // Why? When left==right, we still have one element to check!
    while (left <= right) {
        // CRITICAL: Avoid integer overflow
        // (left + right) / 2 can overflow if left + right > INT_MAX
        // left + (right - left) / 2 is always safe
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;  // Found it!
        } 
        else if (nums[mid] < target) {
            // Target is in right half
            left = mid + 1;  // CRITICAL: +1 to exclude mid
        } 
        else {
            // Target is in left half
            right = mid - 1;  // CRITICAL: -1 to exclude mid
        }
    }
    
    // Loop ended: left > right, target not found
    return -1;
}
```

### The Three Critical Choices

Every binary search implementation requires three crucial decisions:

**1. Loop Condition: `while (left <= right)` vs `while (left < right)`**
```cpp
// Use left <= right when:
// - Checking all elements including when left==right
// - Standard binary search

while (left <= right) {  // Most common
    // ... search ...
}

// Use left < right when:
// - Finding boundaries/positions
// - Want to end with left==right

while (left < right) {  // Less common
    // ... search ...
}
```

**2. Mid Point Calculation**
```cpp
// WRONG - Integer overflow possible!
int mid = (left + right) / 2;

// CORRECT - Safe from overflow
int mid = left + (right - left) / 2;

// ALSO CORRECT (C++ unsigned trick)
int mid = (left + right) >> 1;  // Bit shift
```

**3. Update Rules: `mid + 1` vs `mid`**
```cpp
// Standard: Exclude mid (already checked)
left = mid + 1;   // Mid is too small, don't check again
right = mid - 1;  // Mid is too large, don't check again

// Boundary search: Include mid (might be answer)
left = mid;       // Special cases only
right = mid;      // Special cases only
```

### Common Loop Invariants
```
Invariant 1: nums[left-1] < target < nums[right+1]
- Used in standard search
- Left moves right, right moves left
- They meet when element found or proven absent

Invariant 2: nums[left] might be answer, nums[right+1] definitely not
- Used for finding boundaries
- Looking for leftmost valid position

Invariant 3: nums[right] might be answer, nums[left-1] definitely not
- Used for finding boundaries  
- Looking for rightmost valid position
```

## Variations

### 1. Find First Occurrence (Lower Bound)
```cpp
int findFirst(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;  // Continue searching left
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### 2. Find Last Occurrence (Upper Bound)
```cpp
int findLast(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;  // Continue searching right
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### 3. Search Insert Position
```cpp
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;  // Insert position
}
```

## Advanced Pattern: Binary Search on Answer Space

### The Paradigm Shift
Instead of searching for an **element**, search for an **answer** to a problem!

**Key Insight**: If you can **verify** a solution in O(n), you can **find** the optimal solution in O(n log(answer_range)).

### When to Use
Look for keywords:
- "Minimize the maximum..."
- "Maximize the minimum..."
- "Find the smallest/largest value such that..."

### Template
```cpp
// Check if answer 'mid' is achievable
bool canAchieve(int mid, /* other params */) {
    // Simulate/check if mid works
    // Return true if possible, false otherwise
    return true/false;
}

int binarySearchOnAnswer(int lo, int hi) {
    int result = hi;  // Or lo, depending on what we're finding
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        // Can we achieve answer 'mid'?
        if (canAchieve(mid)) {
            result = mid;        // mid works! Save it
            hi = mid - 1;        // Try to find smaller (for minimize)
            // OR
            // lo = mid + 1;     // Try to find larger (for maximize)
        } else {
            lo = mid + 1;        // mid doesn't work, try larger
            // OR  
            // hi = mid - 1;     // mid doesn't work, try smaller
        }
    }
    
    return result;
}
```

### Real Example: Koko Eating Bananas (LeetCode #875)

**Problem**: Koko has `n` piles of bananas, `piles[i]` bananas in pile i. She wants to eat all bananas in `h` hours. Find the minimum eating speed `k` (bananas/hour) to finish in time.

**Insight**: If she can finish at speed k, she can finish at speed k+1. **Binary search on k!**

```cpp
// Can Koko finish eating at speed k?
bool canFinish(vector<int>& piles, int h, int k) {
    long long hoursNeeded = 0;
    
    for (int pile : piles) {
        // Time to finish this pile at speed k
        // Use ceiling division: (pile + k - 1) / k
        hoursNeeded += (pile + k - 1) / k;
        
        if (hoursNeeded > h) return false;  // Already too slow!
    }
    
    return hoursNeeded <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    // Answer space: [1, max(piles)]
    // Speed 1 = slowest possible
    // Speed max(piles) = can finish any pile in 1 hour
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canFinish(piles, h, mid)) {
            result = mid;        // mid works! But try slower
            right = mid - 1;     // Try smaller k (minimize)
        } else {
            left = mid + 1;      // mid too slow, need faster
        }
    }
    
    return result;
}
```

**Complexity**: O(n log(max_pile))
- Binary search: O(log(max_pile)) iterations
- Each canFinish: O(n) to check all piles

### More Examples

**Split Array Largest Sum** (LeetCode #410)
```
Problem: Split array into m subarrays, minimize largest sum
Answer space: [max(nums), sum(nums)]
Binary search on the "largest sum"
canAchieve(mid): Can we split into ≤m parts with each ≤mid?
```

**Capacity To Ship Packages** (LeetCode #1011)
```  
Problem: Ship packages in D days, minimize ship capacity
Answer space: [max(weights), sum(weights)]
Binary search on the "capacity"
canAchieve(mid): Can we ship in ≤D days with capacity mid?
```

### Rotated Sorted Array
```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

## Common Problems
- Binary Search (LeetCode #704)
- Search Insert Position (LeetCode #35)
- Find First and Last Position (LeetCode #34)
- Search in Rotated Sorted Array (LeetCode #33)
- Find Minimum in Rotated Sorted Array (LeetCode #153)
- Koko Eating Bananas (LeetCode #875)

## Key Points

### When to Use
- ✅ Sorted array
- ✅ Searching for element/position
- ✅ Finding min/max that satisfies condition
- ✅ "Minimize maximum" or "maximize minimum" problems

## Common Mistakes & Debugging

### Mistake 1: Integer Overflow
```cpp
// WRONG - Can overflow!
int mid = (left + right) / 2;

// Example: left = 2147483647, right = 2147483647
// left + right = 4294967294 (overflow!) → wraps to negative

// CORRECT
int mid = left + (right - left) / 2;
```

### Mistake 2: Infinite Loop
```cpp
// WRONG - Infinite loop possible!
while (left < right) {
    int mid = (left + right) / 2;
    if (check(mid)) {
        right = mid;  // Doesn't move when left = mid
    } else {
        left = mid;   // Doesn't move when right = mid
    }
}

// FIX: Always make progress
while (left < right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) {
        right = mid;      // OK
    } else {
        left = mid + 1;   // MUST be +1
    }
}
```

### Mistake 3: Off-by-One Errors
```cpp
// Symptom: Answer is off by 1, or element not found when it exists

// Check:
1. Should loop condition be <= or < ?
2. Should update be mid+1 or mid?
3. Should update be mid-1 or mid?
4. Is initial right = n-1 or n?

// Test with:
- Array of size 1: [5]
- Array of size 2: [5, 7]
- Target at boundaries
```

### Mistake 4: Not Handling Edge Cases
```cpp
// Always check:
if (nums.empty()) return -1;
if (nums.size() == 1) return nums[0] == target ? 0 : -1;
```

### Mistake 5: Wrong Condition for Rotated Array
```cpp
// Need to check WHICH half is sorted
if (nums[left] <= nums[mid]) {
    // Left half is sorted
} else {
    // Right half is sorted
}

// Common mistake: Forgetting the = in <=
// Fails when array not rotated!
```

## Debugging Checklist

When binary search doesn't work:

☐ **Array sorted?** Binary search requires sorted input
☐ **Correct loop condition?** Usually `left <= right`
☐ **Overflow-safe mid?** Use `left + (right-left)/2`
☐ **Updates exclude mid?** Usually `left = mid+1`, `right = mid-1`
☐ **Edge cases tested?** Empty, size 1, size 2, target at ends
☐ **Target exists?** Test when target is in array
☐ **Target missing?** Test when target not in array
☐ **Duplicates handled?** If array has duplicates

## Practice Strategy

### Level 1: Master the Basics (Easy)
1. **Binary Search** (LeetCode #704) - Classic template
2. **Search Insert Position** (LeetCode #35) - Find position
3. **First Bad Version** (LeetCode #278) - Binary search on range
4. **Sqrt(x)** (LeetCode #69) - Binary search on answer

### Level 2: Apply Variations (Medium)  
5. **Find First and Last Position** (LeetCode #34) - Boundaries
6. **Search in Rotated Sorted Array** (LeetCode #33) - Modified search
7. **Find Minimum in Rotated Sorted Array** (LeetCode #153) - Find pivot
8. **Koko Eating Bananas** (LeetCode #875) - Search on answer space
9. **Capacity To Ship Packages** (LeetCode #1011) - Search on answer

### Level 3: Advanced Patterns (Hard)
10. **Median of Two Sorted Arrays** (LeetCode #4) - Binary search on partition
11. **Split Array Largest Sum** (LeetCode #410) - Minimize maximum
12. **Find in Mountain Array** (LeetCode #1095) - Multiple binary searches

## Quick Reference Card

### Standard Binary Search
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

### Find Leftmost (Lower Bound)
```cpp
int left = 0, right = n - 1, result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        result = mid;
        right = mid - 1;  // Keep going left
    } else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return result;
```

### Find Rightmost (Upper Bound)
```cpp
int left = 0, right = n - 1, result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        result = mid;
        left = mid + 1;  // Keep going right
    } else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return result;
```

### Binary Search on Answer
```cpp
int left = min_answer, right = max_answer;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (canAchieve(mid)) {
        result = mid;
        right = mid - 1;  // Try smaller (minimize)
    } else {
        left = mid + 1;
    }
}
```

## Time & Space Complexity

| Variant | Time | Space | Use Case |
|---------|------|-------|----------|
| Standard | O(log n) | O(1) | Find exact value |
| Lower/Upper Bound | O(log n) | O(1) | Find first/last occurrence |
| Answer Space | O(n log k) | O(1) | k = answer range, n = verification |
| Rotated Array | O(log n) | O(1) | Modified sorted array |

[← Back to README](README.md)
