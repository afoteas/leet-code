class Solution {
    public int[] leftRightDifference(int[] nums) {
        int[] ret = new int[nums.length];
        int leftSum = 0;
        int rightSum = Arrays.stream(nums).sum();
        int i = 0;
        for(int num: nums) {
            rightSum -= num;
            ret[i++] = Math.abs(leftSum - rightSum);
            leftSum += num;
        }
        return ret;
    }
}