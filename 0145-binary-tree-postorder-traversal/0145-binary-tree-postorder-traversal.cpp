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
    void postorderTraversalHelper(TreeNode* currentNode, vector<int>& result) {
        // Base case: if the node is null, return
        if (!currentNode) {
            return;
        }
        // Traverse left subtree
        postorderTraversalHelper(currentNode->left, result);
        // Traverse right subtree
        postorderTraversalHelper(currentNode->right, result);
        // Add the current node's value to the result list
        result.push_back(currentNode->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        // Start traversal from root
        postorderTraversalHelper(root, result);
        return result;
    }
};