
class Solution {
public:
    int hIndexMine(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int l = citations.size();
        int lt = l-1;
        while(lt>=0) {
            if (citations[lt] > l - lt) { 
                lt--;
            }
            else if (citations[lt]== l-lt) {
                return l-lt;
            } 
            else {
                return l - lt - 1;
            }
        }

        return min(l,citations[0]);  
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        for(int i =0; i<n; i++){
            if(n - i <= citations[i]){
                return n - i;
            }
        }
        return 0;
    }
};
