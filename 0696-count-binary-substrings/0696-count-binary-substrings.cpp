class Solution {
public:
    int countBinarySubstrings(string& s) {
        vector<int> groups;
        int count = 1;
        
        // Build groups of consecutive same characters
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);
        
        // For each adjacent pair of groups, count valid substrings
        int ans = 0;
        for (int i = 0; i < groups.size() - 1; ++i) {
            ans += min(groups[i], groups[i+1]);
        }
        
        return ans;
    }

    int countBinarySubstringsSlow(string& s) {
        auto hasEqual = [] (string& input, int start, int window) -> bool {
            int ones = 0;
            int zeros = 0;
            bool o = false;
            bool z = false;
            char first = input[start];
            for(int i = start; i<start+window; ++i) {
                if(input[i]=='1') 
                {
                    o = true;
                    ones++;
                }
                else 
                {
                    z = true;
                    zeros++;
                }
                if (o == true && z == true && input[i]==first) return false;
            }
            return ones == zeros;
        };
        int ss = s.size();
        if(ss==1) return false;
        int window = ss;
        int ans = 0;
        while (window > 1) {
            if(window & 1) {
                window--;
                continue;
            }
            for(int i=0; i<(ss-window)+1; ++i) {
                if(hasEqual(s, i, window)) ans++;
            }
            window--;
        }
        return ans;
    }
};