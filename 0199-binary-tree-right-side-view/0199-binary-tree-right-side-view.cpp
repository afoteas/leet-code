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
    vector<int> rightSideViewSlow(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        map<int,vector<int>> levels;
        function<void(TreeNode*, int)> addLevels = [&levels, &addLevels](TreeNode* node, int level) {
            levels[level].push_back(node->val);
            if (node->left) addLevels(node->left,level+1);
            if (node->right) addLevels(node->right,level+1);
        };
        addLevels(root, 0);
        for(auto &level: levels) {
            ret.push_back(level.second.back());
        }
        return ret;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if (!root) return view;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int countAtLevel = q.size();

            for (int i = 0; i < countAtLevel; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If we are at the right-most node in the level, add it to view
                if (i == countAtLevel - 1) view.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return view;
    }
};
