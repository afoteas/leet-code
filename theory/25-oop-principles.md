# OOP Principles

## Overview
Object-Oriented Programming principles for maintainable, extensible code.

## Four Pillars

### 1. Encapsulation
```cpp
class BankAccount {
private:
    double balance;  // Hidden implementation
    
public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    double getBalance() const {
        return balance;
    }
};
```

### 2. Inheritance
```cpp
class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!";
    }
};
```

### 3. Polymorphism
```cpp
Animal* animal = new Dog();
animal->makeSound();  // Calls Dog::makeSound()
```

### 4. Abstraction
```cpp
class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};
```

## SOLID Principles

### S - Single Responsibility
Class should have one reason to change.

### O - Open/Closed
Open for extension, closed for modification.

### L - Liskov Substitution
Subtypes must be substitutable for base types.

### I - Interface Segregation
Many specific interfaces better than one general.

### D - Dependency Inversion
Depend on abstractions, not concretions.

## Design Patterns

### Creational
- **Singleton**: One instance only
- **Factory**: Create objects without specifying class
- **Builder**: Construct complex objects step-by-step

### Structural
- **Adapter**: Make incompatible interfaces work together
- **Decorator**: Add functionality dynamically
- **Facade**: Simplified interface to complex system

### Behavioral
- **Observer**: Notify dependents of state changes
- **Strategy**: Encapsulate algorithms
- **Template Method**: Define skeleton, subclasses fill in

[← Back to README](README.md)
