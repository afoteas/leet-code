class Solution {
    public int maxNumberOfBalloons(String text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;
        for(char c : text.toCharArray()) {
            switch (c) {
                case 'b':
                    b++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'l':
                    l++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'n':
                    n++;
                    break;
            }
        }
        int ret = 0;
        if (b < 1) {
            return 0;
        } else {
            ret = b;
        }
        if (a < 1) {
            return 0;
        } else {
            ret = Math.min(ret,a);
        }
        if (l < 2) {
            return 0;
        } else {
            ret = Math.min(ret,(l>>1));
        }
        if (o < 2) {
            return 0;
        } else {
            ret = Math.min(ret,(o>>1));
        }
        if (n < 1) {
            return 0;
        } else {
            ret = Math.min(ret,n);
        }
        return ret;
    }
}