class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row+1);
        for(int i=0; i<=query_row; ++i) {
            tower[i].resize(i+1,0.0);
        }
        tower[0][0] = poured;

        for(int i=0; i<query_row; ++i) {
            for(int j=0; j<=i; ++j) {
                if(tower[i][j] > 1.0) {
                    double overflow = tower[i][j] - 1.0;
                    // tower[i][j] = 1.0;
                    tower[i+1][j] += overflow/2.0;
                    tower[i+1][j+1] += overflow/2.0;
                }
            }
        }
        return min(1.0, tower[query_row][query_glass]);
    }
};