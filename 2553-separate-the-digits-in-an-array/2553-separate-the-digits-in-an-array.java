class Solution {
    public int[] separateDigits(int[] nums) {
        int totalDigits = 0;
        for (int num : nums) {
            if (num == 0) {
                totalDigits++;
            } else {
                int t = num;
                while (t > 0) {
                    totalDigits++;
                    t /= 10;
                }
            }
        }

        int[] ans = new int[totalDigits];
        int idx = 0;

        for (int num : nums) {
            if (num == 0) {
                ans[idx++] = 0;
                continue;
            }

            int digits = 0;
            int t = num;
            while (t > 0) {
                digits++;
                t /= 10;
            }

            int pow = 1;
            for (int i = 1; i < digits; i++) {
                pow *= 10;
            }

            while (pow > 0) {
                ans[idx++] = num / pow;
                num %= pow;
                pow /= 10;
            }
        }

        return ans;
    }
}