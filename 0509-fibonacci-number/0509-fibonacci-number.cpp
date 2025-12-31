class Solution {
public:
    int fibr(int n) {
        if (n < 2) {
            return n;
        } else {
            return fibr(n-2) + fibr(n-1);
        }
    }

    int fib(int n) {
        int pre=0;
        int ret=1;
        if (n < 2) {
            return n;
        }
        for(int i=2 ; i <=n ; i++){
            int temp = ret;
            ret = ret + pre;
            pre = temp;
        }
        return ret;

    }
};