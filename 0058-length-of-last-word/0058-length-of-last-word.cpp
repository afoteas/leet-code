class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int ret = 0;
        for(int i = size-1; i >= 0; --i) {
            if(s[i] == ' ' && ret !=0) {
                break;
            } else if(s[i] != ' ') {
                ++ret;
            }
        }
        return ret;
    }
};