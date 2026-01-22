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
        unordered_map<int,int> mapa;
        int i = 1;
        while (i < 1001) {
            mapa.insert({(i|(i+1)),i});
            ++i;
        }
        for(const auto& num: nums) {
            // auto it = mapa.find(num);
            // if (it != mapa.end()) {
            //     ans.push_back(it->second);
            // }
            // else {
            //     ans.push_back(-1);
            // }

            try {
                ans.push_back(mapa.at(num));
            } catch (const std::out_of_range& e) {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};