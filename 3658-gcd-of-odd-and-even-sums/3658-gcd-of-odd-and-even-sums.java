class Solution {
    public int gcd(int x, int y) { 
        return y == 0 ? x : gcd(y, x % y); 
    }

    public int gcdOfOddEvenSums(int n) {
        int odd=0;
        int even=0;
        for(int i=1; i<= 2*n; i++) {
            if((i&1) == 1) {
                odd+=i;
            } else {
                even += i;
            }
        }
        return gcd(odd,even);
    }
}