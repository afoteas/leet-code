# Greedy Algorithms

## Overview
Greedy algorithms solve optimization problems by making the **locally optimal choice** at each step, hoping to find a **global optimum**.

### The Greedy Philosophy
*"Take what looks best right now and never look back."*

Unlike dynamic programming (which considers all possibilities), greedy makes an irrevocable decision based on current information and moves forward.

## Key Concepts

### The Greedy Choice Property
A global optimum can be reached by making locally optimal choices. At each step:
1. Look at current options
2. Pick the best one according to some criterion
3. Never reconsider that choice
4. Move to next step

### When Greedy Works vs. When It Fails

**✅ Greedy WORKS When:**
```
Problem: Choose coins to make change (coins: 1, 5, 10, 25)
Greedy: Always pick largest coin possible
Example: 63 cents = 25 + 25 + 10 + 1 + 1 + 1 ✓
This is optimal!
```

**❌ Greedy FAILS When:**
```
Problem: Choose coins (coins: 1, 3, 4)
Target: 6 cents
Greedy: Pick 4, then 1, then 1 = 3 coins ✗
Optimal: Pick 3, then 3 = 2 coins ✓
Greedy gave wrong answer!
```

### Visual Example: Activity Selection
```
Activities with [start, end] times:
A: [1, 4]
B: [3, 5]
C: [0, 6]
D: [5, 7]
E: [3, 9]
F: [5, 9]
G: [6, 10]
H: [8, 11]
I: [8, 12]
J: [2, 14]
K: [12, 16]

Goal: Select maximum non-overlapping activities

Greedy Strategy: Always pick activity that ends earliest!

Step 1: Sort by end time: A(4), B(5), C(6), D(7), E(9), F(9), G(10), H(11), I(12), J(14), K(16)
Step 2: Pick A (ends at 4)
Step 3: Skip B (starts at 3 < 4), skip C (starts at 0 < 4)
Step 4: Pick D (starts at 5 >= 4, ends at 7)
Step 5: Pick H (starts at 8 >= 7, ends at 11)
Step 6: Pick K (starts at 12 >= 11)

Result: [A, D, H, K] = 4 activities

Why this works: By ending earliest, we leave maximum room for future activities!
```

## When to Use Greedy

### Indicators
- Problem asks for maximum/minimum
- Problem has optimal substructure
- Local optimum leads to global optimum
- Can prove greedy choice property

### Common Problem Types
- Interval scheduling
- Fractional knapsack
- Huffman coding
- Activity selection
- Minimum spanning tree

## Classic Problems

### 1. Activity Selection / Meeting Rooms
**Problem**: Select maximum number of non-overlapping intervals.

**Greedy Insight**: Always pick the interval that ends earliest - this leaves maximum room for future selections!

**Why not other strategies?**
- ❌ Pick shortest interval? Counterexample: [1,100] vs [1,2][3,4]...[99,100]
- ❌ Pick earliest start? Counterexample: [1,1000] blocks everything
- ✅ Pick earliest end? Leaves maximum flexibility ✓

```cpp
int maxMeetings(vector<pair<int,int>>& intervals) {
    // CRITICAL: Sort by end time (not start time!)
    // Why? Finishing early leaves more room for future activities
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a.second < b.second; });
    
    int count = 1;  // Always take first activity
    int lastEnd = intervals[0].second;  // Track when we finish
    
    for (int i = 1; i < intervals.size(); i++) {
        // Can we do this activity? (starts after previous ends)
        if (intervals[i].first >= lastEnd) {
            count++;  // Take it greedily!
            lastEnd = intervals[i].second;  // Update end time
        }
        // If overlaps, skip it (greedy choice: keep earlier-ending one)
    }
    
    return count;
}
```

**Time Complexity**: O(n log n) for sorting + O(n) for iteration = O(n log n)

### 2. Jump Game
**Problem**: Given array where each element is max jump length, can you reach the last index?

**Greedy Insight**: Track the maximum reachable position. If we ever encounter an index beyond what we can reach, return false.

```cpp
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
```

### 3. Jump Game II
**Problem**: Find minimum number of jumps to reach the last index.

**Greedy Insight**: Track farthest reachable position. When reaching the end of current jump range, increment jumps and update range to farthest position found.

```cpp
int jump(vector<int>& nums) {
    int jumps = 0, currentEnd = 0, farthest = 0;
    
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}
```

