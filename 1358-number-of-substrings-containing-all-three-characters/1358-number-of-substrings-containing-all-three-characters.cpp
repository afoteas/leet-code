class Solution {
public:
    int numberOfSubstrings(string s) {
        int aCnt = 0;
        int bCnt = 0;
        int cCnt = 0;
        int start = 0;
        int end = 0;
        int ret = 0;
        int ss = s.size();
        while (end<=ss && start<ss) {
            // cout << "start:" << start << ", end:" << end << endl;
            // cout << "aCnt:" << aCnt << ", bCnt:" << bCnt << ", cCnt:" << cCnt << endl;
            if(aCnt && bCnt && cCnt) {
                ret+=ss-end+1;
                if(s[start] == 'a') aCnt--;
                else if (s[start] == 'b') bCnt--;
                else cCnt--;
                start++;
            } else {
                // cout << "entered" <<  endl;
                if(s[end] == 'a') aCnt++;
                else if (s[end] == 'b') bCnt++;
                else cCnt++;
                end++;
            }
            // cout << "ret:" << ret << endl;
        }
        return ret; 
    }
};