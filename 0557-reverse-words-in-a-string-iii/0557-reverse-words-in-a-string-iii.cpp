class Solution {
public:
    string reverseWordsMine(string s) {
        int begin=-1, end=-1;
        for(int i = 0; i< s.size(); ++i) {
            if(s[i]==' ') {
                while (begin < end) {
                    swap(s[begin++],s[end--]);
                }
                begin = -1;
                end = -1;
            } 
            else {
                if(begin != -1) {
                    end++;
                } else {
                    begin = i;
                    end = i;
                }
            }
        }
        while (begin < end) {
            swap(s[begin++],s[end--]);
        }
        return s;
    }

    string reverseWords(string s) {
        size_t start = 0;
        for (size_t i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                std::reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};