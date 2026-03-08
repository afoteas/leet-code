class Solution {
public:
    int bitCount(int num) {
        int ret = 0;
        while(num) {
            if(num&1) ret++;
            num>>=1;
        }
        return ret;
    }

    int countPrimeSetBits(int left, int right) {
        array<int, 8> primes {2, 3, 5, 7, 11, 13, 17, 19};
        int ret = 0;

        for(int i=left; i<= right; i++) {
            int bits = bitCount(i);
            if (find(primes.begin(), primes.end(), bits) != primes.end()) {
                ret++;
            }

        }
        return ret;
    }
};