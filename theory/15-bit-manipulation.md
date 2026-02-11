# Bit Manipulation

## Overview
Techniques using bitwise operations for efficient solutions to certain problems.

## Bitwise Operators

### Basic Operations
```cpp
int a = 5;    // 0101
int b = 3;    // 0011

int and_op = a & b;   // 0001 = 1
int or_op = a | b;    // 0111 = 7
int xor_op = a ^ b;   // 0110 = 6
int not_op = ~a;      // 1010 (two's complement)
int left = a << 1;    // 1010 = 10 (multiply by 2)
int right = a >> 1;   // 0010 = 2 (divide by 2)
```

## Common Techniques

### Check if Bit is Set
```cpp
bool isBitSet(int num, int i) {
    return (num & (1 << i)) != 0;
}
```

### Set a Bit
```cpp
int setBit(int num, int i) {
    return num | (1 << i);
}
```

### Clear a Bit
```cpp
int clearBit(int num, int i) {
    return num & ~(1 << i);
}
```

### Toggle a Bit
```cpp
int toggleBit(int num, int i) {
    return num ^ (1 << i);
}
```

### Clear Rightmost Set Bit
```cpp
int clearRightmostBit(int num) {
    return num & (num - 1);
}
```

### Get Rightmost Set Bit
```cpp
int getRightmostBit(int num) {
    return num & (-num);
}
```

### Check if Power of 2
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### Count Set Bits (Hamming Weight)
```cpp
int countBits(int n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n - 1);  // Clear rightmost bit
    }
    return count;
}

// Using built-in
int countBits(int n) {
    return __builtin_popcount(n);
}
```

## Classic Problems

### 1. Single Number (XOR Property)
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // a ^ a = 0, a ^ 0 = a
    }
    return result;
}
```

### 2. Single Number II (Appears Once, Others 3 Times)
```cpp
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    
    for (int num : nums) {
        twos |= ones & num;
        ones ^= num;
        int threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    
    return ones;
}
```

### 3. Single Number III (Two Unique Numbers)
```cpp
vector<int> singleNumber(vector<int>& nums) {
    int xor_all = 0;
    for (int num : nums) {
        xor_all ^= num;
    }
    
    // Find rightmost set bit
    int rightmost = xor_all & (-xor_all);
    
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & rightmost) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    
    return {num1, num2};
}
```

### 4. Reverse Bits
```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
```

### 5. Number of 1 Bits
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n - 1);
    }
    return count;
}
```

### 6. Counting Bits (0 to n)
```cpp
vector<int> countBits(int n) {
    vector<int> result(n + 1);
    for (int i = 1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}
```

### 7. Maximum XOR of Two Numbers
```cpp
int findMaximumXOR(vector<int>& nums) {
    int maxXOR = 0;
    int mask = 0;
    
    for (int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        
        for (int num : nums) {
            prefixes.insert(num & mask);
        }
        
        int candidate = maxXOR | (1 << i);
        for (int prefix : prefixes) {
            if (prefixes.count(prefix ^ candidate)) {
                maxXOR = candidate;
                break;
            }
        }
    }
    
    return maxXOR;
}
```

### 8. Subsets Using Bitmask
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    
    return result;
}
```

### 9. Sum of Two Integers (Without +/-)
```cpp
int getSum(int a, int b) {
    while (b != 0) {
        int carry = (unsigned)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
```

### 10. Missing Number
```cpp
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        result ^= i ^ nums[i];
    }
    return result;
}
```

## Important Properties

### XOR Properties
```cpp
a ^ a = 0
a ^ 0 = a
a ^ b = b ^ a (commutative)
a ^ b ^ c = a ^ (b ^ c) (associative)
```

### AND Properties
```cpp
n & (n - 1)  // Clears rightmost set bit
n & -n       // Isolates rightmost set bit
```

### Bit Shifting
```cpp
n << k  // Multiply by 2^k
n >> k  // Divide by 2^k (for positive n)
```

## Common Patterns

### Pattern 1: XOR for Finding Unique
Use when numbers appear in pairs except one/two

### Pattern 2: Bitmask for Sets/Subsets
Represent sets as integers (up to 32/64 elements)

### Pattern 3: Bit Counting
Count set bits for various optimization problems

### Pattern 4: Bit by Bit Construction
Build result one bit at a time

## Common Problems
- Single Number (LeetCode #136)
- Single Number II (LeetCode #137)
- Single Number III (LeetCode #260)
- Number of 1 Bits (LeetCode #191)
- Counting Bits (LeetCode #338)
- Reverse Bits (LeetCode #190)
- Power of Two (LeetCode #231)
- Missing Number (LeetCode #268)
- Maximum XOR (LeetCode #421)
- Sum of Two Integers (LeetCode #371)

## Tips
- XOR is self-inverse: `a ^ b ^ b = a`
- Use `(1 << i)` to create mask for bit i
- `n & (n-1)` removes rightmost 1-bit
- `n & -n` isolates rightmost 1-bit
- Represent subsets with integers (bitmask)
- Shift left = multiply by 2, shift right = divide by 2
- Use `unsigned` to avoid undefined behavior with negatives

## Time Complexity
Most bitwise operations are O(1) or O(32) = O(1) for 32-bit integers

[← Back to README](README.md)
