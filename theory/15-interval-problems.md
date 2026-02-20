# Interval Problems

## Overview
Problems involving merging, inserting, or finding intervals (ranges).

## Common Patterns

### 1. Merge Intervals
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {
            // Overlapping, merge
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            // Non-overlapping, add new interval
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}
```

### 2. Insert Interval
```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    
    // Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    
    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}
```

### 3. Non-overlapping Intervals (Greedy)
```cpp
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a[1] < b[1]; });
    
    int count = 0;
    int prevEnd = intervals[0][1];
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < prevEnd) {
            count++;  // Remove current interval
        } else {
            prevEnd = intervals[i][1];
        }
    }
    
    return count;
}
```

### 4. Meeting Rooms (Can Attend All?)
```cpp
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;  // Overlap found
        }
    }
    
    return true;
}
```

### 5. Meeting Rooms II (Minimum Rooms)
```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> starts, ends;
    
    for (auto& interval : intervals) {
        starts.push_back(interval[0]);
        ends.push_back(interval[1]);
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;
    
    while (i < starts.size()) {
        if (starts[i] < ends[j]) {
            rooms++;
            i++;
        } else {
            rooms--;
            j++;
        }
        maxRooms = max(maxRooms, rooms);
    }
    
    return maxRooms;
}

// Alternative: Using Min Heap
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(intervals[0][1]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= minHeap.top()) {
            minHeap.pop();
        }
        minHeap.push(intervals[i][1]);
    }
    
    return minHeap.size();
}
```

### 6. Interval List Intersections
```cpp
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> result;
    int i = 0, j = 0;
    
    while (i < A.size() && j < B.size()) {
        int start = max(A[i][0], B[j][0]);
        int end = min(A[i][1], B[j][1]);
        
        if (start <= end) {
            result.push_back({start, end});
        }
        
        if (A[i][1] < B[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}
```

### 7. My Calendar (Booking System)
```cpp
class MyCalendar {
private:
    map<int, int> bookings;  // start -> end
    
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next = bookings.lower_bound(start);
        
        // Check overlap with next booking
        if (next != bookings.end() && next->first < end) {
            return false;
        }
        
        // Check overlap with previous booking
        if (next != bookings.begin()) {
            auto prev = prev(next);
            if (prev->second > start) {
                return false;
            }
        }
        
        bookings[start] = end;
        return true;
    }
};
```

### 8. Employee Free Time
```cpp
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    vector<vector<int>> intervals;
    
    // Flatten all intervals
    for (auto& employee : schedule) {
        for (auto& interval : employee) {
            intervals.push_back(interval);
        }
    }
    
    // Sort by start time
    sort(intervals.begin(), intervals.end());
    
    // Merge intervals
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    
    // Find gaps (free time)
    vector<vector<int>> result;
    for (int i = 1; i < merged.size(); i++) {
        result.push_back({merged[i - 1][1], merged[i][0]});
    }
    
    return result;
}
```

### 9. Minimum Number of Arrows to Burst Balloons
```cpp
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), 
         [](auto& a, auto& b) { return a[1] < b[1]; });
    
    int arrows = 1;
    int arrowPos = points[0][1];
    
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > arrowPos) {
            arrows++;
            arrowPos = points[i][1];
        }
    }
    
    return arrows;
}
```

## Key Concepts

### Overlap Detection
Two intervals `[a, b]` and `[c, d]` overlap if:
```cpp
max(a, c) <= min(b, d)
// or
!(b < c || d < a)
```

### Sorting Strategies
1. **Sort by start time**: Used in most interval problems
2. **Sort by end time**: Activity selection, greedy algorithms
3. **Sort by length**: Some optimization problems

## Common Problems
- Merge Intervals (LeetCode #56)
- Insert Interval (LeetCode #57)
- Non-overlapping Intervals (LeetCode #435)
- Meeting Rooms (LeetCode #252)
- Meeting Rooms II (LeetCode #253)
- Interval List Intersections (LeetCode #986)
- My Calendar I/II/III (LeetCode #729/731/732)
- Employee Free Time (LeetCode #759)
- Minimum Number of Arrows (LeetCode #452)

## Common Patterns

### Pattern 1: Merge/Flatten
1. Sort intervals
2. Iterate and merge overlapping ones

### Pattern 2: Two Pointers
1. Sort both lists
2. Use two pointers to find intersections

### Pattern 3: Sweep Line
1. Create events (start/end)
2. Sort and process events
3. Track active count

### Pattern 4: Min Heap
1. Sort by start time
2. Use heap to track end times
3. Remove ended meetings before adding new

## Time Complexity
- Sorting: O(n log n)
- Merging: O(n)
- **Overall**: Usually O(n log n)

## Tips
- Always sort first (usually by start time)
- Watch for edge cases: empty input, single interval
- Consider using `map` for ordered intervals
- Min heap useful for tracking active intervals
- Greedy often works (sort by end time)

[← Back to README](README.md)
