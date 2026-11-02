# Java Collections Framework

## Overview
The Java Collections Framework (JCF) provides containers, algorithms, and iterators — the Java equivalent of the STL. Know the interfaces (`List`, `Set`, `Queue`, `Map`), the main implementations, and their complexities.

## Interface Hierarchy

```
Iterable
└── Collection
    ├── List      (ordered, duplicates)  → ArrayList, LinkedList, Vector
    ├── Set       (unique)               → HashSet, LinkedHashSet, TreeSet
    └── Queue     (FIFO)                 → PriorityQueue, ArrayDeque, LinkedList

Map (not a Collection!)                  → HashMap, LinkedHashMap, TreeMap, Hashtable
```

## List

### ArrayList (Dynamic Array)
```java
List<Integer> list = new ArrayList<>();
list.add(1);                  // Append, amortized O(1)
list.add(0, 5);               // Insert at index, O(n)
list.get(0);                  // Random access, O(1)
list.set(0, 10);              // Replace, O(1)
list.remove(0);               // Remove by index, O(n) shift
list.remove(Integer.valueOf(5)); // Remove by VALUE (careful with autoboxing!)
list.size();
list.isEmpty();
list.contains(3);             // O(n)
list.indexOf(3);
list.subList(1, 3);           // View, O(1)

Collections.sort(list);                        // O(n log n)
list.sort(Comparator.reverseOrder());

// Best for: Random access, iteration, general-purpose list
// Backed by an array; grows by 1.5x (newCapacity = old + (old >> 1))
```

### LinkedList (Doubly-Linked List) & Deque
```java
Deque<Integer> dq = new LinkedList<>();
dq.addFirst(1);
dq.addLast(2);
dq.removeFirst();
dq.removeLast();
dq.peekFirst();
dq.peekLast();
dq.get(2);  // O(n) traversal!

// Note: in Java, prefer ArrayDeque over LinkedList for stacks/queues
// (LinkedList has per-node allocation overhead)
```

### ArrayDeque (Best Stack / Queue)
```java
Deque<Integer> stack = new ArrayDeque<>();
stack.push(1);      // == addFirst
stack.pop();        // == removeFirst
stack.peek();       // == peekFirst

Deque<Integer> queue = new ArrayDeque<>();
queue.addLast(1);   // enqueue
queue.removeFirst();// dequeue
queue.peekFirst();

// Best for: Stack and queue operations — faster than Stack and LinkedList
// Resizable circular array; no null elements allowed
```

## Set

```java
Set<Integer> hashSet = new HashSet<>();          // O(1) ops, unordered
Set<Integer> linked = new LinkedHashSet<>();     // O(1) ops, insertion order
Set<Integer> treeSet = new TreeSet<>();          // O(log n) ops, sorted

hashSet.add(1);
hashSet.contains(1);
hashSet.remove(1);
hashSet.size();

// TreeSet extras (sorted)
treeSet.first();
treeSet.last();
treeSet.floor(7);    // greatest element ≤ 7
treeSet.ceiling(7);  // smallest element ≥ 7
treeSet.headSet(7);  // view of elements < 7
treeSet.tailSet(7);  // view of elements ≥ 7

// Set algebra (Java 9+ convenience on List, or manual on Set)
Set<Integer> union = new HashSet<>(a);
union.addAll(b);                    // union
Set<Integer> inter = new HashSet<>(a);
inter.retainAll(b);                 // intersection
Set<Integer> diff = new HashSet<>(a);
diff.removeAll(b);                  // difference
```

## Map

### HashMap (Hash Table) — the workhorse
```java
Map<String, Integer> map = new HashMap<>();
map.put("a", 1);
map.get("a");              // null if absent
map.getOrDefault("b", 0);  // safe lookup — great in interviews
map.containsKey("a");
map.remove("a");
map.putIfAbsent("a", 1);
map.merge("a", 1, Integer::sum);  // frequency counting!
map.size();

// Iterate
for (Map.Entry<String, Integer> e : map.entrySet()) {
    e.getKey();
    e.getValue();
}
map.forEach((k, v) -> System.out.println(k + "=" + v));

// Frequency counting idiom
Map<Character, Integer> freq = new HashMap<>();
for (char c : s.toCharArray()) {
    freq.merge(c, 1, Integer::sum);
}
```

**HashMap internals (asked constantly):**
- Array of buckets; each bucket is a linked list (treeified to red-black tree when ≥ 8 nodes AND table ≥ 64)
- Default capacity 16, load factor 0.75 → doubles when size > capacity × 0.75
- `put` is O(1) average, O(log n) worst case (treeified bucket)
- Keys need proper `equals()` and `hashCode()` (see below)
- Not synchronized; use `ConcurrentHashMap` or `Collections.synchronizedMap` for threads

### TreeMap (Red-Black Tree)
```java
NavigableMap<Integer, String> tm = new TreeMap<>();
tm.put(3, "c");
tm.firstKey();
tm.lastKey();
tm.floorKey(7);      // greatest key ≤ 7
tm.ceilingKey(7);    // smallest key ≥ 7
tm.lowerKey(7);      // strict < 7
tm.higherKey(7);     // strict > 7
tm.subMap(2, 5);     // range view [2, 5)

// Best for: Ordered keys, range queries — O(log n) all operations
```

