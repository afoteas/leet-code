# Java Generics

## Overview
Generics provide compile-time type safety — the Java counterpart to C++ templates, but implemented via **type erasure** (all type arguments are erased to `Object` at runtime). Interviews focus on bounded types, wildcards (PECS), and erasure limitations.

## Generic Classes

```java
public class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) { this.key = key; this.value = value; }
    public K getKey()   { return key; }
    public V getValue() { return value; }
}

Pair<String, Integer> p = new Pair<>("age", 30);   // Java 7+ diamond: new Pair<>("age", 30)
```

## Generic Methods

```java
public static <T> T getFirst(List<T> list) {
    return list.get(0);
}

// Type parameter before the return type; inferred from arguments
String s = getFirst(List.of("a", "b"));
```

## Bounded Type Parameters

```java
// T must be a subtype of Comparable<T> → can call compareTo
public static <T extends Comparable<T>> T max(List<T> list) {
    T best = list.get(0);
    for (T x : list) if (x.compareTo(best) > 0) best = x;
    return best;
}

// Multiple bounds: class first, then interfaces
public static <T extends Number & Comparable<T>> T maxNum(List<T> list) { ... }

// Recursive bound — the idiom for enum "self types"
public static <E extends Enum<E>> E parse(Class<E> type, String name) {
    return Enum.valueOf(type, name);
}
```

## Wildcards

```java
// Unbounded — read as Object, write nothing (except null)
void printAll(List<?> list) { for (Object o : list) System.out.println(o); }

// Upper-bounded (covariant): "a list of some subtype of Number"
// READ as Number; cannot add (except null)
double sum(List<? extends Number> list) {
    double s = 0;
    for (Number n : list) s += n.doubleValue();
    return s;
}

// Lower-bounded (contravariant): "a list of some supertype of Integer"
// WRITE as Integer; reads come back as Object
void addIntegers(List<? super Integer> list) {
    list.add(1);           // OK — Integer is a subtype of whatever ? is
    Object o = list.get(0); // only Object is safe to read
}
```

### PECS — Producer Extends, Consumer Super
- If the structure **produces** values (you read from it) → `? extends T`
- If the structure **consumes** values (you write to it) → `? super T`
- Both produce and consume → use a plain `T`, no wildcard

```java
// Copy src (producer) into dest (consumer) — the classic PECS signature
public static <T> void copy(List<? super T> dest, List<? extends T> src) {
    for (T item : src) dest.add(item);
}
// Also: Collections.copy(dest, src), Comparator.comparing(…)
```

## Type Erasure — what it means & its limits

The compiler erases type arguments to their leftmost bound (`Object` if unbounded):
```java
List<String> a = new ArrayList<>();
List<Integer> b = new ArrayList<>();
a.getClass() == b.getClass();   // TRUE — both are ArrayList.class at runtime
```

**Consequences (classic interview questions):**
```java
// 1. Cannot instantiate type parameters
// public <T> T make() { return new T(); }        ✗

// 2. Cannot create generic arrays
// List<String>[] arr = new List<String>[10];     ✗
List<?>[] arr = new List<?>[10];                 // ✓ (unchecked warning)

// 3. Cannot use instanceof with parameterized types
// if (x instanceof List<String>)                 ✗
if (x instanceof List<?>)                        // ✓

// 4. Cannot use primitives as type arguments
// List<int> nums;                                ✗
List<Integer> nums;                              // ✓ (autoboxing cost!)

// 5. Cannot overload solely on type parameters
// void f(List<String> l); void f(List<Integer> l);  ✗ same erasure

// 6. Static context cannot reference class type parameters
// class Box<T> { static T value; }               ✗
```

## Bridge Methods & Covariant Returns

```java
class StringBox implements Comparable<StringBox> {
    public int compareTo(StringBox other) { return 0; }
}
// Compiler generates a synthetic bridge:
//   int compareTo(Object other) { return compareTo((StringBox) other); }
```
Sound bite: "Erasure keeps generics backward-compatible with pre-generics bytecode — bridges and casts are inserted where needed."

## Generic Idioms for Interviews

```java
// Type-safe heterogeneous container (the "Favorites" pattern from Effective Java)
class Favorites {
    private final Map<Class<?>, Object> map = new HashMap<>();
    public <T> void put(Class<T> type, T value) { map.put(type, value); }
    public <T> T get(Class<T> type) { return type.cast(map.get(type)); }
}

// Generic node — trees & linked lists
class TreeNode<T> {
    T val;
    TreeNode<T> left, right;
    TreeNode(T val) { this.val = val; }
}

// Bounded wildcard with comparators
static <T extends Comparable<? super T>> void sort(List<T> list) {
    list.sort(Comparator.naturalOrder());   // ? super T accepts e.g. Comparable<Object> subtypes
}
```

## Variance: C++ vs Java vs C#

| Feature | C++ | Java | C# |
| ------- | --- | ---- | -- |
| Generic mechanism | Templates (monomorphization) | Type erasure | Reified generics |
| Variance at declaration | N/A | Invariant | `out` / `in` (declaration-site) |
| Variance at use site | N/A | `? extends` / `? super` | `IEnumerable<out T>` etc. |
| Reified at runtime | Yes (per instantiation) | No | Yes |
| Primitives as args | Yes | No (boxing) | Yes (specialization) |

## Interview Checklist
- [ ] `<T extends Comparable<T>>` — why the bound is needed
- [ ] PECS: producer `extends`, consumer `super`
- [ ] What erasure erases to, and all 6 limitations it imposes
- [ ] Why `List<String>` and `List<Integer>` share one `Class` object
- [ ] Wildcard vs type parameter: `List<?>` vs `<T> void f(List<T>)`
- [ ] `Class<T>.cast` for type-safe heterogeneous containers
