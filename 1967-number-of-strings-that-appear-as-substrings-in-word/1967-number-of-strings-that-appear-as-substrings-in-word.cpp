class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ret = 0;
        for (auto& p: patterns) {
            if (word.contains(p)) ret++;
        }
        return ret;
    }
};