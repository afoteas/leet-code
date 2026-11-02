# JVM Memory Model & Garbage Collection

## Overview
Java has no manual `malloc`/`delete` — memory is managed by the JVM and reclaimed by the garbage collector. For interviews you must know the memory regions, object lifecycle, GC generations, and the classic "memory leak" patterns that exist even in managed languages.

## JVM Runtime Memory Areas

```
┌──────────────────────────────────────────────┐
│  Heap (shared across threads)                │
│  ├── Young Generation                        │
│  │   ├── Eden        (new objects)           │
│  │   └── Survivor S0/S1 (from-space/to-space)│
│  └── Old Generation (Tenured)                │
├──────────────────────────────────────────────┤
│  Metaspace (class metadata, native memory)   │
├──────────────────────────────────────────────┤
│  Thread stacks (per thread)                  │
│  ├── Stack frames (locals, operand stack)    │
│  └── Program counter                         │
├──────────────────────────────────────────────┤
│  PC registers, native method stacks          │
└──────────────────────────────────────────────┘
```

| Region | Stores | Cleaned by | Failure |
| ------ | ------ | ---------- | ------- |
| Heap | Objects, arrays | Garbage collector | `OutOfMemoryError: Java heap space` |
| Thread stack | Local variables, frames | Stack unwinding (GC of frames) | `StackOverflowError` |
| Metaspace | Class/method metadata | Class unloading | `OutOfMemoryError: Metaspace` |

## Stack vs Heap

```java
void example() {
    int x = 42;                 // primitive — lives in the stack frame
    int[] arr = new int[10];    // arr reference on stack, array OBJECT on heap
    Object obj = new Object();  // reference on stack, object on heap
}
// When example() returns, the frame is popped; arr/obj become unreachable → GC eligible
```

- **Primitives** (`int`, `double`, `boolean`, `char`, ...) live in the stack frame or inside objects
- **References** live on the stack; the objects they point to live on the heap
- Objects are always heap-allocated (except scalar-replacement via escape analysis, which is an optimization, not a guarantee)
- Java has **no pointer arithmetic** and cannot access raw addresses

## Object Lifecycle & Garbage Collection

### Reachability (what gets collected)
An object is eligible for GC when it is **unreachable from any GC root**:
GC roots = live thread stacks, static fields, JNI references, active monitors.

```java
Object a = new Object();  // reachable
a = null;                 // now unreachable → eligible

// Subtle: object inside a reachable collection is NOT collected
static List<Object> cache = new ArrayList<>();  // classic leak source
cache.add(new byte[1024]);                      // never collected while class is loaded
```

### Generational GC (the core idea)
- **Most objects die young** → collect Eden frequently with cheap copying (minor GC)
- Survivors are copied between S0/S1; after surviving ~15 GC cycles they're promoted to Old
- Old gen fills slowly → occasional **major/full GC** (mark-sweep-compact)

### Common Collectors (know the names & trade-offs)
| Collector | Idea | When |
| --------- | ---- | ---- |
| **G1** (default since Java 9) | Region-based, incremental, predictable pause targets | General purpose |
| **ZGC / Shenandoah** | Concurrent, sub-millisecond pauses | Low-latency apps |
| **Serial / Parallel** | Simple stop-the-world, throughput-oriented | Small heaps / batch |

- **Stop-the-world (STW):** all application threads pause during (parts of) GC
- **Mark:** find reachable objects → **Sweep:** free the rest → **Compact:** defragment
- Interview sound bite: "Throughput vs latency — you pay for shorter pauses with some throughput overhead."

## Reference Types (GC interaction)

```java
Object s = new Object();

StrongReference strong = s;              // normal — never collected while reachable
SoftReference<Object> soft = new SoftReference<>(s);   // cleared under memory pressure
WeakReference<Object> weak = new WeakReference<>(s);   // cleared at next GC if only weakly reachable
PhantomReference<Object> ph = new PhantomReference<>(s, null); // for cleanup bookkeeping

// WeakHashMap: entries vanish when the KEY is weakly reachable (cache idiom)
WeakHashMap<Object, Object> cache = new WeakHashMap<>();
```

## Memory Leaks in Java (yes, they exist!)

Java leaks = **unreachable-by-intent but still-referenced objects**. Classic patterns:

```java
// 1. Static collections that only grow
private static final List<Session> sessions = new ArrayList<>();

// 2. Listeners / callbacks never unregistered
button.addActionListener(listener);   // forget removeActionListener → leak

// 3. Unclosed resources (pre-Java 7 style)
Connection c = dataSource.getConnection();  // never closed → native memory leak

// 4. Inner classes holding outer references
class Outer {
    class Inner { }          // Inner holds hidden reference to Outer
    Runnable r = () -> ...;  // lambdas capture enclosing `this` too
}

// 5. ThreadLocal in pooled threads (thread never dies → value never collected)
static ThreadLocal<byte[]> tl = new ThreadLocal<>();
tl.set(new byte[1024 * 1024]);
tl.remove();   // REQUIRED in thread pools!
```

**Fixes:** try-with-resources, `remove()` on ThreadLocal, unbind listeners, bound caches (`WeakHashMap`, Caffeine), prefer static nested classes.

## try-with-resources (RAII equivalent)

```java
// Anything implementing AutoCloseable
try (BufferedReader br = Files.newBufferedReader(path);
     Connection conn = dataSource.getConnection()) {
    return br.readLine();
}   // closed automatically in reverse order, even on exception
// Suppressed exceptions preserved via getSuppressed()
```

## Strings & the String Pool

```java
String a = "hello";              // literal → String Pool (in heap, since Java 7)
String b = "hello";              // same pooled object → a == b is true
String c = new String("hello");  // fresh heap object → a == c is false
String d = c.intern();           // returns pooled instance → a == d is true

// Strings are immutable → safe to share/pool; concatenation in a loop is O(n²)!
StringBuilder sb = new StringBuilder();   // mutable, not thread-safe (use this)
sb.append('a').append("bc");
String result = sb.toString();

StringBuffer sb2 = new StringBuffer();    // like StringBuilder but synchronized (slower)
```

## Autoboxing & the Integer Cache

```java
Integer x = 127, y = 127;
x == y;             // true  (cached pool −128..127)

Integer a = 128, b = 128;
a == b;             // FALSE — different heap objects! (undefined behavior trap)
a.equals(b);        // true  (correct comparison)
a.intValue() == b.intValue();  // true

// Boxing cost: Integer[] uses ~4x memory of int[] (object header + padding)
int[] fast = new int[n];       // prefer primitives in hot paths
```

## Escape Analysis & Scalar Replacement
The JIT can keep a non-escaping `new` object entirely on the stack (or eliminate it):
```java
int sum() {
    Point p = new Point(1, 2);  // p never escapes → allocation may be eliminated
    return p.x + p.y;
}
```
Sound bite: "Allocation in Java is cheap (bump-pointer in TLAB); *collection* is what costs."

## Interview Checklist
- [ ] Heap vs stack: where does each value live?
- [ ] What makes an object GC-eligible? (unreachable from GC roots)
- [ ] Generational hypothesis and minor vs major GC
- [ ] G1 vs ZGC vs Parallel — throughput vs latency
- [ ] Soft/weak/phantom references and WeakHashMap
- [ ] 3 ways Java apps still leak memory + how to prevent each
- [ ] try-with-resources == Java's RAII
- [ ] String pool and `==` vs `equals`
- [ ] Integer cache trap (−128..127)
