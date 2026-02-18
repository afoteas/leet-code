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
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        vector<TreeNode*> l;
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            l.push_back(cur);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);

        }
        for(int i = 0; i<l.size()-1; ++i) {
            l[i]->left = nullptr;
            l[i]->right = l[i+1];
        }
        l.back()->left=nullptr;
        l.back()->right=nullptr;
        root = l.back();
        
    }
};