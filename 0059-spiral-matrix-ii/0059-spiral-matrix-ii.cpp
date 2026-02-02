class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, std::vector<int>(n, 0));
        pair<int,int> top_left(0,0); //(y,x)
        pair<int,int> top_right(0,n-1);
        pair<int,int> bottom_right(n-1,n-1);
        pair<int,int> bottom_left(n-1,0);
        int max = n*n;
        int i = 0;
        while(true) {
            // move right
            for(int j=top_left.second; j<top_right.second+1; j++) {
                matrix[top_right.first][j] = ++i;
            }
            top_right.first++;
            top_right.second--;

            if(i==max) break;

            //move down
            for(int j=top_right.first; j<bottom_right.first+1; j++) {
                matrix[j][bottom_right.second] = ++i;
            }
            bottom_right.first--;
            bottom_right.second--;
            if(i==max) break;

            // move left
            for(int j=bottom_right.second; j>=bottom_left.second; j--) {
                matrix[bottom_left.first][j] = ++i;
            }
            bottom_left.first--;
            bottom_left.second++;
            if(i==max) break;
            // move up
            for(int j=bottom_left.first; j>top_left.first; j--) {
                matrix[j][top_left.second] = ++i;
            }
            top_left.first++;
            top_left.second++;
            if(i==max) break;

        }
        return matrix;

        
    }
};