import java.util.HashMap;
import java.util.Map;

/**
 * LeetCode 1. Two Sum
 * Java implementation compatible with LeetCode judge.
 */
public class Solution {
    /**
     * Returns indices of the two numbers such that they add up to target.
     * Time: O(n), Space: O(n)
     */
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>(); // value -> index
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
