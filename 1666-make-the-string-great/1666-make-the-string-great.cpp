class Solution {
public:
    string makeGood(string s) {
        int l = s.length();
        string ret = "";
        if (l < 2) {
            return s;
        }
        for(int i=0; i<l;++i) {
            if(ret.length() > 0 && abs(int(s.at(i) - int(ret.back()))) == 32) {
                ret.pop_back();
            } else {
                ret.push_back(s.at(i));
            }
        }
        return ret;    
    }
};


        // if len(s) < 2:
        //     return s
        // ret = []
        // i = 0
        // last = "?"
        // l = len(s)
        // while i < l:
        //     if ret and abs(ord(s[i]) - ord(ret[-1])) == 32:
        //         ret.pop()
        //     else:
        //         ret.append(s[i])
        //     i+=1
        // return "".join(ret)