# Modern Java (8–21)

## Overview
Java 8+ introduced functional-style programming: lambdas, method references, the Streams API, and `Optional`. Later versions added `var`, records, switch expressions, and pattern matching. These features dominate modern Java interview answers.

## Lambdas & Functional Interfaces

A lambda is an instance of a **functional interface** (exactly one abstract method):

```java
// Syntax: (params) -> expression   or   (params) -> { statements; }
Comparator<Integer> cmp = (a, b) -> a - b;
Runnable r = () -> System.out.println("go");
Function<String, Integer> len = String::length;    // method reference

// Built-in functional interfaces (java.util.function)
Predicate<T>  test  = s -> s.isEmpty();      // T -> boolean      test(), and(), or(), negate()
Function<T,R> apply = s -> s.length();       // T -> R            andThen(), compose()
Supplier<T>   get   = ArrayList::new;        // () -> T
Consumer<T>   accept= System.out::println;   // T -> void         andThen()
UnaryOperator<T> u  = x -> x.trim();         // T -> T
BinaryOperator<Integer> add = Integer::sum;  // (T,T) -> T
BiFunction<A,B,R> bf = (a, b) -> ...;
```

**Capture rules:** lambdas capture effectively-final locals and `this` (unlike anonymous inner classes, which get their own `this`). Can't mutate captured locals.

```java
int x = 5;
// () -> x++               ✗ — x must be effectively final
Supplier<Integer> s = () -> x * 2;   // ✓
```

## Method References

```java
ClassName::staticMethod     // Integer::parseInt
instance::method            // System.out::println
ClassName::instanceMethod   // String::length      (arg becomes receiver)
ClassName::new              // ArrayList::new, int[]::new
```

## Streams API

A stream is a **lazy, single-use pipeline** over data (not a collection):

```java
List<String> names = List.of("Alice", "Bob", "Anna", "Charlie");

List<String> result = names.stream()
    .filter(n -> n.startsWith("A"))     // intermediate ops (lazy)
    .map(String::toUpperCase)
    .sorted()
    .limit(10)
    .collect(Collectors.toList());      // terminal op (triggers execution)
```

### Key Operations
```java
// Filter / transform
stream.filter(p -> p.age > 18)
      .map(Person::getName)
      .flatMap(List::stream)            // flatten nested structures
      .distinct()
      .peek(System.out::println);       // debug (lazy!)

// Reduce
int sum = stream.reduce(0, Integer::sum);
int sum2 = stream.mapToInt(Integer::intValue).sum();   // specialized — preferred

// Collect
List<String> list = stream.collect(Collectors.toList());
String joined = stream.collect(Collectors.joining(", "));
Map<Dept, List<Employee>> byDept =
    stream.collect(Collectors.groupingBy(Employee::getDept));
Map<Boolean, List<String>> parts =
    stream.collect(Collectors.partitioningBy(s -> s.length() > 3));
long count = stream.collect(Collectors.counting());    // or stream.count()
Optional<String> max = stream.max(Comparator.naturalOrder());
Map<String, Integer> toMap =
    stream.collect(Collectors.toMap(Person::getName, Person::getAge));

// Match
boolean any = stream.anyMatch(p -> p.age > 18);
boolean all = stream.allMatch(...);
boolean none = stream.noneMatch(...);
```

### Streams vs Loops — when to use which
| Streams win | Loops win |
| ----------- | --------- |
| Readable data pipelines | Simple mutations / early exit |
| Parallelism (`parallelStream`) | Performance-critical hot paths |
| Declarative intent | Need to modify enclosing state |

- Streams are **lazy**: no terminal op → nothing executes
- **Single-use**: a stream can only be consumed once
- `parallelStream()` uses the common ForkJoinPool — beware blocking/IO and shared mutable state
- Avoid side effects inside streams (no mutation of outer variables — capture rules forbid it anyway)

