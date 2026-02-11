# RAII (Resource Acquisition Is Initialization)

## Overview
C++ programming idiom: resource lifetime is tied to object lifetime.

## Core Principle
```cpp
class FileHandle {
private:
    FILE* file;
    
public:
    FileHandle(const char* filename) {
        file = fopen(filename, "r");
        if (!file) throw runtime_error("Cannot open file");
    }
    
    ~FileHandle() {
        if (file) {
            fclose(file);  // Automatic cleanup
        }
    }
    
    // Disable copying
    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;
};

// Usage
void processFile() {
    FileHandle fh("data.txt");
    // Use file
    // File automatically closed when fh goes out of scope
}
```

## Examples

### Lock Guard
```cpp
#include <mutex>

mutex mtx;

void threadSafe() {
    lock_guard<mutex> lock(mtx);
    // Critical section
    // Mutex automatically unlocked at end of scope
}
```

### Unique Lock
```cpp
void example() {
    unique_lock<mutex> lock(mtx);
    // Can unlock/lock manually
    lock.unlock();
    // Do non-critical work
    lock.lock();
}
```

### Custom RAII Wrapper
```cpp
class Timer {
private:
    chrono::time_point<chrono::high_resolution_clock> start;
    
public:
    Timer() : start(chrono::high_resolution_clock::now()) {}
    
    ~Timer() {
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Elapsed: " << duration.count() << "ms\n";
    }
};

// Usage
void benchmark() {
    Timer t;  // Starts timer
    // Do work
    // Time automatically printed when t goes out of scope
}
```

## Benefits
- ✅ No resource leaks
- ✅ Exception-safe
- ✅ Automatic cleanup
- ✅ Clear ownership semantics

## Common RAII Classes
- Smart pointers (`unique_ptr`, `shared_ptr`)
- `lock_guard`, `unique_lock`
- File streams (`ifstream`, `ofstream`)
- Containers (`vector`, `string`)

[← Back to README](README.md)
