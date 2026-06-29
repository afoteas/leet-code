class Solution {
    public int titleToNumber(String columnTitle) {
        int l = columnTitle.length();
        int ret = 0;
        for (int i = l - 1; i >= 0; i--) {
            char c = columnTitle.charAt(i);
            int p = (int) (c - 'A');
            ret += (p+1)*Math.pow(26,l-i-1);
        }
        return ret;
        
    }
}
