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
    public int MinDepth(TreeNode root) {
        if(root == null)
            return 0;
        
        if(root.left == null && root.right == null)
            return 1;
        if(root.left == null)
            return MinDepth(root.right) + 1;
        if(root.right == null)
            return MinDepth(root.left) + 1;
        
        return Math.Min(MinDepth(root.left), MinDepth(root.right)) + 1;
    }
}

//Most common
public class Solution
{
    public int MinDepth(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        
        if (root.left == null && root.right == null)
        {
            return 1;
        }
        
        int min = int.MaxValue;
        if (root.right != null)
        {
            min = Math.Min(MinDepth(root.right), min);
        }
        
        if (root.left != null)
        {
            min = Math.Min(MinDepth(root.left), min);
        }
        
        return min + 1;
    }
}

//Third fastest
public class Solution {
    
    private int m_MinimumDepth = int.MaxValue;
    
    public int MinDepth(TreeNode root) {
        FindNearestEndNode(root, 1);
        if (m_MinimumDepth == int.MaxValue)
            return 0;
            
        return m_MinimumDepth;
    }
    
    private void FindNearestEndNode(TreeNode node, int level)
    {
        if (node == null)
            return;
                  
        var result = level;
        
        if (node.left != null)
        {
            FindNearestEndNode(node.left, level + 1);
        }
        if (node.right != null)
        {
            FindNearestEndNode(node.right, level + 1);
        }        
        
        if (node.left == null && node.right == null && level < m_MinimumDepth)
            m_MinimumDepth = level;
    }
}

//Second fastest
public class Solution {
    public int MinDepth(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null) return 1 + MinDepth(root.right);
        if (root.right == null) return 1 + MinDepth(root.left);
        return 1 + Math.Min(MinDepth(root.left), MinDepth(root.right));
    }

//Fastest
public class Solution {
    public int MinDepth(TreeNode root) {
    int leftDepth = 0;
    int rightDepth = 0;
    if (root == null) return 0;
        
    leftDepth = MinDepth(root.left);
    rightDepth = MinDepth(root.right);
     
    if (leftDepth!=0 && rightDepth!=0)
        return Math.Min(leftDepth,rightDepth) + 1;    
    else if (leftDepth ==0)
        return rightDepth + 1;    
    else
        return leftDepth + 1;    
    }
}