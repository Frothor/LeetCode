/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int dfs(TreeNode root, ref int h){
        if(root == null)
            return 0;
        int left = dfs(root.left, ref h);
        int right = dfs(root.right, ref h);
        
        h = Math.Max(left + right, h);
        
        return Math.Max(left, right) + 1;
    }
    public int DiameterOfBinaryTree(TreeNode root) {
        int d = 0;
        dfs(root, ref d);
        return d;
    }
}

//Second fastest
public class Solution {
    int numOfNodes =0;
    public int DiameterOfBinaryTree(TreeNode root) {
        
        Height(root);
        return numOfNodes;
    }
    
    public int Height(TreeNode node) {
        if (node == null) {
            return 0;   
        }
        int left = Height(node.left);
        int right = Height(node.right);
        numOfNodes = Math.Max(numOfNodes, left + right);
        return Math.Max(left, right) + 1;
    }
}

//Fastest
public class Solution {
    public int DiameterOfBinaryTree(TreeNode root) {
                if (root == null) return 0;
                int res = 0;
                //dfs(root, ref res);
                dfs2(root, ref res);
                return res;
            }
            private static int dfs(TreeNode node, ref int res) {
                if (node == null) return -1;
                int l = dfs(node.left, ref res) + 1;
                int r = dfs(node.right, ref res) + 1;
                res = Math.Max(res, l + r);
                return Math.Max(l, r);
            }
            private static int dfs2(TreeNode node, ref int res) {
                int l = node.left == null ? 0 : 1 + dfs2(node.left, ref res);
                int r = node.right == null ? 0 : 1 + dfs2(node.right, ref res);
                res = Math.Max(res, l + r);
                return Math.Max(l, r);
            }
}