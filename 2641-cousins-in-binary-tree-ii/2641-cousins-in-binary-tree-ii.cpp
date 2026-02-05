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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        if (root->left) root->left->val = 0;
        if (root->right) root->right->val = 0;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({nullptr, root});

        while(!q.empty()){
            int levelSize=q.size();
            vector<pair<TreeNode*,int>> values {{q.front().first,q.front().second->val}};
            for(int i = 0; i<levelSize; ++i) {
                pair<TreeNode*,TreeNode*> cur = q.front();
                q.pop();
                if (i>0) {
                    if (values.back().first == cur.first) values.back().second += cur.second->val;
                    else values.push_back({cur.first,cur.second->val});
                }
                if(cur.second->left) q.push({cur.second,cur.second->left});
                if(cur.second->right) q.push({cur.second,cur.second->right});
            }
            if (values.size() == 1) {
                if(values[0].first && values[0].first->left) values[0].first->left->val = 0;
                if(values[0].first && values[0].first->right) values[0].first->right->val = 0;
            } else {
                int total = 0;
                for(auto& value: values) {
                    total += value.second;
                }
                for(auto& value: values) {
                    if(value.first->left) value.first->left->val = total - value.second;
                    if(value.first->right) value.first->right->val = total - value.second;
                }
            }
        }
        return root;
        
    }
};