### 4. Gas Station
**Problem**: Find starting gas station index to complete circular route, or return -1 if impossible.

**Greedy Insight**: If tank becomes negative at position i, no starting position before i can work. Start fresh from i+1. First check if total gas >= total cost.

```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0, tank = 0, start = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return (totalGas >= totalCost) ? start : -1;
}
```

### 5. Partition Labels
**Problem**: Partition string into max parts so each letter appears in at most one part.

**Greedy Insight**: Track last occurrence of each character. Expand partition until current position equals the farthest last occurrence.

```cpp
vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastIndex;
    for (int i = 0; i < s.length(); i++) 
        lastIndex[s[i]] = i;
    
    vector<int> result;
    int start = 0, end = 0;
    
    for (int i = 0; i < s.length(); i++) {
        end = max(end, lastIndex[s[i]]);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return result;
}
```

### 6. Maximum Subarray (Kadane's Algorithm)
**Problem**: Find contiguous subarray with maximum sum.

**Greedy Insight**: At each position, decide: should I extend the current subarray or start fresh?

**The Key Decision**:
```
At position i: currentSum + nums[i]  vs  nums[i]
                (extend)                  (start new)

Example: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
         
i=0: current=-2, max=-2
i=1: max(1, -2+1)=1, start fresh! current=1, max=1
i=2: max(-3, 1-3)=-2, extend. current=-2, max=1
i=3: max(4, -2+4)=4, start fresh! current=4, max=4
i=4: max(-1, 4-1)=3, extend. current=3, max=4
i=5: max(2, 3+2)=5, extend. current=5, max=5
i=6: max(1, 5+1)=6, extend. current=6, max=6
i=7: max(-5, 6-5)=1, extend. current=1, max=6
i=8: max(4, 1+4)=5, extend. current=5, max=6

Answer: 6 (subarray [4,-1,2,1])
```

```cpp
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];      // Best sum found so far
    int currentSum = nums[0];   // Sum of current subarray
    
    for (int i = 1; i < nums.size(); i++) {
        // GREEDY CHOICE: Is it better to extend or start fresh?
        // Extend if currentSum is positive (adds value)
        // Start fresh if currentSum is negative (drags us down)
        currentSum = max(nums[i], currentSum + nums[i]);
        
        // Update global maximum
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}
```

**Why this works**: If current sum becomes negative, it can only hurt future sums, so start fresh!

**Time Complexity**: O(n) single pass
**Space Complexity**: O(1)

### 7. Task Scheduler
**Problem**: Minimize CPU intervals to complete all tasks with constraint of at least n intervals between same tasks.

**Greedy Insight**: Schedule most frequent task first. Calculate idle slots = (max_frequency - 1) × n, then subtract other tasks that can fill those slots.

```cpp
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char task : tasks) freq[task - 'A']++;
    
    sort(freq.begin(), freq.end(), greater<int>());
    int maxFreq = freq[0];
    int idleSlots = (maxFreq - 1) * n;
    
    for (int i = 1; i < 26 && freq[i] > 0; i++)
        idleSlots -= min(maxFreq - 1, freq[i]);
    
    return tasks.size() + max(0, idleSlots);
}
```

### 8. Non-overlapping Intervals
**Problem**: Minimum intervals to remove to make rest non-overlapping.

**Greedy Insight**: Sort by end time. Keep intervals that end earliest, remove overlapping ones (similar to activity selection).

```cpp
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a[1] < b[1]; });
    
    int count = 0, lastEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < lastEnd) {
            count++;
        } else {
            lastEnd = intervals[i][1];
        }
    }
    return count;
}
```

## Greedy vs Dynamic Programming

### Key Differences

| Aspect | Greedy | Dynamic Programming |
|--------|--------|--------------------|
| Decision Making | Local optimal choice | Considers all possibilities |
| Reconsideration | Never looks back | Explores all paths |
| Speed | O(n) or O(n log n) | O(n²) or more |
| Correctness | Only for specific problems | Always works if formulated correctly |
| Memory | O(1) or O(n) | Usually O(n) or O(n²) |

### When to Use Which?

**Use Greedy When:**
```cpp
// 1. Greedy choice property holds
// 2. Optimal substructure exists  
// 3. Can prove correctness

Examples:
- Activity selection
- Huffman coding
- Minimum spanning tree
- Dijkstra's algorithm
```

