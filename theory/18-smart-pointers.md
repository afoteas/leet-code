# Smart Pointers

## Overview
RAII wrappers for raw pointers that automatically manage memory.

## unique_ptr
Exclusive ownership of a resource.

```cpp
#include <memory>

// Creation
unique_ptr<int> p1(new int(5));
auto p2 = make_unique<int>(10);  // Preferred (exception-safe)

// Cannot copy, but can move
unique_ptr<int> p3 = std::move(p2);  // p2 is now nullptr

// Access
*p1 = 20;
int val = *p1;

// Release ownership
int* raw = p1.release();  // p1 is now nullptr, you own raw pointer

// Reset
p1.reset(new int(30));  // Deletes old, assigns new
p1.reset();  // Deletes and sets to nullptr
```

## shared_ptr
Shared ownership with reference counting.

```cpp
// Creation
shared_ptr<int> sp1(new int(5));
auto sp2 = make_shared<int>(10);  // Preferred (more efficient)

// Copying increases ref count
shared_ptr<int> sp3 = sp2;  // ref count = 2

// Check ref count
sp2.use_count();

// Reset
sp2.reset();  // ref count decreases
```

## weak_ptr
Non-owning reference to `shared_ptr` (breaks circular references).

```cpp
shared_ptr<int> sp = make_shared<int>(5);
weak_ptr<int> wp = sp;

// Check if still valid
if (!wp.expired()) {
    shared_ptr<int> sp2 = wp.lock();
    if (sp2) {
        // Use sp2
    }
}
```

## Example: Breaking Circular Reference
```cpp
class Node {
public:
    shared_ptr<Node> next;
    weak_ptr<Node> prev;  // Use weak_ptr to break cycle
};
```

## When to Use

| Pointer Type | Use When |
|--------------|----------|
| `unique_ptr` | Exclusive ownership, most common case |
| `shared_ptr` | Shared ownership needed |
| `weak_ptr` | Non-owning reference to `shared_ptr` |
| Raw pointer | Non-owning, observers, performance-critical |

## Tips
- ✅ Default to `unique_ptr`
- ✅ Use `make_unique` and `make_shared`
- ✅ Use `weak_ptr` to break circular references
- ❌ Don't mix smart and raw pointer ownership
- ❌ Don't create multiple `shared_ptr` from same raw pointer

[← Back to README](README.md)
