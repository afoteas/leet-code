class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;
        for(auto& num: nums) {
            if (num == num%10) {
                ret.push_back(num);
                continue;
            }
            int tmp=1;
            while(tmp <= num) tmp*=10;
            while(tmp>1) {
                tmp/=10;
                ret.push_back((num/tmp)%10);
            }
        }
        return ret;
    }
};