class Solution {
public:

    // vector<vector<double>> t;
    double t[101][101] = {};

    double champagneTower(int poured, int query_row, int query_glass) {
        // vector<vector<double>> t(query_row+1);
        // for(int i=0; i<=query_row; ++i) {
        //     t[i].resize(i+1,0.0);
        // }
        memset(t, 0, sizeof(t));
        t[0][0] = poured;

        for(int i=0; i<query_row; ++i) {
            for(int j=0; j<=i; ++j) {
                if(t[i][j] > 1.0) {
                    double overflow = t[i][j] - 1.0;
                    t[i+1][j] += overflow/2.0;
                    t[i+1][j+1] += overflow/2.0;
                }
            }
        }
        return min(1.0, t[query_row][query_glass]);
    }



    
    double solve(int poured, int row, int glass) {
        if(row < 0 || glass > row || glass < 0) {
            return 0.00;
        }
        
        if(row == 0 && glass == 0) {
            return poured;
        }
        
        if(t[row][glass] > -1) {
            return t[row][glass];
        }
        
        double left = (solve(poured, row - 1, glass - 1) - 1) / 2;
        if(left < 0) left = 0;
        
        double right = (solve(poured, row - 1, glass) - 1) / 2;
        if(right < 0) right = 0;
        
        return t[row][glass] = left + right;
    }
    
    double champagneTowerTopDown(int poured, int query_row, int query_glass) {
        // t.assign(query_row + 1, vector<double>(query_row + 1, -1.0));
        memset(t, -1, sizeof(t));
        return min(1.00, solve(poured, query_row, query_glass));
    }
};