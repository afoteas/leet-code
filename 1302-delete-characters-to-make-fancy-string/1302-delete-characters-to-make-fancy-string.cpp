class Solution {
public:
    string makeFancyStringRemove(string s) {
        char previous = '\0';
        bool twice = false;
        string ret = "";
        for(string::iterator it = s.begin(); it != s.end();) {
            char c = *it;
            if (c == previous) {
                if (twice) {
                    s.erase(it);
                } else {
                    twice = true;
                    it++;
                }
            } else {
                previous = c;
                twice = false;
                it++;
            }
        }
        return s;
    }

    string makeFancyString(string s) {
        char previous = '\0';
        bool twice = false;
        string ret = "";
        for(string::iterator it = s.begin(); it != s.end();it++) {
            char c = *it;
            if (c == previous) {
                if (!twice) {
                    ret.push_back(c);
                    twice = true;
                }
            } else {
                ret.push_back(c);
                previous = c;
                twice = false;
            }
        }
        return ret;
    }
};