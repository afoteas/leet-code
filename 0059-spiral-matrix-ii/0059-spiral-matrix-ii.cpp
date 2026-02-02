class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        pair<int,int> tl{0,0}, tr{0,n-1}, br{n-1,n-1}, bl{n-1,0};
        int max = n*n;
        int i = 0;
        while(true) {
            // move right
            for(int j=tl.second; j<tr.second+1; j++) m[tr.first][j] = ++i;
            tr.first++;
            tr.second--;
            if(i==max) break;

            //move down
            for(int j=tr.first; j<br.first+1; j++) m[j][br.second] = ++i;
            br.first--;
            br.second--;
            if(i==max) break;

            // move left
            for(int j=br.second; j>=bl.second; j--) m[bl.first][j] = ++i;
            bl.first--;
            bl.second++;
            if(i==max) break;

            // move up
            for(int j=bl.first; j>tl.first; j--) m[j][tl.second] = ++i;
            tl.first++;
            tl.second++;
            if(i==max) break;
        }
        return m;
    }
};