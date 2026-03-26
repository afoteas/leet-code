class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};
        vector<int> pre = getRow(rowIndex - 1);
        vector<int> ret(rowIndex+1, 1);
        for(int i = 1; i < rowIndex; i++) {
            ret[i] = pre[i-1] + pre[i];
        } 
        return ret;
    }
};