class Solution {
public:
    int countTriplesMine(int n) {
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

    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a; b <= n; ++b) { // start at a to avoid duplicate work
                long long c2 = 1LL * a * a + 1LL * b * b;
                long long c  = static_cast<long long>(std::sqrt(static_cast<long double>(c2)) + 0.5L);
                if (c > n) break;          // b only increases, so c will only grow
                if (c * c == c2) {
                    ans += (a == b) ? 1 : 2; // (a,b,c) and (b,a,c) if distinct
                }
            }
        }
        return ans;
    }
};