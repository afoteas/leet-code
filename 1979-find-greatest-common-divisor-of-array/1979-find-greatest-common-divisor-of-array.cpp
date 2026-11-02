class Solution {
public:
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());
        return gcd(m,M);
        
    }
};