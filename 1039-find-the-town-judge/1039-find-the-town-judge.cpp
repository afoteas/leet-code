class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustList(n+1,0);
        for(auto& t:trust) {
            trustList[t[0]]--;
            trustList[t[1]]++;
        }
        for(int i=1;i<(n+1);i++) {
            if(trustList[i] == n-1) {
                return i;
            }
        }
        return -1;
        
    }
};