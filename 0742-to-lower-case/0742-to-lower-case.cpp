class Solution {
public:
    string toLowerCase(string s) {
        std::size_t len = s.size();
        for(int i=0; i<len; i++) {
            int asci = static_cast<int>(s[i]);
            if( asci < 91 && asci > 64) {
                s[i] = static_cast<char>(asci + 32);
            }
        }
        return s;
    }
};


    // def toLowerCase(self, s: str) -> str:
    //     ret = ""
    //     for c in s:
    //         if ord(c) < 91 and ord(c)>64:
    //             ret+=chr(ord(c)+32)
    //         else:
    //             ret+=c
    //     return ret