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

    int countPrimeSetBitsMine(int left, int right) {
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

    int countPrimeSetBits(int L, int R) {
        int count =0,hash[20] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1};
        for(int i = L;i <= R;i++)
        {
            bitset<20> b(i);
            if(hash[b.count()])
                count++;
        }
        return count;
    }
};