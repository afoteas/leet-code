# Java Concurrency & Multithreading

## Overview
Java builds concurrency into the language: `synchronized`, `volatile`, and the Java Memory Model (JMM) define visibility and ordering guarantees. Senior interviews expect the happens-before rules, the `java.util.concurrent` toolkit, and classic concurrency bugs (race conditions, deadlock, visibility).

## Creating Threads

```java
// 1. Runnable + Thread (legacy)
Thread t = new Thread(() -> System.out.println("hello"));
t.start();               // start() spawns a new thread; run() executes on the current one!

// 2. ExecutorService (preferred — thread pools)
ExecutorService pool = Executors.newFixedThreadPool(4);
Future<Integer> f = pool.submit(() -> compute());
int result = f.get();    // blocks; throws ExecutionException
pool.shutdown();         // or shutdownNow()

// 3. Callable (returns a value, can throw)
Callable<Integer> task = () -> compute();
```

**Why pools:** thread creation/teardown is expensive; pools bound resource usage and reuse threads.

## The Race Condition (why we need synchronization)

```java
class Counter {
    private int count = 0;

    // NOT thread-safe: read-modify-write is not atomic
    public void increment() { count++; }

    // Thread-safe option A: synchronized (intrinsic lock)
    public synchronized void incrementSafe() { count++; }

    // Thread-safe option B: AtomicInteger (lock-free CAS)
    private final AtomicInteger atomicCount = new AtomicInteger();
    public void incrementAtomic() { atomicCount.incrementAndGet(); }
}
```

## synchronized (Intrinsic Locks)

```java
public synchronized void method() { }        // locks `this`

public void block() {
    synchronized (this) { }                   // locks `this`
    synchronized (SomeClass.class) { }        // locks the Class object (static sections)
}

// Each object has ONE monitor; reentrant (same thread can re-acquire)
```

- Guarantees **both** mutual exclusion and **visibility** (release/acquire semantics)
- Wait/notify: `obj.wait()` / `obj.notify()` / `obj.notifyAll()` — must hold the object's monitor, always in a `while` loop (spurious wakeups)
- Interview answer: "Intrinsic locks are heavyweight before biased/lock-elision optimizations; `java.util.concurrent` gives finer control."

## volatile (Visibility, NOT Atomicity)

```java
private volatile boolean running = true;      // flag idiom — correct use

// volatile guarantees:
// 1. Visibility: writes flush to main memory, reads come from main memory
// 2. Ordering: establishes happens-before (no reordering across it)
// 3. NOT atomicity: volatile int x; x++ is STILL a race condition!
```

| | mutual exclusion | visibility | atomic read/write |
| --- | --- | --- | --- |
| `synchronized` | ✓ | ✓ | ✓ |
| `volatile` | ✗ | ✓ | ✓ (single access) |
| neither | ✗ | ✗ | ✗ |

## Java Memory Model — Happens-Before (the key rules)

A write **happens-before** a read → the read sees the write. Established by:
1. **Program order:** earlier actions in the same thread happen-before later ones
2. **Monitor unlock → subsequent lock** of the same monitor
3. **volatile write → subsequent volatile read** of the same field
4. **Thread start:** actions before `t.start()` happen-before the thread's actions
5. **Thread join:** thread's actions happen-before `join()` returns
6. **Final fields:** safely published `final` fields are visible without extra sync
7. **Transitivity:** if A hb B and B hb C, then A hb C

Sound bite: "Without a happens-before edge, the compiler, cache, and CPU are free to reorder or hide writes — that's a data race."

## java.util.concurrent Toolkit

### Synchronizers
```java
// CountDownLatch — wait for N events
CountDownLatch latch = new CountDownLatch(3);
latch.countDown();          // in workers
latch.await();              // in coordinator

// Semaphore — limit concurrent access (e.g., connection pool)
Semaphore sem = new Semaphore(5);
sem.acquire();
try { ... } finally { sem.release(); }

// CyclicBarrier — reusable meeting point
CyclicBarrier barrier = new CyclicBarrier(3, () -> System.out.println("round done"));
barrier.await();

// Phaser — dynamic registration (advanced)
```

