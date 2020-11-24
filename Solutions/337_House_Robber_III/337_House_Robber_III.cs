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
    private int[] Dfs(TreeNode root){
        if(root == null)
            return new int[]{0,0};
        var left = Dfs(root.left);
        var right = Dfs(root.right);
        var left_max = Math.Max(left[0], left[1]);
        var right_max = Math.Max(right[0], right[1]);
        var max_with_root = root.val+left[1] + right[1];
        var max_without_root = left_max + right_max;
        
        return new int[]{max_with_root, max_without_root};
    }
    public int Rob(TreeNode root) {
        var res = Dfs(root);
        return Math.Max(res[0], res[1]);
    }
}

//Third fastest
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

/*
Idea is to decide on whether to rob the house or not
If we are robbing the house then we can only rob houses which are below the child houses
else we are robbing the houses below
1st index of the array signifies the case where we are not robbing the house
2nd index of the array signifies the case where we are robbing the house
*/
    
public class Solution {
    public int Rob(TreeNode root) {
        if (root == null)
            return 0;
        var sum = Robbed(root);
        return Math.Max(sum[0], sum[1]);
    }
    
    private int[] Robbed(TreeNode root) 
    {
        if(root == null){
            return new int[2];
        }
        
        int[] left = Robbed(root.left);
        int[] right = Robbed(root.right);
        
        var result = new int[2];
        result[0] = Math.Max(left[0], left[1]) + Math.Max(right[0], right[1]);
        result[1] = root.val + left[0] + right[0];
        return result;
        
        
    }
}

//Second fastest
public class Solution {
    
    int[] Traverse(TreeNode root)
    {
        if(root == null) return new int[] { 0, 0};
        
        var left = Traverse(root.left);
        var right = Traverse(root.right);
        
        int rob = root.val + left[1] + right[1];
        int notRob = Math.Max(left[0], left[1]) + Math.Max(right[0], right[1]);
        
        return new int[] { rob, notRob };
    }
    
    public int Rob(TreeNode root) {
        var ans = Traverse(root);
        return Math.Max(ans[0], ans[1]);
    }
}

//Fastest
public class Solution {
    public int Rob(TreeNode root) {
       // return rob(node) and stores rob(node.left/right) in l/r.
            int Rob(TreeNode node, ref int l, ref int r) 
            {
                if (node == null) return 0;
                else
                {
                    int ll = 0;
                    int lr = 0;
                    int rl = 0;
                    int rr = 0;
                    l = Rob(node.left, ref ll, ref lr);
                    r = Rob(node.right, ref rl, ref rr);
                    return Math.Max(node.val + ll + lr + rl + rr, l + r);
                }
            }
            int left = 0;
            int right = 0;
            return Rob(root, ref left, ref right);
    }
}