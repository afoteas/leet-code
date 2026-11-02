class Solution {
    int gcd(int a, int b) {
    if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    public int findGCD(int[] nums) {
        int max = nums[0];
        int min = nums[0];

        for (int n : nums) {
        if (n > max) {
            max = n;
        }
        if (n < min) {
            min = n;
        }
        }
        return gcd(min,max);
    }
}