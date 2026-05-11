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
            if (num < 10) {
                ans[idx++] = num;
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

    public int[] separateDigitsSize(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            if (num < 10) {
                list.add(num);
                continue;
            }

            int tmp = 1;
            while (tmp <= num) tmp *= 10;

            while (tmp > 1) {
                tmp /= 10;
                list.add((num / tmp) % 10);
            }
        }

        int[] ret = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }
}

    // vector<int> separateDigits(vector<int>& nums) {
    //     vector<int> ret;
    //     for(auto& num: nums) {
    //         if (num == num%10) {
    //             ret.push_back(num);
    //             continue;
    //         }
    //         int tmp=1;
    //         while(tmp <= num) tmp*=10;
    //         while(tmp>1) {
    //             tmp/=10;
    //             ret.push_back((num/tmp)%10);
    //         }
    //     }
    //     return ret;
    // }