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

    void dfs(TreeNode*root, vector<int> parents, vector<string>&paths) {
        parents.push_back(root->val);
        if (root->left || root->right)
        {
            if (root->left) dfs(root->left, parents, paths);
            if (root->right) dfs(root->right, parents, paths);
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

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths = {};
        dfs(root,{},paths);
        return paths;
        
    }
};