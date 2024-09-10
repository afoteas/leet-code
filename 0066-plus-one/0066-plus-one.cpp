class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = 1;
        for(int i = digits.size()-1; i> -1; --i) {
            int t = digits[i]+r;
            digits[i]=t%10;
            r = t > 9 ? 1: 0;
        }
        if (r) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
