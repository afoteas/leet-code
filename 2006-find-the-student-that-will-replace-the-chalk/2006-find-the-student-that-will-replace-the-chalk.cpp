class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL); 
        k = k % sum;

        auto j {0};
        while (k > 0) {
            if (k >= chalk[j]) {
                k -= chalk[j];
            } else {
                return j;
            }
            j = (j + 1) % chalk.size();
        }
        
        return j;
        
    }
};