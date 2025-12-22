class Solution {
public:
    // int minDeletionSize(vector<string>& strs) {
    //     int strlen = strs[0].size();
    //     int veclen = strs.size();
    //     int ret = 0;
    //     int i_last = -1;

    //     for(int i=0; i < strlen; i++) {
    //         bool used = true;
    //         for (int j = 0; j < veclen; j++) {
    //             cout << strs[j][i] << ", ";
    //             if (j == 0) continue;
    //             // cout << "i_last = " << i_last << ", j=" << j << ", i=" << i << endl;
    //             // if (i_last > -1)
    //             // cout << "strs[j-1][i_last] ==  strs[j][i_last] -> " << strs[j-1][i_last] << "==" << strs[j][i_last] << endl; 
    //             if (i_last == -1 || strs[j-1][i_last] ==  strs[j][i_last]) {
    //                 // cout << "entered 1\n";
    //                 // cout << "strs[j-1][i] = " << strs[j-1][i]  << "\n";
    //                 // cout << "strs[j][i] = " << strs[j][i]  << "\n";
    //                 if (used && strs[j-1][i] > strs[j][i]) {
    //                     ret++;
    //                     // cout << "entered 2\n";
    //                     // cout << "ret=" << ret << " , i_last=" << i_last << endl;
    //                     used = false;
    //                     // break;
    //                 }
    //             }
                
    //         }
    //         cout << endl;
    //         if (used) i_last = i;
    //     }
    //     cout << i_last;

    //     return ret;
    // }

        int minDeletionSize(vector<string>& A) {
        int N = A.size();
        int W = A[0].size();
        vector<bool> cuts(N - 1, false);
        int ans = 0;

        for (int j = 0; j < W; ++j) {
            bool needDelete = false;
            for (int i = 0; i < N - 1; ++i) {
                if (!cuts[i] && A[i][j] > A[i + 1][j]) {
                    ans++;
                    needDelete = true;
                    break;
                }
            }
            if (needDelete) continue;
            for (int i = 0; i < N - 1; ++i) {
                if (A[i][j] < A[i + 1][j])
                    cuts[i] = true;
            }
        }
        return ans;
    }
};