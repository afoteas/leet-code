class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool second = false;
        bool ret = false;
        for(auto& bit: bits) {
            if (second) {
                second = false;
                ret = false;
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