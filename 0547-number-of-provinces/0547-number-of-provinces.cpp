class Solution {
public:
    void dfs(const vector<vector<int>>& isConnected, int i, int len, vector<bool>& visit) {
        for(int j=0; j<len; ++j) {
            if(isConnected[i][j] == 1 && !visit.at(j)) {
                visit.at(j) = true;
                dfs(isConnected, j, len, visit);
            }
        }


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        int count = 0;
        vector<bool> visit(len, false);
        for(int i=0; i<len;i++) {
            if(!visit.at(i)) {
                count++;
                visit.at(i)=true;
                dfs(isConnected,i,len,visit);
                }
        }
        return count;
    }
};