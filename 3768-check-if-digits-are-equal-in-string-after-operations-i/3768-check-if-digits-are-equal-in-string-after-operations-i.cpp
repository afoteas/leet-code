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

    bool hasSameDigitsBetter(string s) {
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
        // s.resize(size-1);
        s.pop_back();
        return hasSameDigits(s);

    }

    bool hasSameDigits(string& s) {
        const int n=s.size();
        for(int i=n-1; i>1; i--){
            for(int j=0; j<i; j++){
                s[j]=(s[j]-'0'+s[j+1]-'0')%10+'0';
            }
        }
        return s[0]==s[1];
    }
};