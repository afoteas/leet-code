class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int ans = 0;

        int[] ones = new int[n];
        List<Integer> candidates = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    temp.add(j);
                    ones[j]++;
                }
            }
            if (temp.size() == 1) {
                candidates.add(temp.get(0));
            }
        }

        for (int col : candidates) {
            if (ones[col] == 1) {
                ans++;
            }
        }

        return ans;
    }
}