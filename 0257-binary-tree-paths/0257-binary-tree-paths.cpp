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

    void dfs1(TreeNode*root, vector<int> parents, vector<string>&paths) {
        parents.push_back(root->val);
        if (root->left || root->right)
        {
            if (root->left) dfs1(root->left, parents, paths);
            if (root->right) dfs1(root->right, parents, paths);
        }
        else
        {
            string path = to_string(parents[0]);
            for (int i=1; i<parents.size(); ++i) {
                path += "->"+to_string(parents[i]);
            }
            paths.push_back(path);
        }
    }

    void dfs2(TreeNode*root, string parents, vector<string>&paths) {
        if (root->left || root->right)
        {
            if (root->left) dfs2(root->left, format("{}->{}",parents,root->left->val), paths);
            if (root->right) dfs2(root->right, format("{}->{}",parents,root->right->val), paths);
        }
        else
        {
            paths.push_back(parents);
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths = {};
        // dfs1(root,{},paths);
        dfs2(root,to_string(root->val),paths);
        return paths;
        
    }
};