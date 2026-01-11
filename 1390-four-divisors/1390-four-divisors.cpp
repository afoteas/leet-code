class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0;
        // map<int, vector<int>> memo;
        for (auto& num: nums) {
            int max = sqrt(num);
            // cout << "max =" << max << endl;
            set<int> divisors {1, num};
            for(int i = 2; i <= max; i++) {
                int rest = num%i;
                int divisor = num/i;
                if (rest == 0) {
                    divisors.insert(i);
                    divisors.insert(divisor);
                }
            }
            if (divisors.size() == 4) {
                ret += accumulate(divisors.begin(), divisors.end(), 0);
            }
        }
        return ret;
    }
};