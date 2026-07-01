class Solution {
    public int lengthOfLastWord(String s) {
        String[] ret = s.split(" ");
        return ret[ret.length-1].length();
    }

    public int lengthOfLastWord2(String s) {
        boolean seenChar = false;
        int ret = 0;
        for(int i = s.length()-1; i>=0; i--){
            if(!seenChar) {
                if(s.charAt(i) == ' ') continue;
                else {
                    seenChar = true;
                    ret++;
                }
            } else {
                if(s.charAt(i) == ' ') return ret;
                else ret++;
            }
        }
        return ret;
    }
}