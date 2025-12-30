class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        auto hasFraction = [](long double x) -> bool {
            long double ip;
            long double fp = std::modf(x, &ip);  // fp has the fractional part, same sign as x
            return fp != 0.0L;
        };
        for(int i=1; i<n+1; ++i) {
            for(int j=i; j<n+1;++j) {
                long double c = sqrt(i*i + j*j);
                // cout << "a: " << i << endl;
                // cout << "b: " << j << endl;
                // cout << "c: " << c << endl;
                if (c <= n) {
                    if(!hasFraction(c)) ans+=2;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};