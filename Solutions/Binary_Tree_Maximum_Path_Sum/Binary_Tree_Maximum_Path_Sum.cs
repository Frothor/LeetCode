//C#, simple recursive postorder DFS solution
public class Solution {
    public int MaxPathSum(TreeNode root) {
        int maxPath = int.MinValue;
        MaxPathSum(root, ref maxPath);
        return maxPath;        
    }
    
    private int MaxPathSum(TreeNode node, ref int maxPath) {
        if (node == null)
            return 0;
        int left = MaxPathSum(node.left, ref maxPath);
        int right = MaxPathSum(node.right, ref maxPath);
        int maxChildPath = Math.Max(left, right);
        int currentMaxPath = Math.Max(node.val, node.val + Math.Max(maxChildPath, left + right));
        maxPath = Math.Max(maxPath, currentMaxPath);
        return Math.Max(node.val, node.val + maxChildPath);
    } 
}

//Easy C# DFS Solution
public class Solution
{
    private int Helper(ref int res, TreeNode node)
    {
        if (node == null)
        {
            return 0;
        }
        int value = node.val;
        int left = Helper(ref res, node.left);
        int right = Helper(ref res, node.right);
        int subTreeSum = value;
        subTreeSum = Math.Max(subTreeSum, value + left);
        subTreeSum = Math.Max(subTreeSum, value + right);
        res = Math.Max(res, subTreeSum);
        res = Math.Max(res, value + left + right);
        return subTreeSum;
    }
    public int MaxPathSum(TreeNode root)
    {
        int res = int.MinValue;
        Helper(ref res, root);
        return res;
    }
}
