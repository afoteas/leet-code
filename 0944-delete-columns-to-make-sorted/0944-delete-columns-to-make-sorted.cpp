class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strlen = strs[0].size();
        int veclen = strs.size();
        int ret = 0;

        for(int i=0; i < strlen; i++) {
            for (int j = 1; j < veclen; j++) {
                if (strs[j-1][i] > strs[j][i]) {
                    ret++;
                    break;
                }
            }
        }

        return ret;
    }
};