# Memory Management

## Overview
Understanding stack vs heap allocation, memory leaks, and performance implications.

## Stack vs Heap

### Stack Allocation
```cpp
void function() {
    int x = 5;  // Stack allocated
    int arr[100];  // Stack allocated
    // Automatically cleaned up when function returns
}
```

### Heap Allocation
```cpp
void function() {
    int* p = new int(5);  // Heap allocated
    int* arr = new int[100];  // Heap allocated
    
    // Must manually delete
    delete p;
    delete[] arr;
}
```

## Memory Leaks

### Common Causes
```cpp
// Leak: forgot to delete
void leak() {
    int* p = new int(5);
    return;  // Memory leaked
}

// Exception safety issue
void unsafe() {
    int* p = new int(5);
    throw exception();  // Memory leaked
    delete p;  // Never reached
}
```

### Solutions
```cpp
// Use RAII (smart pointers)
void safe() {
    unique_ptr<int> p = make_unique<int>(5);
    throw exception();  // p automatically deleted
}
```

## Memory Alignment
```cpp
struct alignas(16) AlignedStruct {
    int x;
};

// Check alignment
cout << alignof(AlignedStruct);
```

## Performance Tips
- Stack allocation is faster than heap
- Avoid unnecessary allocations
- Reserve capacity for containers
- Use move semantics to avoid copies
- Consider object pools for frequent allocations

## Tools
- Valgrind (Linux): memory leak detection
- AddressSanitizer: memory error detection
- Custom allocators for performance

[← Back to README](README.md)
