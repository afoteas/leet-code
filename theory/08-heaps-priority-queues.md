# Heaps / Priority Queues

## Overview
Heap is a complete binary tree that satisfies the heap property:
- **Max Heap**: Parent ≥ children
- **Min Heap**: Parent ≤ children

Priority Queue is an abstract data type typically implemented using heaps.

## C++ Implementation

### std::priority_queue (Max Heap by default)
```cpp
#include <queue>

// Max heap
priority_queue<int> maxHeap;
maxHeap.push(5);
maxHeap.push(10);
maxHeap.push(3);
int top = maxHeap.top();  // 10
maxHeap.pop();

// Min heap
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(5);
minHeap.push(10);
minHeap.push(3);
int top = minHeap.top();  // 3
minHeap.pop();
```

### Custom Comparator
```cpp
// For pairs
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;  // Min heap by second element
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

// For custom objects
struct Task {
    int priority;
    string name;
};

struct CompareTask {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority;  // Max heap by priority
    }
};

priority_queue<Task, vector<Task>, CompareTask> taskQueue;
```

## Common Patterns

### 1. Top K Elements
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Min heap of size k
    auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    
    for (auto& [num, count] : freq) {
        pq.push({num, count});
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    return result;
}
```

### 2. Merge K Sorted Lists
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min heap
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    
    for (ListNode* list : lists) {
        if (list != nullptr) {
            pq.push(list);
        }
    }
    
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        
        tail->next = node;
        tail = tail->next;
        
        if (node->next != nullptr) {
            pq.push(node->next);
        }
    }
    
    return dummy.next;
}
```

### 3. Kth Largest Element
```cpp
int findKthLargest(vector<int>& nums, int k) {
    // Min heap of size k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}
```

### 4. Median from Data Stream
```cpp
class MedianFinder {
private:
    priority_queue<int> maxHeap;  // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Upper half
    
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

### 5. Task Scheduler
```cpp
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for (char task : tasks) {
        freq[task]++;
    }
    
    priority_queue<int> pq;
    for (auto& [task, count] : freq) {
        pq.push(count);
    }
    
    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;
        for (int i = 0; i <= n; i++) {
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                if (count > 1) {
                    temp.push_back(count - 1);
                }
            }
            time++;
            if (pq.empty() && temp.empty()) {
                break;
            }
        }
        for (int count : temp) {
            pq.push(count);
        }
    }
    
    return time;
}
```

## Heap Operations

### Manual Heap (using std::make_heap)
```cpp
vector<int> nums = {3, 1, 4, 1, 5, 9};

// Make max heap
make_heap(nums.begin(), nums.end());

// Push
nums.push_back(7);
push_heap(nums.begin(), nums.end());

// Pop
pop_heap(nums.begin(), nums.end());
nums.pop_back();

// Sort
sort_heap(nums.begin(), nums.end());  // Results in sorted order
```

## Common Problems
- Kth Largest Element (LeetCode #215)
- Top K Frequent Elements (LeetCode #347)
- Merge K Sorted Lists (LeetCode #23)
- Find Median from Data Stream (LeetCode #295)
- Task Scheduler (LeetCode #621)
- Kth Smallest Element in Sorted Matrix (LeetCode #378)

## When to Use Heaps

✅ **Use Heap When:**
- Finding top/bottom K elements
- Streaming data (median, percentiles)
- Merging K sorted lists
- Scheduling tasks by priority
- Need quick access to min/max

❌ **Don't Use Heap When:**
- Need to access arbitrary elements
- Need to maintain order
- Simple min/max of static data (use `std::min_element`)

## Time Complexities

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(log n) | O(n) |
| Delete Min/Max | O(log n) | - |
| Get Min/Max | O(1) | - |
| Build Heap | O(n) | - |
| Heapify | O(log n) | - |

## Tips
- **Top K**: Use min heap of size K
- **Bottom K**: Use max heap of size K
- **Median**: Use two heaps (max for lower half, min for upper half)
- Custom comparators can be tricky - test carefully
- Consider `std::nth_element` for one-time Kth element queries (O(n) average)

[← Back to README](README.md)
