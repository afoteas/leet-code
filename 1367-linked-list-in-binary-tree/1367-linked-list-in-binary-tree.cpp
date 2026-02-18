/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPathMine(ListNode* head, TreeNode* root) {
        
        stack<pair<array<TreeNode*, 2>,ListNode*>> st;
        st.push({{root,root},head});
        while(!st.empty()) {
            auto [trees, list] = st.top();
            st.pop();
            if(trees[0]->val == list->val) {
                if(!list->next) return true;
                if(trees[0]->left) st.push({{trees[0]->left, trees[1]}, list->next});
                if(trees[0]->right) st.push({{trees[0]->right, trees[1]}, list->next});
            } else {
                if(trees[1]->left) st.push({{trees[1]->left, trees[1]->left},head});
                if(trees[1]->right) st.push({{trees[1]->right, trees[1]->right},head});
            }
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        
        // Try matching starting from this node OR skip this node
        return isMatching(head, root) || 
               isSubPath(head, root->left) || 
               isSubPath(head, root->right);
    }
    
private:
    bool isMatching(ListNode* list, TreeNode* tree) {
        // If list is done, we found the full path
        if (!list) return true;
        
        // If tree is done but list isn't, no match
        if (!tree) return false;
        
        // Values must match AND rest of list must match rest of tree
        return list->val == tree->val && 
               (isMatching(list->next, tree->left) || 
                isMatching(list->next, tree->right));
    }
};