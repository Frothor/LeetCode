//
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
class Solution {
    public bool IsBalanced(TreeNode root) {
        return height(root) != -1;
    }
    
    private int height(TreeNode node) {
        if(node == null)
            return 0;
        int left = height(node.left);
        int right = height(node.right);
        if(left == -1 || right == -1 || Math.Abs(left - right) > 1)
            return -1;
        return Math.Max(left, right) + 1;
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
public class Solution {
    public bool IsBalanced(TreeNode root) 
    {
        if (CheckLength(root) == -1) return false;
        return true;
    }
    
    private int CheckLength(TreeNode root)
    {
        if (root == null) return 0;
        
        int left = CheckLength(root.left);
        if (left == -1) return -1;
        
        int right = CheckLength(root.right);
        if (right == -1) return -1;
        
        int diff = Math.Abs(left - right);
        
        if (diff > 1) return -1;
        return 1 + Math.Max(left, right);
        
    }
}

//Second fastest
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
    public bool IsBalanced(TreeNode root) {
        return GetBalancedDepth(root) != -1;
    }
    
    private int GetBalancedDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        if (root.left == null && root.right == null) {
            return 1;
        }
        
        //if ((root.left == null) != (root.right == null)) {
            //var any = GetBalancedDepth(root.left ?? root.right);
            //return any == -1 ? -1 : any + 1;
            //return -1;
        //}
        
        var left = GetBalancedDepth(root.left);
        var right = GetBalancedDepth(root.right);
        
        if (left == -1 || right == -1 || Math.Abs(left - right) > 1) {
            return -1;
        }
        
        return Math.Max(left, right) + 1;
    }
}

//Fastest
**
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
    public bool IsBalanced(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }

            var heightOfLeft = Height(root.left);
            var heightOfRight = Height(root.right);

            if (Math.Abs(heightOfLeft - heightOfRight) <= 1
                && IsBalanced(root.left)
                && IsBalanced(root.right))
            {
                return true;
            }

            return false;
        }

        public int Height(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }

            var height = 1 + Math.Max(Height(node.left), Height(node.right));
            return height;
        }
}