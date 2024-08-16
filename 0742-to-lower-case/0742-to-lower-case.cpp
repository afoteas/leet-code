class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.size(); i++) {
            int asci = static_cast<int>(s[i]);
            if( asci < 91 && asci > 64) {
                s[i] = static_cast<char>(asci + 32);
            }
        }
        return s;
    }
};