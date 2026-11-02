# Java OOP & Language Essentials

## Overview
The core language mechanics every senior Java engineer is expected to know cold: OOP principles and their Java flavor, the object lifecycle, key keywords (`static`, `final`, `this`, `super`), exceptions, and the everyday traps (String immutability, equals/hashCode, autoboxing).

## Interfaces vs Abstract Classes

```java
// Interface — "can do" contract; multiple inheritance of type
public interface Drawable {
    void draw();                        // public abstract
    default void clear() { }            // Java 8+: default method (has body)
    static Drawable of() { ... }        // static helper
    int MAX = 10;                       // public static final (constant)

    private void helper() { }           // Java 9+: private methods for sharing code
}

// Abstract class — "is a" base; single inheritance; can hold state
public abstract class Shape {
    protected int sides;                // shared state
    public Shape(int sides) { this.sides = sides; }
    public abstract double area();      // must be implemented
    public double perimeter() { return 0; }   // can provide defaults
}
```

| | Interface | Abstract class |
| --- | --- | --- |
| Multiple inheritance | ✓ (many interfaces) | ✗ (one superclass) |
| State / fields | constants only | any fields |
| Constructors | ✗ | ✓ |
| Use when | defining a capability/contract | sharing code + state among relatives |

## The Four Pillars (Java flavor)

```java
// 1. ENCAPSULATION — private fields + accessors; expose behavior, hide state
public class BankAccount {
    private BigDecimal balance;                    // hidden
    public void deposit(BigDecimal amount) { ... } // behavior
}

// 2. INHERITANCE — extends; reuse and specialize (favor composition!)
// 3. POLYMORPHISM — dynamic dispatch: the OVERRIDDEN method runs based on runtime type
class Animal  { void speak() { System.out.println("..."); } }
class Dog     extends Animal { @Override void speak() { System.out.println("woof"); } }
Animal a = new Dog();
a.speak();   // "woof" — virtual dispatch (all non-private, non-static, non-final methods are virtual)

// 4. ABSTRACTION — interfaces/abstract classes hide implementation detail
```

### Overloading vs Overriding
```java
// Overloading: same name, DIFFERENT parameter list — resolved at COMPILE time
int add(int a, int b) { ... }
int add(int a, int b, int c) { ... }

// Overriding: same signature in subclass — resolved at RUNTIME (dynamic dispatch)
// Rules: cannot reduce visibility, cannot widen checked exceptions,
//        return type may be covariant (subtype)
@Override
public Dog clone() { ... }   // covariant return vs Animal clone()
```

## Object Lifecycle & Key Keywords

```java
public class Example extends Base {
    static int count = 0;            // one copy per CLASS (loaded once)
    final int id;                    // assigned once (in constructor); reference is fixed, object may be mutable
    private final List<Integer> data = new ArrayList<>();  // final ≠ immutable!

    Example(int id) {
        super();                     // must be FIRST statement (implicit if parent has no-arg ctor)
        this.id = id;                // `this` = current instance
        count++;
    }

    static Example create() { ... }  // static: no instance context; cannot use this/super
}
```
- **Construction order:** static initializers (class load) → superclass ctor → instance initializers/field order → constructor body
- **`final`:** variable = assign-once · method = no override · class = no extension
- **`static` nested class:** no outer-instance reference (prefer it over inner classes to avoid leaks)
- **Immutability recipe:** `final` class + `private final` fields + no setters + defensive copies of mutable inputs

## equals / hashCode / toString (the trio)

```java
public record Point(int x, int y) { }   // gets all three for free

// Hand-written version (see 36-java-collections.md for the contract)
@Override public boolean equals(Object o) {
    if (this == o) return true;
    if (!(o instanceof Point p)) return false;
    return x == p.x && y == p.y;
}
@Override public int hashCode() { return Objects.hash(x, y); }
@Override public String toString() { return "Point(" + x + ", " + y + ")"; }
```
Rules: equal objects ⇒ equal hash codes; never use mutable fields as hash keys; override both or neither.

