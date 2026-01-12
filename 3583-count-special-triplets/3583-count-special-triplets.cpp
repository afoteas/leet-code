class Solution {
public:
    int specialTripletsN3(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        for (int i = 0; i<len-2 ; ++i) {
            if(nums[i]%2 == 0 ) {
                for (int j= i+1; j < len -1; ++j) {
                    if (2*nums[j]==nums[i]) {
                        for (int k = j+1; k < len ; ++k) {
                            if (nums[k] == nums[i]) {
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    int specialTripletsN2(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        for (int i = 1; i<len-1 ; ++i) {
            int freqPrev = 0;
            int freqNext = 0;
            for(int j = 0; j <i; ++j) {
                if (2*nums[i]==nums[j]) {
                    ++freqPrev;
                }
            }
            if (!freqPrev) continue;
            for(int j = i+1; j <len; ++j) {
                if (2*nums[i]==nums[j]) {
                    ++freqNext;
                }
            }
            ans += freqPrev*freqNext;
        }
        return ans;

    }

    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        numCnt.reserve(nums.size() * 2);
        numPartialCnt.reserve(nums.size() * 2);

        for (int v : nums) {
            numCnt[v]++;
        }

        int ans = 0;
        for (int v : nums) {
            int target = v * 2;
            int lCnt = numPartialCnt[target];
            numPartialCnt[v]++;
            int rCnt = numCnt[target] - numPartialCnt[target];
            ans = (ans + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }

        return ans;
    }
};