class Solution {
public:
    int findComplement(int num) {
        unsigned temp = num;
        unsigned numberBits = 0;
        while (temp > 0) {
            ++numberBits;
            temp>>=1;
        }
        unsigned mask = (1u<<numberBits) - 1;
        return num ^ mask;
    }
};