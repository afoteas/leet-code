class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> maps {};
        for(const auto& num: nums) {
            if(maps.contains(num)) {
                if(maps[num] == 2) {
                    maps.erase(num);
                } else {
                    maps[num]=2;
                }
            }
            else {
                maps[num] = 1;
            }
        }

        return maps.begin()->first;
    }
};