class Solution {
public:
    bool hasSameDigitsFirst(string s) {
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
        for(int i = 0; i < size-1; i++) {
            s[i] = (int(s[i]) + int(s[i+1]))%10;
        }
        s.resize(size-1);
        return hasSameDigits(s);

    }
};