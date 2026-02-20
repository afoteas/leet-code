# Modern C++ (C++11/14/17/20)

## Auto
```cpp
auto x = 5;  // int
auto s = "hello"s;  // string
auto v = vector<int>{1, 2, 3};

// With structured bindings (C++17)
auto [key, value] = *map.begin();
```

## Range-Based For Loops
```cpp
vector<int> v = {1, 2, 3, 4, 5};

for (int x : v) {  // Copy
    cout << x;
}

for (const auto& x : v) {  // Const reference (preferred)
    cout << x;
}

for (auto& x : v) {  // Reference (for modification)
    x *= 2;
}
```

## Lambdas
```cpp
// Basic lambda
auto add = [](int a, int b) { return a + b; };

// Capture by value
int x = 5;
auto f1 = [x]() { return x * 2; };

// Capture by reference
auto f2 = [&x]() { x *= 2; };

// Capture all by value
auto f3 = [=]() { return x + y; };

// Capture all by reference
auto f4 = [&]() { x++; y++; };

// Generic lambda (C++14)
auto print = [](const auto& x) { cout << x; };
```

## nullptr
```cpp
int* p = nullptr;  // Instead of NULL or 0
```

## Uniform Initialization
```cpp
int x{5};
vector<int> v{1, 2, 3};
```

## std::optional (C++17)
```cpp
#include <optional>

optional<int> find(const vector<int>& v, int target) {
    auto it = std::find(v.begin(), v.end(), target);
    if (it != v.end()) {
        return *it;
    }
    return nullopt;
}

// Usage
if (auto result = find(v, 5)) {
    cout << *result;
}
```

## std::variant (C++17)
```cpp
#include <variant>

variant<int, string> v = 42;
v = "hello"s;

// Access
if (holds_alternative<string>(v)) {
    cout << get<string>(v);
}
```

## Constexpr
```cpp
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

constexpr int x = factorial(5);  // Computed at compile time
```

## Concepts (C++20)
```cpp
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template<Addable T>
T add(T a, T b) {
    return a + b;
}
```

## Ranges (C++20)
```cpp
#include <ranges>

vector<int> v = {1, 2, 3, 4, 5};
auto even = v | views::filter([](int x) { return x % 2 == 0; })
              | views::transform([](int x) { return x * 2; });
```

[← Back to README](README.md)
