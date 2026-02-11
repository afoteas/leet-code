# Multithreading

## Overview
Concurrent execution using threads to achieve **parallelism** and better CPU utilization.

### Why Multithreading?

**Single Thread**:
```
Task A ───────> Task B ───────> Task C
Time: 3 seconds
```

**Multiple Threads** (with multi-core CPU):
```
Thread 1: Task A ─────>
Thread 2:      Task B ─────>
Thread 3:           Task C ─────>
Time: 1 second (3x speedup!)
```

### Key Concepts

**Concurrency**: Tasks make progress in overlapping time periods (can be on single core)
**Parallelism**: Tasks execute simultaneously (requires multiple cores)

```
Concurrency (1 core):        Parallelism (2 cores):
  Time ────>                   Time ────>
  [A][B][A][B][A]              Core 1: [A][A][A]
                               Core 2: [B][B][B]
```

### The Challenge: Shared State

Multiple threads accessing shared data = **Race Conditions**

```cpp
// DANGER: Race condition!
int counter = 0;  // Shared between threads

void increment() {
    counter++;  // NOT atomic! Actually 3 operations:
                // 1. Read counter
                // 2. Add 1
                // 3. Write back
}

// Thread 1 and Thread 2 both call increment()
// Expected: counter = 2
// Actual: counter might be 1! (lost update)

Timeline:
Thread 1: Read(0)  Add(1)         Write(1)
Thread 2:      Read(0)  Add(1)  Write(1)
                       ↑
                   Both read 0!
```

## Basic Thread Creation

### Creating and Managing Threads

```cpp
#include <thread>
#include <iostream>

void threadFunction(int id) {
    cout << "Thread " << id << " running\n";
}

int main() {
    // Create thread
    thread t1(threadFunction, 1);
    thread t2(threadFunction, 2);
    
    // CRITICAL: Must join or detach!
    t1.join();   // Wait for t1 to finish
    t2.join();   // Wait for t2 to finish
    
    cout << "All threads finished\n";
    return 0;
}
```

### join() vs detach()

```cpp
// join() - Wait for thread to finish
thread t(task);
t.join();  // Blocks until t finishes
// Now safe to exit

// detach() - Let thread run independently
thread t(task);
t.detach();  // Thread runs in background
// WARNING: Must ensure resources remain valid!
```

**Common Mistake**: Forgetting to join/detach
```cpp
// WRONG - Destructor called on joinable thread!
void bad() {
    thread t(task);
    // t goes out of scope without join/detach
}  // Calls std::terminate()! 💥

// CORRECT
void good() {
    thread t(task);
    t.join();  // or t.detach()
}  // Safe
```

### Passing Arguments

```cpp
void process(int x, const string& str) {
    cout << x << ": " << str << endl;
}

int main() {
    int value = 42;
    string text = "hello";
    
    // Arguments passed by value/reference
    thread t(process, value, ref(text));
    //                       ↑
    //                  Use ref() for references
    
    t.join();
}
```

## Mutex (Mutual Exclusion)

### The Problem: Race Conditions

```cpp
// WITHOUT mutex - BROKEN!
int counter = 0;

void increment(int times) {
    for (int i = 0; i < times; i++) {
        counter++;  // Race condition!
    }
}

int main() {
    thread t1(increment, 1000);
    thread t2(increment, 1000);
    t1.join(); t2.join();
    
    cout << counter << endl;  // Expected: 2000
                               // Actual: ~1500 (varies!)
}
```

### The Solution: Mutex

```cpp
#include <mutex>

mutex mtx;  // The lock
int counter = 0;

void increment(int times) {
    for (int i = 0; i < times; i++) {
        mtx.lock();      // Acquire lock
        counter++;       // Critical section (protected)
        mtx.unlock();    // Release lock
    }
}
// Now counter will be exactly 2000! ✓
```

### RAII-Style Locking (Preferred)

**Problem with manual lock/unlock**: If exception thrown, unlock() not called!

