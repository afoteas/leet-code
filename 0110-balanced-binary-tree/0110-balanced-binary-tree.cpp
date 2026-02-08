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
    int dfs(TreeNode* root, bool& ret) {
        int l=0,r=0;
        if (!ret) return 0;
        if(root->left) l=dfs(root->left, ret);
        if(root->right) r=dfs(root->right, ret);
        if (abs(l-r)>1) {
            ret = false;
            return 0;
        }
        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool ret=true;
        dfs(root, ret);
        return ret;
    }
};