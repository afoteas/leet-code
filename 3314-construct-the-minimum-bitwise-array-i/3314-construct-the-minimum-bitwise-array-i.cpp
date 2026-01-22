class Solution {
public:
    vector<int> minBitwiseArraySlow(vector<int>& nums) {
        vector<int> ans;
        for(const auto& num: nums) {
            bool found = false;
            for (int i=1; i < num; ++i ) {
                if((i|(i+1)) == num) {
                    ans.push_back(i);
                    found = true;
                    break;
                } 
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mapa;
        int i = 1;
        while ((i|(i+1)) <= 2000) {
            mapa.insert({(i|(i+1)),i});
            ++i;
        }
        for(const auto& num: nums) {
            auto it = mapa.find(num);
            if (it != mapa.end()) {
                ans.push_back(it->second);
            }
            else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};