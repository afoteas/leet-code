class Solution {
public:
    int hammingWeight(int n) {
        int ret=0;
        while(n>0){
            printf("n=%d\n",n);
            if(n&1) {
                ret++;
            }
            n = n >> 1;
        }
        return ret;
        
    }
};