```cpp
// DANGEROUS - Not exception-safe
void bad() {
    mtx.lock();
    riskyOperation();  // Might throw!
    mtx.unlock();      // Never reached! Deadlock!
}

// SAFE - Use lock_guard (RAII)
void good() {
    lock_guard<mutex> lock(mtx);  // Locks in constructor
    riskyOperation();              // If exception thrown...
}  // lock_guard destructor unlocks automatically! ✓
```

### Lock Types

```cpp
// lock_guard - Simple, can't unlock early
{
    lock_guard<mutex> lock(mtx);
    // ... critical section ...
}  // Unlocks here, can't unlock earlier

// unique_lock - Flexible, can unlock/relock
{
    unique_lock<mutex> lock(mtx);
    // ... do work ...
    lock.unlock();  // Unlock early if needed
    // ... non-critical work ...
    lock.lock();    // Relock if needed
}  // Unlocks if still locked

// scoped_lock - Lock multiple mutexes (C++17)
{
    scoped_lock lock(mtx1, mtx2, mtx3);  // Deadlock-free!
    // All locked
}  // All unlocked
```

### Visual: How Mutex Works

```
Shared Resource: counter

Thread 1                Thread 2
   |                       |
   | lock(mtx)             |
   | ✓ Acquired            |
   | counter++             | lock(mtx)
   | counter++             | ⏳ Waiting...
   | unlock(mtx)           | ⏳ Waiting...
   |                       | ✓ Acquired
   |                       | counter++
   |                       | unlock(mtx)
   |                       |
```

## Condition Variables

### The Problem: Busy Waiting

```cpp
// WRONG - Wastes CPU!
bool ready = false;
mutex mtx;

void worker() {
    while (true) {
        mtx.lock();
        if (ready) {  // Constantly checking!
            mtx.unlock();
            break;
        }
        mtx.unlock();
        // CPU cycles wasted in this loop!
    }
    doWork();
}
```

### The Solution: Condition Variables

**Condition variable** = Efficient waiting mechanism

```cpp
#include <condition_variable>

mutex mtx;
condition_variable cv;
bool ready = false;

void worker() {
    unique_lock<mutex> lock(mtx);
    
    // Wait until ready is true
    cv.wait(lock, []{ return ready; });
    //          ↑        ↑
    //        lock    predicate
    
    // When we get here:
    // 1. ready == true
    // 2. lock is held
    
    doWork();
}

void signaler() {
    {
        lock_guard<mutex> lock(mtx);
        ready = true;  // Change the condition
    }  // Release lock BEFORE notify
    
    cv.notify_one();   // Wake up one waiting thread
    // or cv.notify_all();  // Wake up all waiting threads
}
```

### How cv.wait() Works

```
Step 1: cv.wait(lock, predicate)
        ↓
Step 2: Check predicate
        If false:
            - Unlock mutex (atomically!)
            - Put thread to sleep
            - Wait for notification...
        
Step 3: Notification arrives!
        - Wake up
        - Relock mutex (atomically!)
        - Check predicate again
        
Step 4: If predicate true:
            - Return (lock still held)
        Else:
            - Go back to sleep (spurious wakeup protection)
```

### Why Predicate is Critical

```cpp
// WRONG - No predicate!
cv.wait(lock);  // Spurious wakeups!

// CORRECT - With predicate
cv.wait(lock, []{ return ready; });

// What is a spurious wakeup?
// Thread wakes up even though condition not met!
// Predicate protects against this.
```

## Atomics

### Lock-Free Synchronization

For simple operations, **atomics** are faster than mutexes.

```cpp
#include <atomic>

// Atomic operations - No mutex needed!
atomic<int> counter(0);

void increment() {
    counter++;  // Atomic! Thread-safe!
    // Equivalent to: counter.fetch_add(1, memory_order_seq_cst)
}

int main() {
    thread t1(increment);
    thread t2(increment);
    t1.join(); t2.join();
    
    cout << counter << endl;  // Always correct!
}
```

### Atomic Operations

```cpp
atomic<int> x(0);

// Read/Write
int val = x.load();        // Atomic read
x.store(42);               // Atomic write

// Read-Modify-Write
int old = x.fetch_add(5);  // old = x; x += 5; (atomic)
int old = x.fetch_sub(3);  // old = x; x -= 3; (atomic)
int old = x.exchange(10);  // old = x; x = 10; (atomic)

// Compare-And-Swap (CAS)
int expected = 5;
int desired = 10;
bool success = x.compare_exchange_strong(expected, desired);
// If x == expected: x = desired, return true
// Else: expected = x, return false
```

