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
    public int FindTilt(TreeNode root) {
        int tilt = 0;
        Traverse(root, ref tilt);
        return tilt;
    }
    
    public int Traverse(TreeNode root, ref int tilt){
        if(root == null)
            return 0;
        
        int left = Traverse(root.left, ref tilt);
        int right = Traverse(root.right, ref tilt);
        
        tilt += Math.Abs(left - right);
        
        return left + right + root.val;
    }
}

//Second fastest
public class Solution {
    public int FindTilt(TreeNode root) {
        var t = GetTilt(root);
        return t.Item2;
    }
    
    private Tuple<int, int> GetTilt(TreeNode root) {
        if(root == null) return new Tuple<int, int>(0, 0);
        var left = GetTilt(root.left);
        var right = GetTilt(root.right);
        var tilt = Math.Abs(left.Item1 - right.Item1) + left.Item2 + right.Item2;
        var sum = left.Item1 + right.Item1 + root.val;
        return new Tuple<int, int>(sum, tilt);
    }
}

//Fastest
public class Solution {
    int res = 0; 
    public int FindTilt(TreeNode root) {
        postOrder(root);
        return res; 
            
        
    }
    
    private int postOrder(TreeNode node){
        
        if(node == null )
            return 0;
        
        int left = postOrder(node.left); 
        int right = postOrder(node.right); 
        
        res += Math.Abs(left - right) ; 
        
        return node.val + right + left; 
    }
}