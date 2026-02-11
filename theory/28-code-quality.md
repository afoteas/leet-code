# Code Quality

## Overview
Principles and practices for writing clean, maintainable code.

## Clean Code Principles

### Meaningful Names
```cpp
// Bad
int d;  // elapsed time in days

// Good
int elapsedTimeInDays;
```

### Small Functions
```cpp
// Do one thing well
void processUser(User& user) {
    validateUser(user);
    saveUser(user);
    notifyUser(user);
}
```

### Don't Repeat Yourself (DRY)
```cpp
// Extract common logic
double calculateTax(double amount, double rate) {
    return amount * rate;
}
```

### Comments
```cpp
// Comments should explain WHY, not WHAT

// Bad: Stating the obvious
i++;  // increment i

// Good: Explaining reasoning
i++;  // Skip header row
```

## Refactoring Techniques

### Extract Method
```cpp
// Before
void processOrder() {
    // validate order
    // calculate total
    // save to database
}

// After
void processOrder() {
    validateOrder();
    calculateTotal();
    saveToDatabase();
}
```

### Replace Magic Numbers
```cpp
// Bad
if (status == 1) { ... }

// Good
const int STATUS_ACTIVE = 1;
if (status == STATUS_ACTIVE) { ... }
```

## Testing

### Unit Tests
```cpp
#include <cassert>

void testAdd() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
}
```

### Test-Driven Development (TDD)
1. Write failing test
2. Write minimal code to pass
3. Refactor

## Error Handling
```cpp
// Use exceptions for exceptional cases
void processFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file");
    }
    // Process file
}
```

## Code Review Checklist
- [ ] Does it work correctly?
- [ ] Is it readable?
- [ ] Is it maintainable?
- [ ] Are there tests?
- [ ] Are edge cases handled?
- [ ] Is error handling appropriate?
- [ ] Any code duplication?
- [ ] Are names meaningful?

[← Back to README](README.md)
