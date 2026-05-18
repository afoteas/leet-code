/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public int maxDepth(Node root) {
        int ret = 0;
        if(root == null) return ret;
        Queue<Node> q = new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()) {
            int levelsize = q.size();
            for(int i =0; i < levelsize; ++i) {
                Node cur = q.poll();
                for(Node n: cur.children) {
                    q.add(n);
                }
            }
            ret++;
        }
        return ret;
        
    }
}