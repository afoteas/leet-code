class Solution {
public:
    bool hasSameDigits(string s) {
        const int size = s.size();
        if(size == 2) {
            if(s[0] == s[1]) {
                return true;
            }
            else {
                return false;
            }
        }
        string ss (size-1, '0');
        for(int i = 0; i < size-1; i++) {
            ss[i] = (int(s[i]) + int(s[i+1]))%10;
        }
        return hasSameDigits(ss);

    }
};