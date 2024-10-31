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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        std::vector<double> levels;
        std::function<void(TreeNode*, int)> kfun = [&](TreeNode* node, int level) {
            if (!node) return;
            if (levels.size() == level) {
                levels.push_back(node->val);
            } else {
                levels[level] += node->val;
            }

            if (node->left) kfun(node->left, level + 1);
            if (node->right) kfun(node->right, level + 1);
        };

        kfun(root, 0);

        if (levels.size() < k) {
            return -1;
        }

        std::sort(levels.rbegin(), levels.rend());
        return levels[k - 1];
        
    }
};
