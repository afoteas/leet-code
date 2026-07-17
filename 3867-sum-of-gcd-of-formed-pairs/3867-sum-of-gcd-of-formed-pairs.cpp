class Solution {
public:
    int gcd(int x, int y) { 
        return y == 0 ? x : gcd(y, x % y); 
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> vxi(nums.size());
        vector<int> prefixGcd(nums.size());
        long long ret =0;
        for(int i=0; i<nums.size(); i++) {
            if(i) vxi[i] = max(vxi[i-1],nums[i]);
            else vxi[i] = nums[i];
        }
        for(int i=0; i<nums.size(); i++) {
            prefixGcd[i]=gcd(nums[i],vxi[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int x=0;
        int y=nums.size()-1;
        while(y>x) {
            ret += gcd(prefixGcd[x++], prefixGcd[y--]);
        }
        return ret;
    }
};