## Strings (again, because everyone asks)

```java
String s = "abc";          // immutable, pooled
s.concat("d");             // returns NEW string; s unchanged
s.substring(1);            // new String
char c = s.charAt(0);
s.toCharArray();           // copy — common in char-array two-pointer problems
s.split(",");
String.join("-", parts);
s.trim();                  // or strip() (Unicode-aware, Java 11+)
s.repeat(3);               // Java 11+
s.isBlank();               // Java 11+
s.equals(other);           // value comparison — NEVER == for strings
```
- `StringBuilder` for concatenation in loops (O(n) vs O(n²) with `+`)
- `String` is `final` — safe to share, hash cacheable, security-friendly

## Exceptions

```java
                    Throwable
                   /         \
              Error          Exception
          (OOM, SOE)        /         \
                      IOException   RuntimeException
                      (checked)     (unchecked: NPE, AIOOBE, ...)
```

```java
// try / catch / finally / multi-catch / try-with-resources
try (Connection c = open(); BufferedReader r = openReader()) {
    risky();
} catch (IOException | SQLException e) {     // multi-catch (disjoint types)
    log(e);
} finally {
    cleanup();                                 // always runs (careful: don't throw from here)
}

// Custom exception
public class ValidationException extends Exception {          // checked
    public ValidationException(String msg) { super(msg); }
}
public class NotFoundException extends RuntimeException { }   // unchecked (preferred for programming errors)
```
- **Checked** (`Exception` subclasses): compiler forces handling — good for recoverable conditions
- **Unchecked** (`RuntimeException`): programming errors — don't declare them needlessly
- Never swallow exceptions (`catch (Exception e) { }`) and never `e.printStackTrace()` in production code
- Wrap low-level exceptions instead of leaking implementation details across layers

## Composition over Inheritance

```java
// Fragile base class problem: inheriting exposes internals & couples forever
class Stack extends ArrayList<Object> { }     // ✗ push/pop inherited add/get — leaks the API

class Stack<T> implements Iterable<T> {       // ✓ wrap, delegate, expose only what's needed
    private final Deque<T> items = new ArrayDeque<>();
    public void push(T x) { items.push(x); }
    public T pop() { return items.pop(); }
}
```
Sound bite: "Inheritance is white-box reuse (subclasses see internals); composition is black-box reuse and stays flexible."

## SOLID (Java mapping)
| Principle | Java idiom |
| --------- | ---------- |
| **S**ingle responsibility | small classes, one reason to change |
| **O**pen/closed | interfaces + polymorphism; `switch` over sealed hierarchies |
| **L**iskov substitution | overrides must honor the base contract (no strengthened preconditions) |
| **I**nterface segregation | small, focused interfaces (`Runnable`, `Closeable`) |
| **D**ependency inversion | depend on interfaces; inject via constructor |

## Everyday Traps Cheat Sheet
- `==` compares references for objects; `equals` compares values
- `Integer a = 128, b = 128; a == b` → **false** (cache is −128..127)
- `final List<String> l` — the reference is fixed, the list is still mutable
- `Math.abs(Integer.MIN_VALUE)` is still negative (overflow)
- `ArrayList.remove(int)` vs `remove(Object)` — autoboxing picks the overload
- `char` + `char` promotes to `int`: `'1' + 1` is `50`, not `'2'`
- Modifying a collection while iterating it → `ConcurrentModificationException`
- `static` methods are NOT virtual — hiding, not overriding
- Constructors are not inherited; `super()` must be the first statement

## Interview Checklist
- [ ] Interface vs abstract class — pick one in 10 seconds with justification
- [ ] Compile-time overloading vs runtime overriding; covariant returns
- [ ] Object construction order (static → super → fields → body)
- [ ] equals/hashCode/toString contract and when records suffice
- [ ] Checked vs unchecked exceptions; try-with-resources
- [ ] Composition over inheritance (the `Stack extends ArrayList` example)
- [ ] SOLID translated into concrete Java code
