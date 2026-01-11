
class Solution {
    
public:
    int repeatedNTimesMine(vector<int>& nums) {
        int len = nums.size();
        len >>=2;
        ++len;
        set<int> unique;
        for (auto& num : nums) {
            if (unique.count(num) == 0) {
                unique.insert(num);
            } else {
                return num;
            }
        }

        return 0;
    }
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size()-2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        return A.back();
    }
};