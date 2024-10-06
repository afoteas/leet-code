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
    TreeNode* sortedArrayToBSTmine(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return nullptr;
        }
        int median = len/2;
        vector<int> first_half(nums.begin(), nums.begin() + median);
        vector<int> second_half(nums.begin() + median + 1, nums.end());
        return new TreeNode(nums[median], sortedArrayToBST(first_half), sortedArrayToBST(second_half));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);  // Pass the full array with indices
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;  // Base case: no elements in this range
        }

        int median = left + (right - left) / 2;  // Avoid overflow for large numbers
        TreeNode* node = new TreeNode(nums[median]);  // Create the root node with median value

        node->left = buildBST(nums, left, median - 1);  // Recursively build left subtree
        node->right = buildBST(nums, median + 1, right);  // Recursively build right subtree

        return node;
    }
};
