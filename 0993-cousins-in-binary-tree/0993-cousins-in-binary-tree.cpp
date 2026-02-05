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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root-> val == x || root-> val == y) return false;
        stack<pair<int,TreeNode*>> st;
        st.push({0,root});
        int xp, yp, xl, yl;
        while(!st.empty()) {
            pair<int,TreeNode*> cur = st.top();
            st.pop();
            if (cur.second->left) {
                st.push({cur.first+1, cur.second->left});
                if(cur.second->left->val == x) {
                    xl = cur.first;
                    xp = cur.second->val;
                }
                if(cur.second->left->val == y) {
                    yl = cur.first;
                    yp = cur.second->val;
                } 
            }
            if (cur.second->right) {
                st.push({cur.first+1, cur.second->right});
                if(cur.second->right->val == x) {
                    xl = cur.first;
                    xp = cur.second->val;
                }
                if(cur.second->right->val == y) {
                    yl = cur.first;
                    yp = cur.second->val;
                } 
            }
        }
        return (xl==yl) && (xp != yp);
        
    }
};