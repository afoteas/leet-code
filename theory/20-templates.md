# Templates

## Overview
Generic programming feature allowing functions and classes to work with any data type.

## Function Templates
```cpp
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage
int i = max(5, 10);
double d = max(3.14, 2.71);
```

## Class Templates
```cpp
template<typename T>
class Stack {
private:
    vector<T> data;
    
public:
    void push(const T& item) {
        data.push_back(item);
    }
    
    T pop() {
        T item = data.back();
        data.pop_back();
        return item;
    }
    
    bool empty() const {
        return data.empty();
    }
};

// Usage
Stack<int> intStack;
Stack<string> stringStack;
```

## Template Specialization
```cpp
// Primary template
template<typename T>
class Container {
    // General implementation
};

// Specialization for bool
template<>
class Container<bool> {
    // Optimized implementation for bool
};
```

## Variadic Templates
```cpp
template<typename... Args>
void print(Args... args) {
    (cout << ... << args) << '\n';
}

// Usage
print(1, 2, 3, "hello", 3.14);
```

## SFINAE (Substitution Failure Is Not An Error)
```cpp
template<typename T>
typename enable_if<is_integral<T>::value, T>::type
processNumber(T value) {
    return value * 2;
}
```

## Concepts (C++20)
```cpp
template<typename T>
concept Numeric = is_arithmetic_v<T>;

template<Numeric T>
T add(T a, T b) {
    return a + b;
}
```

## Tips
- Templates are instantiated at compile time
- Can lead to code bloat if overused
- Compiler errors can be difficult to read
- Use constraints (concepts in C++20) to improve error messages

[← Back to README](README.md)