### LinkedHashMap
```java
Map<Integer, String> lhm = new LinkedHashMap<>(16, 0.75f, true); // access-order = LRU!
// Insertion-order by default; access-order=true gives LRU behavior
```

## Queue / PriorityQueue

```java
Queue<Integer> pq = new PriorityQueue<>();                  // min-heap, O(log n) insert/remove
Queue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());
Queue<Integer> pq2 = new PriorityQueue<>(
    (a, b) -> a[0] - b[0]                                    // custom comparator
);

pq.offer(3);   // insert (returns false on failure); add() throws
pq.peek();     // min element, O(1); poll() removes it, O(log n)
pq.poll();
pq.size();

// Best for: Top-K, Dijkstra, merge K lists, scheduling
```

## equals(), hashCode(), and compareTo() — the contract

```java
public class Point {
    private final int x, y;

    public Point(int x, int y) { this.x = x; this.y = y; }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Point p)) return false;   // pattern matching (Java 16+)
        return x == p.x && y == p.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
```

**The rules (violating them breaks HashMap/HashSet silently):**
1. `equals` reflexive, symmetric, transitive, consistent; `equals(null)` is `false`
2. **Equal objects MUST have equal hash codes** — the reverse is not required
3. `hashCode` must be consistent within an execution (unless fields used in `equals` change)
4. `compareTo` should be consistent with `equals` for `TreeSet`/`TreeMap` (a sorted set uses `compareTo == 0` for uniqueness!)
5. Never use mutable fields as HashMap keys while they're in the map

## Complexity Cheat Sheet

| Structure | Access | Insert | Delete | Search | Ordered |
| --------- | ------ | ------ | ------ | ------ | ------- |
| `ArrayList` | O(1) | O(n)* | O(n) | O(n) | yes |
| `LinkedList` | O(n) | O(1)** | O(1)** | O(n) | yes |
| `ArrayDeque` | O(1) ends | O(1) ends | O(1) ends | O(n) | FIFO/LIFO |
| `HashMap` | — | O(1) | O(1) | O(1) get | no |
| `TreeMap` | — | O(log n) | O(log n) | O(log n) | sorted |
| `HashSet` | — | O(1) | O(1) | O(1) | no |
| `TreeSet` | — | O(log n) | O(log n) | O(log n) | sorted |
| `PriorityQueue` | peek O(1) | O(log n) | O(log n) | O(n) | heap order |

\* amortized O(1) at the end · \*\* with a known node/iterator

## Utilities & Iteration

```java
Collections.sort(list);                          // natural order
Collections.sort(list, Comparator.comparingInt(p -> p.x));
Collections.reverse(list);
Collections.swap(list, 0, 1);
Collections.unmodifiableList(list);              // read-only view
Collections.binarySearch(sortedList, key);       // requires sorted input
Collections.frequency(list, x);
Collections.max(list);

// Modern comparators
list.sort(Comparator.comparing(Person::getAge)
                   .thenComparing(Person::getName)
                   .reversed());

// Arrays
int[] arr = Arrays.stream(nums).sorted().toArray();
Arrays.sort(arr);                    // primitives: dual-pivot quicksort, O(n log n)
Arrays.sort(arr, 0, k);              // partial sort range
Arrays.binarySearch(arr, key);
Arrays.fill(arr, -1);
List<Integer> boxed = Arrays.asList(1, 2, 3);  // fixed-size view!
List<Integer> copy = new ArrayList<>(Arrays.asList(1, 2, 3));
int[] fromList = list.stream().mapToInt(Integer::intValue).toArray();
```

**Fail-fast:** iterators on `HashMap`/`ArrayList` throw `ConcurrentModificationException` if the collection is structurally modified during iteration (except via `iterator.remove()`).

## C++ → Java Quick Translation

| C++ | Java |
| --- | ---- |
| `std::vector` | `ArrayList` |
| `std::unordered_map` | `HashMap` |
| `std::map` | `TreeMap` |
| `std::set` / `unordered_set` | `TreeSet` / `HashSet` |
| `std::priority_queue` | `PriorityQueue` (mind min/max default!) |
| `std::deque` / `std::stack` | `ArrayDeque` |
| `std::sort` | `Arrays.sort` / `List.sort` |
| `lower_bound` / `upper_bound` | `TreeMap.floorKey/ceilingKey`, `TreeSet.headSet/tailSet` |
| `std::pair` | `Map.Entry`, custom record, or `int[]` |

## Gotchas
- `PriorityQueue` is a **min-heap** in Java (C++ `priority_queue` is a max-heap!)
- `List.remove(int)` removes by index; `List.remove(Object)` by value — autoboxing decides which
- `Integer` comparison: `a == b` fails above 127 (Integer cache −128..127) — use `equals` or `intValue()`
- `HashMap` allows one `null` key and many `null` values; `Hashtable`/`TreeMap`/`ConcurrentHashMap` don't allow null keys
- `Arrays.asList` returns a fixed-size list; `List.of` returns an immutable list (no `add`/`set`)
