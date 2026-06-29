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

    public int maxNumberOfBalloonsCompact(String text) {
        int[] cnt = new int[26];
        for (char c : text.toCharArray()) cnt[c - 'a']++;
        return Math.min(
            Math.min(cnt['b' - 'a'], cnt['a' - 'a']),
            Math.min(Math.min(cnt['l' - 'a'] / 2, cnt['o' - 'a'] / 2), cnt['n' - 'a'])
        );
    }
}