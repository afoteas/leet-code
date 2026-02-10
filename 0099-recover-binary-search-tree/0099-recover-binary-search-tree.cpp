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

    void dfs(TreeNode* root, vector<TreeNode*>& nodesArray) {
        if(!root) return;
        if(root->left) dfs(root->left, nodesArray);
        nodesArray.push_back(root);
        if(root->right) dfs(root->right, nodesArray);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodesArray;
        dfs(root, nodesArray);

        vector<TreeNode*> sw;

        for(int i=0 ; i< nodesArray.size();++i) {
            if(nodesArray[i]->val > nodesArray[i+1]->val) {
                sw.push_back(nodesArray[i]);
                break;
            }
        }
        for(int i=nodesArray.size()-1 ; i > 0; --i) {
            if(nodesArray[i]->val < nodesArray[i-1]->val) {
                sw.push_back(nodesArray[i]);
                break;
            }
        }

        int tmp = sw[0]-> val;
        sw[0]->val = sw[1]->val;
        sw[1]->val = tmp;

        // for (auto& node: nodesArray) {
        //     cout << node->val << " ";
        // }
                
    }
};