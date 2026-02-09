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
    void inorder(TreeNode* root, vector<int>& treeValues) {
        if(root->left) inorder(root->left, treeValues);
        treeValues.push_back(root->val);
        if(root->right) inorder(root->right, treeValues);
    }

    TreeNode* buildBST(const vector<int>& treeValues, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(treeValues[mid]);
        root->left = buildBST(treeValues, l, mid -1);
        root->right = buildBST(treeValues, mid+1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        inorder(root, sortedValues);
        return buildBST(sortedValues, 0, sortedValues.size()-1);

    }
};