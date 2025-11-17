class Solution {
public:

    int totalMoney(int n) {
        int ret = 0;
        int step1 = 0;
        int step2 = 0;
        for (int i = 0; i<n; i++) {
            if(i%7 == 0) {
                step1++;
                step2 = step1;
            }
            ret += step2++;
        }
        return ret;
    }
};