class Solution {
public:
    string makeGood(string s) {
        int l = s.length();
        string ret = "";
        if (l < 2) {
            return s;
        }
        for(const auto& ch: s) {
            if(ret.length() > 0 && abs(int(ch) - int(ret.back())) == 32) {
                ret.pop_back();
            } else {
                ret.push_back(ch);
            }
        }
        return ret;    
    }
};
