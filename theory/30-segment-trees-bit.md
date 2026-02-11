# Segment Trees / Binary Indexed Trees

## Segment Tree

### Overview
Tree structure for range queries and updates in O(log n).

### Implementation
```cpp
class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + 
               query(2*node+1, mid+1, end, l, r);
    }
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }
    
    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
    
    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
```

## Binary Indexed Tree (Fenwick Tree)

### Implementation
```cpp
class BIT {
private:
    vector<int> tree;
    int n;
    
public:
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    void update(int idx, int delta) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
    
    int rangeQuery(int l, int r) {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
```

### Time Complexity
- Build: O(n log n)
- Query: O(log n)
- Update: O(log n)

## Use Cases
- Range sum queries
- Range minimum/maximum
- Count inversions
- 2D range queries

[← Back to README](README.md)
