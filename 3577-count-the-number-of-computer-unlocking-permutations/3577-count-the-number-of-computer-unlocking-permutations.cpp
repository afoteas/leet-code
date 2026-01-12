class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9 + 7;
        if(complexity[0] >= *min_element(complexity.begin()+1, complexity.end())) {
            return 0;
        }
        int n = complexity.size();
        const int N = 1e5 + 1;
        vector<long long> comp(n,1);
        for(int i = 1; i < n; ++i) {
            comp[i] = (comp[i-1]*i)%mod;
        }


        
        return comp[n-1]%mod;
    }
};