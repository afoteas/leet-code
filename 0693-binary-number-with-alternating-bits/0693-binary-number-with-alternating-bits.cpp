class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool pre = (n & 1);
        n >>= 1;
        while(n) {
            if (pre == (n&1)) return false;
            pre = (n&1);
            n >>=1;
        }
        return true;
    }
};