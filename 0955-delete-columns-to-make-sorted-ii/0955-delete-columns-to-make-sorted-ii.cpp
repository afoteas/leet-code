class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strlen = strs[0].size();
        int veclen = strs.size();
        int ret = 0;
        int j_last = -1;
        vector<bool> inorder(veclen - 1, false);

        for(int j=0; j < strlen; j++) {
            bool used = true;
            for (int i = 1; i < veclen; i++) {
                if (!inorder[i-1] && strs[i-1][j] > strs[i][j]) {
                    ret++;
                    used = false;
                    break;
                }
            }
            if (used){
                for (int i = 1; i < veclen; i++) {
                    if (strs[i-1][j] < strs[i][j]) {
                        inorder[i-1] = true;
                    }
                }
            }
        }

        return ret;
    }

        int minDeletionSize2(vector<string>& A) {
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