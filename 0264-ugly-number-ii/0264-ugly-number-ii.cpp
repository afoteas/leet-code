class Solution {
public:

    int nthUglyNumberDp(int n) {
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

    int nthUglyNumber(int n)
    {
        // Base cases...
        if (n == 1 or n == 2 or n == 3 or n == 4 or n == 5)
            return n;
    
        set<long long int> s;
        s.insert(1);
        n--;
    
        while (n) {
            auto it = s.begin();
    
            // Get the beginning element of the set
            long long int x = *it;
    
            // Deleting the ith element
            s.erase(it);
    
            // Inserting all the other options
            s.insert(x * 2);
            s.insert(x * 3);
            s.insert(x * 5);
            n--;
        }
    
        // The top of the set represents the nth ugly number
        return *s.begin();
    }
 

};