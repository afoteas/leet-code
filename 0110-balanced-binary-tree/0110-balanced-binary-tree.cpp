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
    int dfs(TreeNode* root) {
        int l=0,r=0;
        if(root->left) l=dfs(root->left);
        if(root->right) r=dfs(root->right);
        if (l==-1 || r==-1 || abs(l-r)>1) return -1;
        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return dfs(root) != -1;
    }

    bool isBalancedBFS_ERROR(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        int l=1;
        int u=0;
        bool e = false;
        while(!q.empty()) {
            int s=q.size();
            if (e) return false;
            if (s!=l) {
                if (s <= l>>1) e=true; 
                if (++u > 2) return false;
            }
            for(int i=0; i<s; ++i) {
                TreeNode* c=q.front();
                q.pop();
                if(c->left) q.push(c->left);
                if(c->right) q.push(c->right);
            }
            l <<=1;
        }
        return true;
    }
};