class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        
        for(auto& num: nums) {
            freq[num]++;
        }
        sort(freq.begin(), freq.end(), greater<>());
        int ans = freq[0];
        for (int i = 1; i < 100; i++) {
            if(freq[i]==freq[i-1]) {
                ans += freq[i];
            } else {
                break;
            }
        }
        return ans;
    }
};