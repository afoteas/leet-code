class Solution {
public:
    string addBinary(string a, string b) {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int la = a.length();
        int lb = b.length();
        int i = 0;
        char rem = '0';
        string ret = "";
        while(i < la && i < lb) {
            if (a[i]==b[i]) {
                if (a[i]=='1') {
                    if(rem == '0') {
                        ret.push_back('0');
                    } else {
                        ret.push_back('1');
                    }
                    rem = '1';
                } else {
                    ret.push_back(rem);
                    rem = '0';
                }
            } else {
                if (rem == '0') {
                    ret.push_back('1');
                } else {
                    ret.push_back('0');
                }
            }
            i++;
        }
        if (la > lb) {
            while(i < la ) {
                if (a[i]=='0') {
                    if (rem == '1') {
                        ret.push_back('1');
                        rem = '0';
                    } else {
                        ret.push_back('0');
                    }
                } else {
                    if (rem == '1') {
                        ret.push_back('0');
                    } else {
                        ret.push_back('1');
                    }
                }
                i++;
            }
        } else {
            // cout << "rem: "<<rem << ", b["<<i<<"]=" <<b[i];
              while(i < lb ) {
                if (b[i]=='0') {
                    if (rem == '1') {
                        ret.push_back('1');
                        rem = '0';
                    } else {
                        // cout << "rem: "<<rem << ", b["<<i<<"]=" <<b[i];
                        ret.push_back('0');
                    }
                } else {
                    if (rem == '1') {
                        ret.push_back('0');
                    } else {
                        ret.push_back('1');
                    }
                }
                i++;
            }          
        }
        if (rem == '1') {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};