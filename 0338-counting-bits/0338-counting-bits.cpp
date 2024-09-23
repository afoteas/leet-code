class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> re = vector(n+1,0);
        int i = 0;
        for(auto& v:re) {
            int tmp = i;
            while (tmp > 0) {
                v += tmp & 1;
                tmp>>=1;
            }
            i++;
        }
        return re;
    }
};