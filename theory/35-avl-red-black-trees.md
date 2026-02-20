# AVL and Red-Black Trees

## Overview

Self-balancing Binary Search Trees (BSTs) automatically maintain a balanced structure to guarantee O(log n) time complexity for search, insert, and delete operations. Unlike regular BSTs which can degenerate to O(n) in the worst case, these trees rebalance themselves after modifications.

**Why they exist:**
- Regular BSTs can become unbalanced (e.g., inserting sorted data creates a linked list)
- Unbalanced trees lose the O(log n) guarantee
- Self-balancing trees maintain height ≈ log n through rotations and rebalancing

**Two main types:**
1. **AVL Trees** - Strict height-balancing
2. **Red-Black Trees** - Relaxed balancing with color properties

## AVL Trees

### Properties
- Named after inventors Adelson-Velsky and Landis (1962)
- **Balance Factor**: `height(left) - height(right)` must be -1, 0, or +1 for every node
- Strictly balanced: height is always O(log n)
- Rebalancing through rotations after insertions/deletions

### Balance Factor
```cpp
int height(Node* node) {
    return node ? node->height : 0;
}

int balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}
```

### Rotations

#### Single Right Rotation (LL Case)
```
        z                                y
       / \                             /   \
      y   T4      Right Rotate(z)     x     z
     / \          - - - - - - - ->   / \   / \
    x   T3                          T1 T2 T3 T4
   / \
  T1  T2
```

```cpp
Node* rightRotate(Node* z) {
    Node* y = z->left;
    Node* T3 = y->right;
    
    // Perform rotation
    y->right = z;
    z->left = T3;
    
    // Update heights
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));
    
    return y;  // New root
}
```

#### Single Left Rotation (RR Case)
```
    z                               y
   / \                            /   \
  T1  y     Left Rotate(z)       z     x
     / \    - - - - - - - ->    / \   / \
    T2  x                      T1 T2 T3 T4
       / \
      T3 T4
```

```cpp
Node* leftRotate(Node* z) {
    Node* y = z->right;
    Node* T2 = y->left;
    
    // Perform rotation
    y->left = z;
    z->right = T2;
    
    // Update heights
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));
    
    return y;  // New root
}
```

#### Double Rotations

**Left-Right Rotation (LR Case)**
```
       z                           z                         x
      / \                         / \                      /   \
     y   T4   Left Rotate(y)     x   T4   Right Rotate   y     z
    / \       - - - - - - - ->  / \        - - - - - - >/ \   / \
   T1  x                       y  T3                    T1 T2 T3 T4
      / \                     / \
     T2 T3                   T1 T2
```

**Right-Left Rotation (RL Case)**
```
    z                         z                           x
   / \                       / \                        /   \
  T1  y   Right Rotate(y)   T1  x    Left Rotate(z)   z     y
     / \  - - - - - - - ->      / \   - - - - - - ->  / \   / \
    x  T4                      T2  y                  T1 T2 T3 T4
   / \                            / \
  T2 T3                          T3 T4
```

### AVL Insert Pattern
```cpp
Node* insert(Node* node, int key) {
    // 1. Standard BST insertion
    if (node == nullptr) 
        return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // Duplicate keys not allowed
    
    // 2. Update height
    node->height = 1 + max(height(node->left), height(node->right));
    
    // 3. Get balance factor
    int balance = balanceFactor(node);
    
    // 4. Rebalance if needed
    
    // Left-Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right-Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left-Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right-Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}
```

## Red-Black Trees

### Properties
1. Every node is either RED or BLACK
2. Root is always BLACK
3. All leaves (NIL) are BLACK
4. RED nodes cannot have RED children (no two consecutive RED nodes)
5. Every path from root to leaf has the same number of BLACK nodes (black-height)

### Why These Properties Work
- Ensure tree height is at most 2 × log(n + 1)
- Less strict than AVL, allowing slightly more unbalanced trees
- Fewer rotations needed during insertions/deletions

### Node Structure
```cpp
enum Color { RED, BLACK };

struct RBNode {
    int key;
    Color color;
    RBNode *left, *right, *parent;
    
    RBNode(int k) : key(k), color(RED), 
                    left(nullptr), right(nullptr), parent(nullptr) {}
};
```