### Atomic vs Mutex: When to Use What

```cpp
// Use ATOMIC when:
// ✓ Single variable
// ✓ Simple operations (++, --, load, store)
// ✓ Performance critical
atomic<int> counter(0);
counter++;  // Fast!

// Use MUTEX when:
// ✓ Multiple variables
// ✓ Complex operations
// ✓ Need to protect multiple statements
mutex mtx;
int balance = 100;
vector<int> transactions;

{
    lock_guard<mutex> lock(mtx);
    balance -= 50;              // Multiple
    transactions.push_back(50); // operations
}  // Must be atomic together!
```

### Memory Ordering (Advanced)

```cpp
// Default: memory_order_seq_cst (sequential consistency)
// Safest but slowest
counter.fetch_add(1);  // Same as:
counter.fetch_add(1, memory_order_seq_cst);

// Relaxed: No ordering guarantees (fastest)
counter.fetch_add(1, memory_order_relaxed);
// Use for counters where order doesn't matter

// Acquire-Release: For producer-consumer
data.store(42, memory_order_release);  // Producer
int val = data.load(memory_order_acquire);  // Consumer
// Ensures writes before release are visible after acquire
```

## Common Patterns

### Pattern 1: Producer-Consumer (Detailed)

**Problem**: Producers generate data, consumers process it.

```cpp
#include <queue>
#include <mutex>
#include <condition_variable>

queue<int> buffer;           // Shared buffer
mutex mtx;                   // Protects buffer
condition_variable cv_full;  // Signals: buffer has data
const int MAX_SIZE = 10;

void producer(int id) {
    for (int i = 0; i < 20; i++) {
        int item = id * 100 + i;
        
        {
            unique_lock<mutex> lock(mtx);
            
            // Wait if buffer full (optional)
            // cv_full.wait(lock, []{ return buffer.size() < MAX_SIZE; });
            
            buffer.push(item);
            cout << "Producer " << id << " produced: " << item << endl;
        }  // Release lock before notify!
        
        cv_full.notify_one();  // Wake one consumer
        
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(int id) {
    while (true) {
        int item;
        
        {
            unique_lock<mutex> lock(mtx);
            
            // Wait until buffer has data
            cv_full.wait(lock, []{ return !buffer.empty(); });
            
            item = buffer.front();
            buffer.pop();
            
            cout << "Consumer " << id << " consumed: " << item << endl;
        }  // Release lock
        
        // Process item (outside critical section!)
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() {
    thread p1(producer, 1);
    thread p2(producer, 2);
    thread c1(consumer, 1);
    thread c2(consumer, 2);
    
    p1.join(); p2.join();
    // Consumers run forever, would need termination signal in real code
}
```

### Pattern 2: Reader-Writer Lock

**Problem**: Multiple readers OK, but writers need exclusive access.

```cpp
#include <shared_mutex>  // C++17

shared_mutex rw_mtx;
int shared_data = 0;

void reader(int id) {
    // Multiple readers can hold shared lock simultaneously
    shared_lock<shared_mutex> lock(rw_mtx);
    cout << "Reader " << id << " reads: " << shared_data << endl;
}  // All readers can read in parallel!

void writer(int id, int value) {
    // Writer needs exclusive lock
    unique_lock<shared_mutex> lock(rw_mtx);
    shared_data = value;  // Exclusive access
    cout << "Writer " << id << " wrote: " << value << endl;
}  // Only one writer at a time, blocks all readers
```

### Pattern 3: Thread Pool (Simplified)

