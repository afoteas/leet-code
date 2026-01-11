class Solution {
public:
    int sumFourDivisorsMine(vector<int>& nums) {
        int ret = 0;
        // map<int, vector<int>> memo;
        for (auto& num: nums) {
            int max = sqrt(num);
            // cout << "max =" << max << endl;
            set<int> divisors {1, num};
            for(int i = 2; i <= max; ++i) {
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


    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int cnt = 0;
            int sum = 0;

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int e = x / d;
                    cnt++;
                    sum += d;

                    if (e != d) {
                        cnt++;
                        sum += e;
                    }
                }
                if (cnt > 4) break;
            }

            if (cnt == 4)
                ans += sum;
        }

        return ans;
    }
};