### Rotations in Red-Black Trees
Same as AVL rotations, but also need to update parent pointers:

```cpp
void leftRotate(RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    
    if (y->left != nullptr)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}
```

### Red-Black Insert (High-Level)
```cpp
void insert(int key) {
    // 1. Standard BST insertion with RED color
    RBNode* newNode = new RBNode(key);
    // ... BST insertion logic ...
    
    // 2. Fix violations
    fixViolation(newNode);
}

void fixViolation(RBNode* node) {
    RBNode* parent = nullptr;
    RBNode* grandparent = nullptr;
    
    while (node != root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;
        
        // Case A: Parent is left child of grandparent
        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;
            
            // Case 1: Uncle is RED - recoloring
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else {
                // Case 2: Node is right child - left rotation
                if (node == parent->right) {
                    leftRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                
                // Case 3: Node is left child - right rotation
                rightRotate(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
        // Case B: Parent is right child of grandparent (symmetric)
        else {
            // ... symmetric cases ...
        }
    }
    
    root->color = BLACK;  // Root is always black
}
```

## AVL vs Red-Black Comparison

### When to Use AVL Trees
✅ **Use AVL when:**
- Lookup-intensive applications (search-heavy workloads)
- Need strict O(log n) with minimal height
- Read operations >> Write operations
- Predictable performance is critical

**Examples:**
- Database indexes with heavy reads
- In-memory lookup tables
- Real-time systems requiring guaranteed performance

### When to Use Red-Black Trees
✅ **Use Red-Black when:**
- Balanced read/write operations
- Insertions and deletions are frequent
- Slightly relaxed balance is acceptable
- Want fewer rotations during modifications

**Examples:**
- `std::map` and `std::set` in C++ STL
- Linux kernel's Completely Fair Scheduler
- Java's TreeMap and TreeSet
- General-purpose sorted containers

### Performance Comparison

| Metric | AVL Trees | Red-Black Trees |
|--------|-----------|-----------------|
| Height | ≤ 1.44 log(n) | ≤ 2 log(n) |
| Search | Faster (shorter height) | Slightly slower |
| Insert/Delete | Slower (more rotations) | Faster (fewer rotations) |
| Balancing | Strict (BF ∈ {-1, 0, 1}) | Relaxed (color rules) |
| Rotations per Insert | ≤ 2 | ≤ 2 (but with recoloring) |
| Rotations per Delete | O(log n) | ≤ 3 |
| Space Overhead | Height field per node | Color bit per node |

### Trade-offs Summary
```
AVL:        More balanced → Faster search → Slower modifications
Red-Black:  Less balanced → Faster modifications → Slightly slower search
```

## C++ STL Implementation

### std::map and std::set (Red-Black Trees)
```cpp
#include <map>
#include <set>

// std::map - internally a Red-Black tree
std::map<int, string> map;
map[1] = "one";           // O(log n) insert
map.find(1);              // O(log n) search
map.erase(1);             // O(log n) delete

// std::set - also Red-Black tree
std::set<int> set;
set.insert(5);            // O(log n)
set.count(5);             // O(log n)
set.erase(5);             // O(log n)

// Guaranteed ordered traversal
for (auto& [key, val] : map) {
    // Iterates in sorted order of keys
}
```

### Why C++ STL Uses Red-Black Trees
- Balanced insert/delete/search performance
- Fewer rotations during modifications
- Better for general-purpose containers
- Predictable amortized performance

### Custom Comparators
```cpp
// Custom comparison for complex keys
struct Person {
    string name;
    int age;
};

struct PersonCompare {
    bool operator()(const Person& a, const Person& b) const {
        return a.age < b.age;
    }
};

std::set<Person, PersonCompare> people;
std::map<Person, string, PersonCompare> personData;
```

## Interview Perspective

### What You Need to Know
✅ **Conceptual Understanding (MUST KNOW):**
- Self-balancing trees maintain O(log n) operations
- AVL is strictly balanced, Red-Black is relaxed
- Rotations are used to rebalance trees
- STL containers (`std::map`, `std::set`) use Red-Black trees
- Know the O(log n) guarantees for insert/search/delete

✅ **High-Level Implementation (GOOD TO KNOW):**
- Recognize when rotations are needed
- Understand balance factor (AVL) and color rules (Red-Black)
- Know the 4 rotation cases conceptually

