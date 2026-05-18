/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int ret = 0;
        if (!root) return ret;
        stack<pair<Node*,int>> st;
        st.push({root, 1});
        while(!st.empty()) {
            pair<Node*,int> cur = st.top();
            st.pop();
            for (Node* child : cur.first->children) {
                st.push({child, cur.second + 1});
            }
            ret = max(ret, cur.second);
        }
        return ret;
    }
};