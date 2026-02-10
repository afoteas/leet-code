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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while(!q.empty()) {
            pair<TreeNode*,TreeNode*> p = q.front();
            q.pop();
            if(!p.first && !p.second) continue;

            if(p.first && p.second && p.first->val == p.second->val) {
                q.push({p.first->right, p.second->left});
                q.push({p.first->left, p.second->right});
            } else {
                return false;
            }
        }
        return true;
        
    }
};