```cpp
class ThreadPool {
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop = false;
    
public:
    ThreadPool(int num_threads) {
        for (int i = 0; i < num_threads; i++) {
            workers.emplace_back([this] {
                while (true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this]{ return stop || !tasks.empty(); });
                        
                        if (stop && tasks.empty()) return;
                        
                        task = move(tasks.front());
                        tasks.pop();
                    }
                    task();  // Execute outside lock!
                }
            });
        }
    }
    
    void enqueue(function<void()> task) {
        {
            lock_guard<mutex> lock(mtx);
            tasks.push(move(task));
        }
        cv.notify_one();
    }
    
    ~ThreadPool() {
        {
            lock_guard<mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (thread& t : workers) t.join();
    }
};
```

## Common Issues & Solutions

### Issue 1: Race Condition

**Problem**: Unsynchronized access to shared data

```cpp
// WRONG
int balance = 100;

void withdraw(int amount) {
    if (balance >= amount) {  // Check
        // Another thread might run here!
        balance -= amount;     // Use
    }
}
// Two threads withdrawing $60 each from $100 balance
// Both pass check! Balance becomes -$20! 💥

// CORRECT
mutex mtx;
void withdraw(int amount) {
    lock_guard<mutex> lock(mtx);
    if (balance >= amount) {
        balance -= amount;  // Atomic check-and-use
    }
}
```

### Issue 2: Deadlock

**Problem**: Circular wait for locks

```cpp
mutex mtx1, mtx2;

// Thread 1
void transfer1() {
    lock_guard<mutex> lock1(mtx1);  // Lock A
    this_thread::sleep_for(chrono::milliseconds(1));
    lock_guard<mutex> lock2(mtx2);  // Wait for B
    // Transfer...
}

// Thread 2  
void transfer2() {
    lock_guard<mutex> lock2(mtx2);  // Lock B
    this_thread::sleep_for(chrono::milliseconds(1));
    lock_guard<mutex> lock1(mtx1);  // Wait for A
    // Transfer...
}
// DEADLOCK! Thread 1 has A, waits for B
//           Thread 2 has B, waits for A
```

**Solution 1**: Lock in same order
```cpp
// Both threads lock in same order
void transfer1() {
    lock_guard<mutex> lock1(mtx1);  // Always mtx1 first
    lock_guard<mutex> lock2(mtx2);  // Then mtx2
}

void transfer2() {
    lock_guard<mutex> lock1(mtx1);  // Same order!
    lock_guard<mutex> lock2(mtx2);
}
```

**Solution 2**: Lock all at once (C++17)
```cpp
void transfer() {
    scoped_lock lock(mtx1, mtx2);  // Deadlock-free!
    // Uses deadlock avoidance algorithm
}
```

### Issue 3: Livelock

**Problem**: Threads keep changing state but make no progress

```cpp
// Two polite people in a hallway, both stepping aside
// Both keep moving but neither passes!
void politePass() {
    while (other_thread_in_way) {
        step_aside();  // Keep yielding
        // But other thread also yielding!
    }
}

// Solution: Add randomness or priority
void smartPass() {
    while (other_thread_in_way) {
        wait_random_time();  // Break symmetry
    }
}
```

### Issue 4: Starvation

**Problem**: Thread never gets resources

```cpp
// Writer keeps acquiring lock, readers starve
mutex mtx;

void writer() {
    while (true) {
        lock_guard<mutex> lock(mtx);
        write();  // Constantly writing
        // Readers never get a chance!
    }
}

// Solution: Use fair scheduling or reader-writer locks
shared_mutex rw_mtx;  // Readers get fair access
```

### Issue 5: Forgetting to Unlock

```cpp
// WRONG - Exception leaves mutex locked!
void bad() {
    mtx.lock();
    mayThrow();  // Exception!
    mtx.unlock();  // Never reached!
}

// CORRECT - RAII handles it
void good() {
    lock_guard<mutex> lock(mtx);
    mayThrow();  // Exception thrown
}  // Destructor unlocks! ✓
```

## Thread Safety Guidelines

### Do's ✓

1. **Use RAII for locks**
   ```cpp
   lock_guard<mutex> lock(mtx);  // Auto-unlocks
   ```

2. **Minimize critical sections**
   ```cpp
   // WRONG - Entire function locked
   void process() {
       lock_guard<mutex> lock(mtx);
       expensiveComputation();  // Doesn't need lock!
       shared_data++;           // Needs lock
   }
   
   // CORRECT - Lock only what's needed
   void process() {
       expensiveComputation();  // Outside lock
       {
           lock_guard<mutex> lock(mtx);
           shared_data++;  // Only this locked
       }
   }
   ```

