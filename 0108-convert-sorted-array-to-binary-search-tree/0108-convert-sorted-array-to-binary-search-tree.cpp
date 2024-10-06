/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return nullptr;
        }
        int median = len/2;
        vector<int> first_half(nums.begin(), nums.begin() + median);
        vector<int> second_half(nums.begin() + median + 1, nums.end());
        return new TreeNode(nums[median], sortedArrayToBST(first_half), sortedArrayToBST(second_half));
    }
};
