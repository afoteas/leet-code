class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool second = false;
        bool ret = false;
        for(auto& bit: bits) {
            // cout << "bit:" << bit << ", ";
            // cout << "second:" << second << ", ";
            // cout << "ret:" << ret << "\n";
            if (second) {
                second = false;
                ret = false;
                // cout << "\nentered!\n";
            }
            else {
                if (bit) {
                    second = true;
                } else {
                    second = false;
                    ret = true;
                }
            }
        }
        return ret;
    }
};