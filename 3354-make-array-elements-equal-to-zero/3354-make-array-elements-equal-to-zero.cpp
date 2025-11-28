class Solution {
public:
    int countValidSelectionsLambda(vector<int>& nums) {
        int count = 0;
        int nonZeros = 0;
        int n = nums.size();
        auto isValid = [&](int position, int direction) {
            int localNonZeros = nonZeros;
            std::vector<int> temp(nums);

            while (localNonZeros > 0 && position >= 0 && position < n) {
                if (temp[position] > 0) {
                    temp[position]--;
                    direction *= -1;
                    if (temp[position] == 0) {
                        localNonZeros--;
                    }
                }
                position += direction;
            }

            if(localNonZeros == 0) {
                count++;
            }
        };
        for(int i=0; i < n; i++) {
            if (nums[i] > 0) {
                nonZeros++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                isValid(i, -1);
                isValid(i, 1);
            }
        }
        return count;
    }
    int countValidSelectionsSlow(vector<int>& nums) {
        int count = 0;
        int nonZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                nonZeros++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, nonZeros, i, -1)) {
                    count++;
                }
                if (isValid(nums, nonZeros, i, 1)) {
                    count++;
                }
            }
        }

        return count;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) {
                    ans++;
                }
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) {
                    ans++;
                }
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
        return ans;
    }

private:
    bool isValid(const vector<int>& nums, int nonZeros, int start,
                 int direction) {
        int n = nums.size();
        vector<int> temp(nums);
        int curr = start;

        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0) {
                    nonZeros--;
                }
            }
            curr += direction;
        }

        return nonZeros == 0;
    }
};