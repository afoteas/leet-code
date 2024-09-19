class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        for(auto& w: words) {
            bool found = true;
            for(char c: w){
                if (allowed.find(c) == string::npos) {
                    found = false;
                    break;
                }
            }
            if (found) ret++;
        }
        return ret;
        
    }
};