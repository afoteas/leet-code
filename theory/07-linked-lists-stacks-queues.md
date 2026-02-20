# Linked Lists, Stacks, Queues

## Linked Lists

### Overview
Linear data structure where elements are stored in nodes, each containing data and pointer(s) to next/previous nodes.

### Definition
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

### Basic Operations

#### Traversal
```cpp
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}
```

#### Insert at Beginning
```cpp
ListNode* insertAtHead(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    return newNode;
}
```

#### Delete Node
```cpp
ListNode* deleteNode(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    
    while (prev->next != nullptr) {
        if (prev->next->val == val) {
            ListNode* toDelete = prev->next;
            prev->next = prev->next->next;
            delete toDelete;
            break;
        }
        prev = prev->next;
    }
    
    return dummy.next;
}
```

### Common Patterns

#### Two Pointers (Fast & Slow)
```cpp
// Find middle
ListNode* findMiddle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Detect cycle
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    
    return false;
}
```

#### Reverse Linked List
```cpp
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
```

#### Merge Two Lists
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}
```

## Stacks

### Overview
LIFO (Last-In-First-Out) data structure.

### C++ Implementation
```cpp
#include <stack>

stack<int> st;
st.push(5);          // Add to top
st.pop();            // Remove from top
st.top();            // Access top
st.empty();          // Check if empty
st.size();           // Get size
```

### Common Use Cases
- Expression evaluation
- Backtracking
- Function call stack
- Undo operations
- Parentheses matching

### Example: Valid Parentheses
```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
    
    for (char c : s) {
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }
    
    return st.empty();
}
```

## Queues

### Overview
FIFO (First-In-First-Out) data structure.

### C++ Implementation
```cpp
#include <queue>

queue<int> q;
q.push(5);           // Add to back
q.pop();             // Remove from front
q.front();           // Access front
q.back();            // Access back
q.empty();           // Check if empty
q.size();            // Get size
```

### Deque (Double-Ended Queue)
```cpp
#include <deque>

deque<int> dq;
dq.push_front(1);    // Add to front
dq.push_back(2);     // Add to back
dq.pop_front();      // Remove from front
dq.pop_back();       // Remove from back
```

### Common Use Cases
- BFS traversal
- Level-order traversal
- Sliding window problems
- Task scheduling

## Common Problems

### Linked Lists
- Reverse Linked List (LeetCode #206)
- Merge Two Sorted Lists (LeetCode #21)
- Linked List Cycle (LeetCode #141)
- Remove Nth Node From End (LeetCode #19)
- Intersection of Two Linked Lists (LeetCode #160)

### Stacks
- Valid Parentheses (LeetCode #20)
- Min Stack (LeetCode #155)
- Daily Temperatures (LeetCode #739)
- Largest Rectangle in Histogram (LeetCode #84)

### Queues
- Implement Queue using Stacks (LeetCode #232)
- Sliding Window Maximum (LeetCode #239)
- Design Circular Queue (LeetCode #622)

## Time Complexities

| Operation | Linked List | Stack | Queue |
|-----------|-------------|-------|-------|
| Access | O(n) | O(n) | O(n) |
| Search | O(n) | O(n) | O(n) |
| Insert (front) | O(1) | N/A | N/A |
| Insert (back) | O(n) or O(1)* | N/A | N/A |
| Push/Enqueue | N/A | O(1) | O(1) |
| Pop/Dequeue | N/A | O(1) | O(1) |
| Top/Front | N/A | O(1) | O(1) |

*O(1) if maintaining tail pointer

## Tips
- Use dummy node for linked list to simplify edge cases
- Always check for nullptr before dereferencing
- Use fast/slow pointers for cycle detection
- Stack for reversing or matching
- Queue for BFS and level-order traversal
- Don't forget to free memory in C++!

[← Back to README](README.md)
