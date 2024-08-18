class Solution {
public:

    int nthUglyNumber(int n) {
        unsigned ugly[n]; 
        unsigned i2 = 0, i3 = 0, i5 = 0;
        unsigned next_multiple_of_2 = 2;
        unsigned next_multiple_of_3 = 3;
        unsigned next_multiple_of_5 = 5;
        unsigned next_ugly_no = 1;
    
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            next_ugly_no = min(
                next_multiple_of_2,
                min(next_multiple_of_3, next_multiple_of_5));
            ugly[i] = next_ugly_no;
            if (next_ugly_no == next_multiple_of_2) {
                next_multiple_of_2 = ugly[++i2] * 2;
            }
            if (next_ugly_no == next_multiple_of_3) {
                next_multiple_of_3 = ugly[++i3] * 3;
            }
            if (next_ugly_no == next_multiple_of_5) {
                next_multiple_of_5 = ugly[++i5] * 5;
            }
        }  
        return next_ugly_no;
    }
};