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
    vector<int> rightSideView(TreeNode* root) {
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
        addLevels(root,0);
        for(auto &level: levels) {
            ret.push_back(level.second.back());
        }
        return ret;
    }
};


// def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
//     if not root:
//         return []
//     ret = []
//     levels = {}
//     def addLevels(node:Optional[TreeNode],level:int):
//         if level in levels:
//             levels[level].append(node.val)
//         else:
//             levels[level] = [node.val]
//         if node.left:
//             addLevels(node.left,level+1)
//         if node.right:
//             addLevels(node.right,level+1)
//     addLevels(root,0)
//     for values in levels.values():
//         ret.append(values[-1])
//     return ret