**Use DP When:**
```cpp
// 1. Overlapping subproblems
// 2. Need to try all possibilities
// 3. Greedy doesn't work

Examples:
- 0/1 Knapsack
- Longest common subsequence
- Edit distance
- Coin change (certain denominations)
```

### Classic Example: Fractional vs 0/1 Knapsack

**Fractional Knapsack**: Greedy WORKS ✓
```cpp
// Can take fractions of items
// Greedy: Always take item with best value/weight ratio

Items: {value, weight}
A: {60, 10}  ratio=6
B: {100, 20} ratio=5  
C: {120, 30} ratio=4
Capacity: 50

Greedy solution:
1. Take all of A: 60 value, 10 weight
2. Take all of B: 100 value, 20 weight  
3. Take 20/30 of C: 80 value, 20 weight
Total: 240 value ✓ OPTIMAL
```

**0/1 Knapsack**: Greedy FAILS ✗
```cpp
// Must take whole item or nothing
// Greedy by ratio doesn't work!

Items: {value, weight}
A: {60, 10}  ratio=6
B: {100, 20} ratio=5
C: {120, 30} ratio=4
Capacity: 50

Greedy attempt:
1. Take A: 60 value, 10 weight
2. Take B: 100 value, 20 weight
3. Can't fit C (need 30, have 20)
Total: 160 value ✗

Optimal (DP):
1. Take B: 100 value, 20 weight
2. Take C: 120 value, 30 weight
Total: 220 value ✓ BETTER!
```

**Why greedy fails here**: Can't take fractions, so best ratio doesn't guarantee best combination!

## Common Sorting Strategies

1. **By end time**: Activity selection, meeting rooms
2. **By start time**: Some interval problems
3. **By length/duration**: Some scheduling problems
4. **By value/weight ratio**: Fractional knapsack

