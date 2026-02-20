# Const Correctness

## Overview
Proper use of `const` to prevent unintended modifications and document intent.

## Const Variables
```cpp
const int x = 5;  // Cannot modify x
x = 10;  // Error
```

## Const Pointers
```cpp
int value = 5;

const int* p1 = &value;  // Pointer to const int
*p1 = 10;  // Error: cannot modify through p1
p1 = &other;  // OK: can change pointer

int* const p2 = &value;  // Const pointer to int
*p2 = 10;  // OK: can modify through p2
p2 = &other;  // Error: cannot change pointer

const int* const p3 = &value;  // Const pointer to const int
*p3 = 10;  // Error
p3 = &other;  // Error
```

## Const Member Functions
```cpp
class MyClass {
private:
    int value;
    mutable int cache;  // Can be modified in const functions
    
public:
    // Const member function - promises not to modify object
    int getValue() const {
        cache++;  // OK: mutable
        return value;
    }
    
    // Non-const version
    int& getValue() {
        return value;  // Can return non-const reference
    }
    
    void setValue(int v) {
        value = v;  // Modifies object, cannot be const
    }
};
```

## Const Parameters
```cpp
// Pass by const reference (efficient, safe)
void process(const vector<int>& data) {
    // Cannot modify data
}

// For built-in types, pass by value
void calculate(int value) {
    // value is a copy anyway
}
```

## Const Return Values
```cpp
// Return const reference to prevent modification
class Container {
private:
    vector<int> data;
    
public:
    const vector<int>& getData() const {
        return data;
    }
};
```

## Best Practices
- ✅ Make member functions `const` if they don't modify state
- ✅ Pass objects by `const reference` when not modifying
- ✅ Use `const` for variables that shouldn't change
- ✅ Const-correctness catches bugs at compile time
- ✅ Documents intent to other developers

## Common Patterns
```cpp
// Getter should be const
int getSize() const { return size; }

// Setter cannot be const
void setSize(int s) { size = s; }

// Overload on const
const T& operator[](size_t i) const { return data[i]; }
T& operator[](size_t i) { return data[i]; }
```

[← Back to README](README.md)