3. **Prefer atomics for simple counters**
   ```cpp
   atomic<int> counter(0);  // Better than mutex for simple int
   ```

4. **Always use predicates with cv.wait()**
   ```cpp
   cv.wait(lock, []{ return ready; });  // Protects against spurious wakeups
   ```

5. **Lock in consistent order**
   ```cpp
   // Always lock lower address first
   if (&mtx1 < &mtx2) {
       lock_guard<mutex> lock1(mtx1);
       lock_guard<mutex> lock2(mtx2);
   } else {
       lock_guard<mutex> lock2(mtx2);
       lock_guard<mutex> lock1(mtx1);
   }
   ```

### Don'ts ✗

1. **Don't use manual lock/unlock**
   ```cpp
   mtx.lock();    // ✗ Error-prone
   mtx.unlock();
   ```

2. **Don't hold locks unnecessarily**
   ```cpp
   lock_guard<mutex> lock(mtx);
   doWork();  // If this doesn't need lock, move outside!
   ```

3. **Don't access shared data without synchronization**
   ```cpp
   // Even reads need protection!
   int val = shared_counter;  // ✗ Race condition
   ```

4. **Don't call unknown code while holding lock**
   ```cpp
   lock_guard<mutex> lock(mtx);
   callback();  // ✗ Callback might acquire other locks → deadlock
   ```

5. **Don't forget to join/detach threads**
   ```cpp
   thread t(task);
   // ✗ Forgot t.join() or t.detach()
   // Destructor calls terminate()!
   ```

## Practice Problems

### Level 1: Basics
1. Implement thread-safe counter class
2. Fix race condition in bank account
3. Create producer-consumer with bounded buffer

### Level 2: Synchronization
4. **Print in Order** (LeetCode #1114) - Condition variables
5. **Print FooBar Alternately** (LeetCode #1115) - Thread coordination
6. **Building H2O** (LeetCode #1117) - Barrier synchronization

### Level 3: Advanced
7. **Dining Philosophers** - Deadlock avoidance
8. **Web Crawler Multithreaded** (LeetCode #1242) - Thread pool
9. Implement reader-writer lock from scratch
10. Implement lock-free stack using atomics

## Quick Reference

### Thread Creation
```cpp
thread t(function, arg1, arg2);  // Create
t.join();   // Wait for completion
t.detach(); // Run independently
```

### Mutex
```cpp
mutex mtx;
lock_guard<mutex> lock(mtx);      // RAII, simple
unique_lock<mutex> lock(mtx);     // RAII, flexible
scoped_lock lock(mtx1, mtx2);     // Multiple locks
```

### Condition Variable
```cpp
condition_variable cv;
cv.wait(lock, []{ return ready; });  // Wait
cv.notify_one();   // Wake one
cv.notify_all();   // Wake all
```

### Atomics
```cpp
atomic<int> x(0);
x.load();           // Read
x.store(5);         // Write
x.fetch_add(1);     // Atomic +=
x.exchange(10);     // Swap
```

### Reader-Writer Lock (C++17)
```cpp
shared_mutex mtx;
shared_lock<shared_mutex> r_lock(mtx);  // Reader
unique_lock<shared_mutex> w_lock(mtx);  // Writer
```

## Performance Comparison

| Mechanism | Overhead | Use Case |
|-----------|----------|----------|
| No synchronization | None | Read-only data |
| Atomic | Very low | Simple counters, flags |
| Mutex | Low-Medium | General synchronization |
| Reader-Writer Lock | Medium | Many readers, few writers |
| Condition Variable | Medium | Event waiting |

## Common C++ Threading Headers

```cpp
#include <thread>              // thread
#include <mutex>               // mutex, lock_guard, unique_lock
#include <shared_mutex>        // shared_mutex (C++17)
#include <condition_variable>  // condition_variable
#include <atomic>              // atomic<T>
#include <future>              // async, future, promise
```

[← Back to README](README.md)