## Common Problems
- Jump Game (LeetCode #55)
- Jump Game II (LeetCode #45)
- Gas Station (LeetCode #134)
- Partition Labels (LeetCode #763)
- Non-overlapping Intervals (LeetCode #435)
- Minimum Number of Arrows (LeetCode #452)
- Task Scheduler (LeetCode #621)

## How to Prove Greedy Correctness

Proving a greedy algorithm is correct is often harder than implementing it!

### Method 1: Exchange Argument (Most Common)

**Template**:
1. Assume optimal solution OPT differs from greedy solution G
2. Find first place they differ
3. Exchange OPT's choice with G's choice
4. Show this doesn't worsen (or improves) the solution
5. Repeat until OPT = G, proving G is optimal

**Example: Activity Selection Proof**
```
Claim: Selecting activity with earliest end time is optimal

Proof by exchange:
1. Let OPT = optimal solution
2. Let G = greedy solution (earliest end time)
3. Suppose first activity in OPT is 'a', first in G is 'g'
4. Since g ends earliest, end(g) ≤ end(a)
5. Replace 'a' with 'g' in OPT:
   - Still valid (g ends before or when a ends)
   - Same number of activities
   - Leaves ≥ as much room for future activities
6. Can repeat for all activities
7. Therefore, G is optimal ✓
```

### Method 2: Greedy Stays Ahead

**Template**:
1. Define a measure of "progress"
2. Show greedy is always ≥ optimal at each step
3. Therefore greedy reaches goal

**Example: Interval Covering**
```
Problem: Cover interval [0, L] with minimum intervals

Greedy: Always pick interval that extends farthest

Proof:
At step i, let g_i = greedy's coverage, o_i = optimal's coverage
Invariant: g_i ≥ o_i (greedy covers at least as much)

Base: g_0 = o_0 = 0 ✓
Step: Greedy picks interval extending farthest
      So g_{i+1} ≥ o_{i+1} ✓
End: If greedy covers L, used ≤ intervals than optimal ✓
```

### Method 3: Contradiction

**Template**:
1. Assume greedy is not optimal
2. Show this leads to logical contradiction
3. Therefore greedy must be optimal

**Example: Huffman Coding**
```
Claim: Combining two least frequent characters is optimal

Proof by contradiction:
Suppose optimal solution combines x (not least) and y (not least)
Let a, b be two least frequent characters
Swap x↔a and y↔b in the tree
This reduces total encoding length (contradiction!)
Therefore, must combine least frequent ✓
```

### Quick Correctness Checklist

✅ **Before implementing greedy, ask:**
1. Can I prove it with exchange argument?
2. Does greedy stay ahead of optimal?
3. Can I find a counterexample?
4. Have I tested edge cases?

❌ **Red flags (greedy might fail):**
- Future choices depend on past choices
- Need to "undo" decisions
- Local optimum ≠ global optimum
- Problem has dependencies/constraints

## Common Greedy Patterns & Strategies

### Pattern 1: Interval Problems
**Strategy**: Sort by end time, pick non-overlapping
- Activity selection
- Non-overlapping intervals
- Minimum arrows to burst balloons

### Pattern 2: Two-Stage Problems  
**Strategy**: Handle extremes first
- Assign cookies (sort both arrays)
- Meeting rooms (process starts/ends)

### Pattern 3: One Pass Decisions
**Strategy**: Decide at each step without looking back
- Kadane's algorithm (max subarray)
- Jump game (track max reachable)
- Gas station (track tank level)

### Pattern 4: Frequency-Based
**Strategy**: Process most/least frequent first
- Task scheduler
- Reorganize string
- Huffman coding

## Common Mistakes & How to Avoid

### Mistake 1: Wrong Sorting Criterion
```cpp
// WRONG: Sort by start time for activity selection
sort(intervals.begin(), intervals.end());

// CORRECT: Sort by end time
sort(intervals.begin(), intervals.end(), 
     [](auto& a, auto& b) { return a.second < b.second; });
```
**Why it matters**: Greedy depends critically on the right ordering!

### Mistake 2: Not Proving Correctness
```cpp
// Don't just code greedy because it "seems right"
// Always ask: Can I prove this or find a counterexample?
```

### Mistake 3: Using Greedy When DP Needed
```cpp
// Not all optimization problems are greedy!
// If greedy fails on examples, try DP
```

### Mistake 4: Forgetting Edge Cases
```cpp
// Empty input, single element, all same values
if (intervals.empty()) return 0;
```

## Implementation Tips

✅ **Best Practices**:
1. **Sort first** if order matters
2. **Use custom comparator** to make sorting clear
3. **Track state** (last end time, current max, etc.)
4. **Test with counterexamples** before implementing
5. **Prove or disprove** greedy before coding

✅ **Debugging Greedy**:
```cpp
// If getting wrong answer:
1. Try small examples by hand
2. Check sorting criterion
3. Verify greedy choice at each step
4. Look for counterexample
5. Consider if DP is needed instead
```

## Practice Strategy

### Level 1: Learn the Patterns (Easy)
1. **Assign Cookies** (LeetCode #455) - Sort both arrays
2. **Lemonade Change** (LeetCode #860) - Greedy decisions
3. **Best Time to Buy/Sell Stock II** (LeetCode #122) - Accumulate gains

### Level 2: Apply Techniques (Medium)
4. **Jump Game** (LeetCode #55) - Track max reachable
5. **Jump Game II** (LeetCode #45) - Minimize jumps
6. **Gas Station** (LeetCode #134) - Single pass greedy
7. **Partition Labels** (LeetCode #763) - Track last occurrence
8. **Non-overlapping Intervals** (LeetCode #435) - Sort by end time

### Level 3: Master Advanced (Hard)
9. **Meeting Rooms II** (LeetCode #253) - Min heap or sweep line
10. **Minimum Number of Arrows** (LeetCode #452) - Interval merging
11. **Task Scheduler** (LeetCode #621) - Frequency + math

## Time Complexity Patterns

- **Sorting-based**: O(n log n)
- **Single pass**: O(n)
- **With heap**: O(n log n)
- **Two pointers**: O(n) after sorting

## When in Doubt: The Decision Tree

```
Is it an optimization problem?
├─ No → Not greedy
└─ Yes → Can you prove greedy choice property?
   ├─ Yes → USE GREEDY ✓
   │  └─ Sort if needed
   │  └─ Make local optimal choices
   │  └─ Never look back
   └─ No/Unsure → Try counterexamples
      ├─ Found counterexample? → USE DP
      └─ No counterexample? → Prove it or code both and compare
```

## Quick Reference: Common Sorts

```cpp
// By end time (activity selection)
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.second < b.second;
});

// By start time
sort(v.begin(), v.end());

// By value/weight ratio (fractional knapsack)
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return 1.0 * a.value / a.weight > 1.0 * b.value / b.weight;
});

// By frequency (descending)
sort(v.begin(), v.end(), greater<int>());
```

[← Back to README](README.md)
