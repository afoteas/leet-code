class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int ret = 0;
        for(String p: patterns) {
            if(word.contains(p)) ret++;
        }
        return ret;
    }
}