class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9 + 7;
        if(complexity[0] >= *min_element(complexity.begin()+1, complexity.end())) {
            return 0;
        }
        int n = complexity.size();
        long ans=1;
        for(int i = 1; i < n; ++i) {
            ans = (ans*i)%mod;
        }
        return ans%mod;
    }
};