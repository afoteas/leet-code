class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ht;
        for(auto&c:s) {
            ht[c]++;
        }
        int r = 0;
        for(auto&c:ht) {
            if (c.second%2) r++;
        }
        if(r) return  s.size() - r + 1;
        return s.size();
    }
};