class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int maxy = 0;
        int miny = 1e9;
        long double upper = 0;
        long double lower = 0;
        // set<int> tops = {};
        for(auto& square: squares) {
            miny = square[1] < miny ? square[1] : miny;
            maxy = (square[1] + square[2]) > maxy ? (square[1] + square[2]) : maxy;
            upper+= double(square[2])*square[2];
            // tops.insert(square[1] + square[2]);
        }

        double ans = miny + (maxy-miny)/2.0;
        long double ansTop = maxy;
        long double ansBottom = miny;
        // cout << "miny:" << miny << ", maxy:" << maxy << endl;
        bool cut = false;

        while(abs(upper-lower) > 0) {
            // cout << "START\n"<< "upper:" << upper << ", lower:" << lower << ", upper-lower:" << abs(upper-lower) << endl;
            // cout << "ansTop:" << ansTop << ", ansBottom:" << ansBottom << endl;
            upper = 0;
            lower = 0;
            cut = false;

            for(auto& square: squares) {
                const long bottom = square[1];
                const long top = square[1] + square[2];
                if(bottom >= ans) {
                    upper += double(square[2])*square[2];
                }
                else if (top <= ans) {
                    lower += (long double)(square[2])*square[2];
                } else {
                    lower += (long double)(square[2])*(ans-bottom);
                    upper += (long double)(square[2])*(top-ans);
                    cut = true;
                }
            }



            if (upper > lower) {
                ansBottom = ans;
                ans = ansBottom + (ansTop-ansBottom)/2.0;
            } else if ((upper < lower)) {
                ansTop = ans;
                ans = ansTop - (ansTop-ansBottom)/2.0;
            } else {
                break;
            }

            long long ia = static_cast<long long>((ansTop) * 1e5);
            long long ib = static_cast<long long>((ansBottom+1e-6) * 1e5);
            // cout << "ia:" << ia << ", ib:" << ib << endl;
            if (ia == ib) {
                break;
            }

            // cout << "END\n"<< "upper:" << upper << ", lower:" << lower << endl;
        }

        if (!cut) {
            double tempAns = 0;
            // for(auto& y:tops) {
            //     if (y <= ans) {
            //         tempAns = y;
            //     }
            // }

            for(auto& square: squares) {
                int top = square[1] + square[2];
                if (top <= ans && top > tempAns) {
                    tempAns = top;
                }
            }
            ans = tempAns;
        }

        return ans;
        
    }
};