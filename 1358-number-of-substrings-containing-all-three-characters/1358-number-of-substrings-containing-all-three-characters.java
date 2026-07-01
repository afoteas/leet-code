class Solution {
    public int numberOfSubstrings(String s) {
        int aCnt = 0;
        int bCnt = 0;
        int cCnt = 0;
        int start = 0;
        int end = 0;
        int ret = 0;
        int ss = s.length();
        while (end<=ss && start<ss-1) {
            if(aCnt>0 && bCnt>0 && cCnt>0) {
                ret+=ss-end+1;
                if(s.charAt(start) == 'a') aCnt--;
                else if (s.charAt(start) == 'b') bCnt--;
                else cCnt--;
                start++;
            } else {
                if(end<ss) {
                    if(s.charAt(end) == 'a') aCnt++;
                    else if (s.charAt(end) == 'b') bCnt++;
                    else cCnt++;
                } else {
                    break;
                }
                end++;
            }
        }
        return ret;     
    }
}