### Locks (explicit, more flexible than synchronized)
```java
Lock lock = new ReentrantLock();
lock.lock();
try { ... } finally { lock.unlock(); }   // MUST unlock in finally

// Extras over synchronized: tryLock(), lockInterruptibly(), fairness, multiple Condition objects
Condition notFull = lock.newCondition();
notFull.await();
notFull.signal();
```

### Concurrent Collections
```java
ConcurrentHashMap<String, Integer> chm = new ConcurrentHashMap<>();
chm.put(k, v);                              // fine-grained locking / CAS
chm.computeIfAbsent(k, key -> expensive()); // atomic
chm.merge(k, 1, Integer::sum);              // atomic frequency counting

BlockingQueue<Integer> bq = new LinkedBlockingQueue<>(100);
bq.put(1);      // blocks when full
bq.take();      // blocks when empty     → producer/consumer pattern

CopyOnWriteArrayList<Listener> listeners = new CopyOnWriteArrayList<>(); // read-heavy
ConcurrentLinkedQueue<Integer> clq = new ConcurrentLinkedQueue<>();     // non-blocking
```

### Atomic Variables (CAS — compare-and-swap)
```java
AtomicInteger ai = new AtomicInteger(0);
ai.incrementAndGet();          // lock-free on x86 (LOCK XADD)
ai.compareAndSet(5, 10);       // CAS loop: expected, new

// CAS pitfall: ABA problem → AtomicReference with version stamps (AtomicStampedReference)
```

## The Classic Bug Zoo

```java
// DEADLOCK: circular lock ordering
// Thread1: synchronized(a) { synchronized(b) { } }
// Thread2: synchronized(b) { synchronized(a) { } }   ← deadlock
// Prevention: consistent global lock ordering, lock timeout via tryLock()

// LIVELOCK: threads keep reacting to each other (two polite people stepping aside forever)
// STARVATION: a thread never gets the lock (unfair scheduling / heavy contention)

// DOUBLE-CHECKED LOCKING — broken without volatile (pre-Java 5)
class Broken {
    private static Broken instance;
    static Broken get() {
        if (instance == null) {                    // 1st check (no lock)
            synchronized (Broken.class) {
                if (instance == null)              // 2nd check
                    instance = new Broken();       // may publish partially-constructed object!
            }
        }
        return instance;
    }
}
// Fix: make `instance` volatile, or use enum/holder-class idiom:
class Holder {                                   // lazy + thread-safe, no locks
    private static class Lazy { static final Holder I = new Holder(); }
    static Holder get() { return Lazy.I; }
}
```

## CompletableFuture (Modern Async Pipelines)

```java
CompletableFuture.supplyAsync(() -> fetchUser(id))
    .thenApply(user -> user.name())              // transform
    .thenCombine(fetchOther(id), (a, b) -> a + b)
    .thenAccept(this::save)                      // consumer
    .exceptionally(ex -> fallback())
    .join();                                     // or get()
```

## Thread Lifecycle & Interruption

```
NEW → RUNNABLE ⇄ WAITING / TIMED_WAITING / BLOCKED → TERMINATED
```

```java
Thread t = new Thread(() -> {
    while (!Thread.currentThread().isInterrupted()) {
        try {
            doWork();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();   // restore the flag!
            break;
        }
    }
});
```

**Rules:** interrupt is cooperative; never swallow `InterruptedException` without restoring the flag; prefer `ExecutorService` over raw threads.

## Interview Checklist
- [ ] Race condition: read-modify-write is not atomic (`x++`)
- [ ] `synchronized` vs `volatile` (mutual exclusion vs visibility)
- [ ] Happens-before: which actions establish ordering edges
- [ ] Deadlock conditions (mutual exclusion, hold-and-wait, no preemption, circular wait) + prevention
- [ ] `ConcurrentHashMap`, `BlockingQueue`, `CountDownLatch`, `Semaphore`, `AtomicInteger`
- [ ] Producer/consumer with `BlockingQueue` — write it fluently
- [ ] Broken double-checked locking and the volatile fix
- [ ] `CompletableFuture` chaining