❌ **Deep Implementation (RARELY TESTED):**
- Coding complete AVL/Red-Black insert/delete from scratch
- Handling all edge cases in deletion
- Memory management details

### Common Interview Questions
1. **"Why do we need balanced BSTs?"**
   - Prevent O(n) worst-case for unbalanced trees
   - Guarantee O(log n) for all operations

2. **"What's the difference between AVL and Red-Black trees?"**
   - AVL: stricter balancing, better for search-heavy
   - Red-Black: relaxed balancing, better for mixed operations
   - Red-Black used in STL (`std::map`, `std::set`)

3. **"How does std::map guarantee O(log n) lookup?"**
   - Implemented as Red-Black tree (self-balancing BST)
   - Height is always O(log n)

4. **"When would you use std::map vs std::unordered_map?"**
   - `std::map` (Red-Black): need sorted order, O(log n)
   - `std::unordered_map` (hash table): no order needed, O(1) average

5. **"Can you implement a simple rotation?"**
   - Should be able to code left/right rotation
   - Understand pointer manipulation

### Interview Tips
- **Don't overthink implementation**: Interviewers rarely ask for full AVL/RB implementation
- **Focus on concepts**: Understand why balanced trees matter
- **Know STL usage**: Most C++ interviews care more about proper STL usage
- **Mention trade-offs**: Show you understand when to use different data structures
- **Draw diagrams**: Visual explanation of rotations is often sufficient

## Key Points to Remember

### Must-Know Facts
1. **Self-balancing BSTs guarantee O(log n)** for insert/search/delete
2. **AVL trees are stricter** (balance factor) than Red-Black trees (color rules)
3. **C++ STL uses Red-Black trees** for `std::map` and `std::set`
4. **Rotations (left/right) rebalance** trees after modifications
5. **AVL better for search-heavy**, Red-Black better for mixed operations
6. **Regular BST can degrade to O(n)** without balancing

### Quick Reference
```cpp
// When you need sorted order + O(log n)
std::map<int, string> map;        // Key-value, sorted, O(log n)
std::set<int> set;                // Unique values, sorted, O(log n)

// When you need O(1) average + no order
std::unordered_map<int, string>;  // Key-value, unordered, O(1) avg
std::unordered_set<int>;          // Unique values, unordered, O(1) avg
```

### Time Complexities
| Operation | Regular BST (worst) | AVL Tree | Red-Black Tree |
|-----------|---------------------|----------|----------------|
| Search | O(n) | O(log n) | O(log n) |
| Insert | O(n) | O(log n) | O(log n) |
| Delete | O(n) | O(log n) | O(log n) |
| Min/Max | O(n) | O(log n) | O(log n) |

## Common Interview Problems

### Related LeetCode Problems
While AVL/Red-Black implementation is rarely tested, these problems test understanding:

1. **Balance a Binary Search Tree** (LeetCode #1382)
   - Given unbalanced BST, return balanced BST
   - Tests understanding of why balancing matters
   
2. **Convert Sorted Array to BST** (LeetCode #108)
   - Build balanced BST from sorted array
   - Foundation for understanding balanced trees

3. **Design problems using std::map/set**
   - Many problems benefit from using STL's Red-Black implementation
   - Example: Range queries, finding k-th elements

### Practice Focus
- **Instead of implementing AVL/Red-Black from scratch**, focus on:
  - Using `std::map` and `std::set` effectively
  - Understanding when balanced trees are needed
  - Recognizing problems that benefit from O(log n) guarantees
  - System design questions about data structure choices

## Additional Resources

### When Balanced Trees Matter in Practice
- **Database Indexes**: B-trees (extension of balanced BSTs)
- **File Systems**: Balanced trees for directory structures
- **Memory Allocators**: Red-Black trees for free block management
- **Process Scheduling**: Fair scheduling with balanced trees

### Modern C++ Considerations
```cpp
// C++17 and later - structured bindings with map
std::map<string, int> scores;
for (const auto& [name, score] : scores) {
    // Clean iteration over Red-Black tree
}

// Efficient insertion with hint
auto it = scores.find("Alice");
scores.insert(it, {"Bob", 95});  // O(1) if hint is good
```

[← Back to README](README.md)
