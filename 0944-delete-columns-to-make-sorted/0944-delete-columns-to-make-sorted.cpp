class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strlen = strs[0].size();
        int veclen = strs.size();
        cout << strlen << endl;
        int ret = 0;

        for(int i=0; i < strlen; i++) {
            for (int j = 0; j < veclen; j++) {
                // cout << strs[i][j] << " ";
                if (j > 0 && strs[j-1][i] > strs[j][i]) {
                    ret++;
                    break;
                }
            }
            // cout << endl;

        }

        return ret;
    }
};