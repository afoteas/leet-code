# Divide and Conquer

## Overview
Divide and conquer breaks a problem into smaller subproblems, solves each recursively, and then combines the results.

**Core steps:**
1. **Divide** the problem into smaller independent subproblems.
2. **Conquer** by solving subproblems recursively (or directly if small).
3. **Combine** the subproblem results into a final answer.

## When to Use
- The problem can be split into similar subproblems.
- Subproblems are independent or weakly dependent.
- A clean merge/combine step exists.
- Recurrence feels like $T(n) = aT(n/b) + f(n)$.

## Recognizing the Pattern
- "Split into halves" or "two subarrays"
- "Solve left and right independently"
- "Merge results" or "combine answers"
- Recursion + merge step that is $O(n)$ or $O(n\log n)$

## Time Complexity Intuition (Master Theorem)
For recurrences of the form $T(n) = aT(n/b) + f(n)$:
- If $f(n)$ is smaller than $n^{\log_b a}$, then $T(n) = \Theta(n^{\log_b a})$.
- If $f(n)$ matches $n^{\log_b a}$, then $T(n) = \Theta(n^{\log_b a} \log n)$.
- If $f(n)$ is larger than $n^{\log_b a}$ (polynomially), then $T(n) = \Theta(f(n))$.

Common examples:
- Merge sort: $T(n) = 2T(n/2) + O(n)$ => $O(n\log n)$
- Binary search: $T(n) = T(n/2) + O(1)$ => $O(\log n)$

## Template (C++)
```cpp
int solve(vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = left + (right - left) / 2;
    int leftResult = solve(nums, left, mid);
    int rightResult = solve(nums, mid + 1, right);

    // Combine step
    return combine(leftResult, rightResult);
}
```

## Classic Examples

### Merge Sort
```cpp
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);  // Combine
}
```

### Maximum Subarray (Divide and Conquer)
```cpp
int maxCrossingSum(const vector<int>& nums, int left, int mid, int right) {
    int sum = 0;
    int leftMax = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        leftMax = max(leftMax, sum);
    }

    sum = 0;
    int rightMax = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
}

int maxSubArray(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];

    int mid = left + (right - left) / 2;
    int leftBest = maxSubArray(nums, left, mid);
    int rightBest = maxSubArray(nums, mid + 1, right);
    int crossBest = maxCrossingSum(nums, left, mid, right);

    return max({leftBest, rightBest, crossBest});
}
```

### Closest Pair of Points (High-Level Idea)
- Divide points by x-coordinate into left/right halves.
- Recursively compute closest pair on each side.
- Combine by checking a narrow vertical strip around the dividing line.

## Common Pitfalls
- Missing or incorrect base cases.
- Combine step that accidentally becomes $O(n^2)$.
- Overlapping subproblems (consider DP or memoization instead).
- Stack depth issues for very large inputs.

## Common Problems
- Merge Sort (sorting template)
- Maximum Subarray (LeetCode #53)
- Search in Rotated Sorted Array (LeetCode #33)
- Pow(x, n) (LeetCode #50)
- Kth Largest Element (divide and partition)
- Closest Pair of Points (classic)

## Key Takeaways
- Divide and conquer is about structured recursion with a clean combine step.
- If subproblems overlap heavily, switch to DP.
- Always analyze the recurrence and combine cost.

[← Back to README](README.md)