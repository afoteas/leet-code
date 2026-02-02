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
            // cout << "in while" << endl;
            // move right
            // cout << "top_right.first"<< top_right.first <<endl;
            // cout << "top_left.second"<< top_left.second <<endl;
            // cout << "top_right.second"<< top_right.second <<endl;
            for(int j=top_left.second; j<top_right.second+1; j++) {

                matrix[top_right.first][j] = ++i;

                // cout << i << " ";
            }
            top_right.first++;
            top_right.second--;

            if(i==max) break;
            // move down
            for(int j=top_right.first; j<bottom_right.first+1; j++) {
                matrix[j][bottom_right.second] = ++i;
                // cout << i << " ";
            }
            bottom_right.first--;
            bottom_right.second--;
            if(i==max) break;
            // move left
            for(int j=bottom_right.second; j>=bottom_left.second; j--) {
                matrix[bottom_left.first][j] = ++i;
                // cout<< i << " ";
            }
            bottom_left.first--;
            bottom_left.second++;
            if(i==max) break;
            // move up
            for(int j=bottom_left.first; j>top_left.first; j--) {
                matrix[j][top_left.second] = ++i;
                // cout<< i << " ";
                // cout<< "entered j ="<<j<<",i="<< i<<",top_left.second:" << top_left.second<<endl;
            }
            top_left.first++;
            top_left.second++;

            // cout << "entered1";
            if(i==max) break;
            // cout << "entered2\n";
        }
        return matrix;

        
    }
};