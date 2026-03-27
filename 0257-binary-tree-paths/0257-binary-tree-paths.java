/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class Solution {

    void dfs(TreeNode root, String parents, List<String> paths) {
        if(parents.length() > 0) parents+="->" + root.val;
        else parents+=root.val;
    
        if (root.left != null || root.right != null)
        {
            if (root.left != null) dfs(root.left, parents, paths);
            if (root.right != null) dfs(root.right, parents, paths);
        }
        else
        {
            paths.add(parents);
        }

    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        dfs(root,"",paths);
        return paths;
        
    }
}