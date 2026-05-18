class Solution {
    public boolean rotateStringMine(String s, String goal) {
        if (s.length() != goal.length()) return false;
        if (s.equals(goal)) return true;
        String curr = s;
        for(int i = 0; i < s.length(); i++) {
            curr = curr.substring(1) + curr.charAt(0);
            if (curr.equals(goal)) return true;
        }
        return false;
    }

    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;
        return (s + s).contains(goal);
    }
}