## Optional — fight null without exceptions

```java
Optional<String> name = Optional.of("hi");          // non-null (NPE if null!)
Optional<String> maybe = Optional.ofNullable(get()); // may be null
Optional<String> empty = Optional.empty();

// Read safely
String s = maybe.orElse("default");
String s2 = maybe.orElseGet(() -> computeDefault());   // lazy default
String s3 = maybe.orElseThrow(() -> new IllegalStateException());

// Transform
maybe.map(String::toUpperCase)
     .filter(s -> s.length() > 2)
     .ifPresent(System.out::println);

// Compose
Optional<String> flat = maybe.flatMap(s -> Optional.ofNullable(lookup(s)));

// Rules: Optional is for RETURN TYPES, not fields/parameters/collections
```

## Type Inference — `var` (Java 10+)

```java
var list = new ArrayList<String>();   // ArrayList<String> — inferred, still statically typed!
var stream = list.stream();           // readable for long generic types
// var x = null;                      ✗ — cannot infer
// var is not a keyword; it's a reserved type name
```

## Records (Java 16+) — immutable data carriers

```java
public record Point(int x, int y) { }

Point p = new Point(1, 2);
p.x(); p.y();                 // accessors (not getX())
p.equals(new Point(1, 2));    // true — value-based equals/hashCode/toString for free

// Compact constructor for validation
public record Range(int low, int high) {
    public Range {
        if (low > high) throw new IllegalArgumentException();
    }
}
```
Records replace Lombok-style boilerplate; fields are `private final`; cannot extend classes.

## Switch Expressions & Pattern Matching (14–21)

```java
// Expression form — no fall-through, must be exhaustive
String size = switch (day) {
    case MONDAY, FRIDAY, SUNDAY    -> "weekend-ish";
    case TUESDAY                   -> "mid";
    default                        -> { yield "other"; }   // block form
};

// Pattern matching for instanceof (Java 16+)
if (obj instanceof Point p) {
    System.out.println(p.x());      // p is cast & bound automatically
}

// Pattern matching for switch (Java 21)
return switch (shape) {
    case Circle c when c.radius() > 10 -> "big circle";
    case Circle c                      -> "circle";
    case Square s                      -> "square";
    case null                          -> "nothing";
    default                            -> "unknown";
};
```

## Text Blocks (Java 15+)

```java
String json = """
        {
          "name": "Ada",
          "age": 36
        }
        """;   // preserves newlines/indentation — great for SQL, JSON, HTML
```

## Sealed Classes (Java 17+)

```java
public sealed interface Shape permits Circle, Square { }
public record Circle(double r) implements Shape { }
public final class Square implements Shape { }   // must be final, sealed, or non-sealed
// Enables exhaustive switch over a closed hierarchy
```

## Modern Java Performance Notes (interview sound bites)
- Lambdas compile to `invokedynamic` — no anonymous-class allocation per call site after the first
- Streams add modest overhead vs raw loops; JIT often fuses the pipeline, but `for` loops can still win in microbenchmarks
- Autoboxing in `Stream<Integer>` pipelines is the real hidden cost → prefer `IntStream`/`LongStream`/`DoubleStream`
- Records are plain immutable objects — no runtime magic beyond generated methods
- `Optional` allocation is usually scalar-replaced by escape analysis

## Interview Checklist
- [ ] Lambda vs anonymous class: `this` semantics, effectively-final capture
- [ ] The 6 `java.util.function` interfaces and when each applies
- [ ] Stream pipeline: intermediate vs terminal, laziness, single-use
- [ ] `groupingBy`, `partitioningBy`, `toMap`, `joining`, `reduce` — write fluently
- [ ] `Optional` misuse: fields, parameters, `get()` without checking
- [ ] Records: generated methods, immutability, compact constructors
- [ ] Switch expressions + pattern matching exhaustiveness
- [ ] PECS again — it governs stream method signatures too
