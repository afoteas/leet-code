# Move Semantics

## Overview
C++11 feature allowing resources to be transferred from temporary objects instead of copied.

## Rvalue References
```cpp
int x = 5;       // x is lvalue
int&& y = 10;    // 10 is rvalue, y is rvalue reference

void func(int&& x) {  // Accepts only rvalues
    // x is rvalue reference
}
```

## std::move
```cpp
#include <utility>

vector<int> v1 = {1, 2, 3};
vector<int> v2 = std::move(v1);  // v1 is now empty, v2 owns the data

string s1 = "hello";
string s2 = std::move(s1);  // s1 is now empty
```

## Move Constructor & Move Assignment
```cpp
class MyClass {
private:
    int* data;
    size_t size;
    
public:
    // Move constructor
    MyClass(MyClass&& other) noexcept 
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    
    // Move assignment
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;
            
            data = other.data;
            size = other.size;
            
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
    
    // Rule of 5: Destructor, copy constructor, copy assignment
    ~MyClass() { delete[] data; }
    MyClass(const MyClass& other);
    MyClass& operator=(const MyClass& other);
};
```

## When to Use
- ✅ Returning large objects from functions
- ✅ Transferring ownership of resources
- ✅ Implementing containers
- ✅ Performance optimization

## Common Mistakes
- ❌ Using moved-from objects
- ❌ Moving objects you still need
- ❌ Forgetting `noexcept` on move operations

[← Back to README](README.md)
