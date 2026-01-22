// Performance Decrease: Lambda Captures Explained
// The performance decrease is likely due to lambda capture overhead. Here's why:

// The Problem
// Each time you call these lambdas in a loop, there's overhead from:

// Indirect access through the captured reference
// Function call overhead (lambdas are function objects)
// Potential compiler optimization limitations with captures
// Why Commented Code Was Faster
// The commented version was a direct member function that:

// Has direct access to parameters (no capture)
// May be inlined more easily by the compiler
// Has less abstraction layers

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        
        auto isNonDecreasing = [](const std::vector<int>& v) -> bool {
            for (size_t i = 1; i < v.size(); ++i) {
                if (v[i] < v[i - 1]) return false;
            }
            return true;
        };

        auto mergeOne = [](std::vector<int>& v) -> void {
            size_t pos = 0;
            int minSum = std::numeric_limits<int>::max();
            for (size_t i = 1; i < v.size(); ++i) {
                int s = v[i] + v[i - 1];
                if (s < minSum) { minSum = s; pos = i; }
            }
            v[pos - 1] = minSum;
            v.erase(v.begin() + pos);
        };

        while (!isNonDecreasing(nums)) {
            mergeOne(nums);
            ++ans;
        }
        return ans;
        
    }
};