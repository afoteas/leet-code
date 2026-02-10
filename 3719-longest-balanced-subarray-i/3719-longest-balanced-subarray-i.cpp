class Solution {
public:
    int longestBalancedSlow(vector<int>& nums) {
        int subLen = nums.size();
        while(subLen > 1) {
            for(int i=0; i<=nums.size()-subLen; ++i) {
                set<int> odd;
                set<int> even;
                for(int j=i; j<(i+subLen); ++j) {
                    if (nums[j]%2) odd.insert(nums[j]);
                    else even.insert(nums[j]);
                }
                if (odd.size() == even.size() && odd.size()) return subLen;
            }
            --subLen;
        }
        return 0;
    }

    int longestBalanced(vector<int>& nums) {
        int subLen = nums.size();
        while(subLen > 1) {
            unordered_map<int,int> odd;
            unordered_map<int,int> even;
            for(int i=0; i<=nums.size()-subLen; ++i) {
                if(i == 0) {
                    for(int j=i; j<(i+subLen); ++j) {
                        if (nums[j]%2) {
                            odd[nums[j]]++;
                        }
                        else {
                            even[nums[j]]++;
                        };
                    }
                } else {
                    int in = nums[i+subLen-1];
                    if (in % 2) {
                        odd[in]++;
                    } else {
                        even[in]++;
                    }
                    int out = nums[i-1];
                    if (out % 2) {
                        if (--odd[out] == 0) odd.erase(out);
                    } else {
                        if (--even[out] == 0) even.erase(out);
                    }
                }
                if (odd.size() == even.size()) return subLen;
            }
            --subLen;
        }
        return 0;
    }
};