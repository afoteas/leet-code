class Solution {
public:
    string reverseWords(string s) {
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
};