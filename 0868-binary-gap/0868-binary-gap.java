class Solution {
    public int binaryGap(int n) {
        int first=-1,second=-1, i=0, ret=0;

        while ((n>>i)>0) {
            if ((n & (1 << i)) != 0) {
                if (first==-1) {
                    first = i;
                }
                else if (second == -1) {
                    second = i;
                    ret = second - first;
                }
                else {
                    first = second;
                    second = i;
                    ret = Math.max(ret, second - first);
                }

            }
            i++;
        }
        return ret;
    }
}