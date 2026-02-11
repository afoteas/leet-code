# Dynamic Programming

## Overview
Optimization technique that solves complex problems by breaking them down into simpler subproblems and storing results to avoid redundant computation.

## Key Concepts

### When to Use DP
1. **Optimal substructure**: Optimal solution contains optimal solutions to subproblems
2. **Overlapping subproblems**: Same subproblems solved multiple times
3. Keywords: "maximum", "minimum", "count ways", "longest", "shortest"

### Approaches
1. **Top-Down (Memoization)**: Recursion + caching
2. **Bottom-Up (Tabulation)**: Iterative, fill table

## Classic Patterns

### 1. Fibonacci (Basic DP)

#### Top-Down
```cpp
int fib(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}
```

#### Bottom-Up
```cpp
int fib(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}
```

#### Space-Optimized
```cpp
int fib(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

### 2. Climbing Stairs
```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}
```

### 3. Coin Change (Unbounded Knapsack)
```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}
```

### 4. Longest Increasing Subsequence
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    
    return maxLen;
}
```

### 5. 0/1 Knapsack
```cpp
int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], 
                              values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];
}
```

### 6. Edit Distance
```cpp
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],      // delete
                                    dp[i][j - 1],      // insert
                                    dp[i - 1][j - 1]}); // replace
            }
        }
    }
    
    return dp[m][n];
}
```

## DP Problem Categories

### 1. Linear DP
- House Robber
- Maximum Subarray
- Paint House

### 2. Knapsack
- 0/1 Knapsack
- Unbounded Knapsack
- Target Sum

### 3. String DP
- Longest Common Subsequence
- Edit Distance
- Palindrome problems

### 4. Grid/Path DP
- Unique Paths
- Minimum Path Sum
- Dungeon Game

### 5. Interval DP
- Burst Balloons
- Palindrome Partitioning

### 6. Tree DP
- House Robber III
- Binary Tree Maximum Path Sum

## Approach Steps

1. **Define state**: What does `dp[i]` or `dp[i][j]` represent?
2. **Find recurrence**: How does current state relate to previous states?
3. **Initialize**: Base cases
4. **Iteration order**: Fill table in correct order
5. **Answer**: Where is the final answer?

## Common Problems
- Climbing Stairs (LeetCode #70)
- Coin Change (LeetCode #322)
- Longest Increasing Subsequence (LeetCode #300)
- Unique Paths (LeetCode #62)
- House Robber (LeetCode #198)
- Longest Common Subsequence (LeetCode #1143)
- Edit Distance (LeetCode #72)
- Maximum Subarray (LeetCode #53)

## Tips
- Start with brute force recursion
- Add memoization (top-down DP)
- Convert to iterative (bottom-up DP)
- Optimize space if possible
- Draw the DP table to visualize
- Look for patterns in transitions

## Time Complexity
- Usually O(n), O(n²), or O(n·m) depending on dimensions
- Space can often be optimized to O(1) or O(n)

[← Back to README](README.md)
