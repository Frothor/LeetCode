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
    private int Helper(TreeNode root, int min, int max){
        if(root == null)
            return max - min;
        
        min = Math.Min(root.val, min);
        max = Math.Max(root.val, max);
        
        int l = Helper(root.left, min, max);
        int r = Helper(root.right, min, max);
        
        return Math.Max(l, r);
    }
    
    public int MaxAncestorDiff(TreeNode root) {
        if(root == null)
            return 0;
        
        return Helper(root, root.val, root.val);
    }
}

//Another
public class Solution {
    private int result = 0;
  
    public int MaxAncestorDiff(TreeNode root) {
        PreOrder(root, root.val, root.val);
        
        return result;
    }
    
    private void PreOrder(TreeNode root, int min, int max)
    {
        if(root == null) return;
        
        result = Math.Max(result, Math.Abs(root.val - min));
        result = Math.Max(result, Math.Abs(root.val - max));
        
        var nextMin = Math.Min(root.val, min);
        var nextMax = Math.Max(root.val, max);
        
        PreOrder(root.left, nextMin, nextMax);
        PreOrder(root.right, nextMin, nextMax);
    }
}

//Second fastest
public class Solution {
    int ans = 0;
    public int MaxAncestorDiff(TreeNode root) {
        helper(root, root.val, root.val);
        return ans;
    }
    
    private void helper(TreeNode root, int min, int max) {
        if (root == null) {
            return;
        }
        
        ans = Math.Max(ans, Math.Max(Math.Abs(root.val - min), Math.Abs(root.val - max)));
        int newMin = Math.Min(root.val, min);
        int newMax = Math.Max(root.val, max);
        
        helper(root.left, newMin, newMax);
        helper(root.right, newMin, newMax);
    }
}

//Fastest
public class Solution {
    public int MaxAncestorDiff(TreeNode root) {
        if(root == null || (root.left == null && root.right == null))
            {
                return 0;
            }

            int maxDiff = int.MinValue;

            PostOrder(root, ref maxDiff);
            return maxDiff;
        }

        private static int[] PostOrder(TreeNode root, ref int maxDiff)
        {
            if(root == null)
            {
                return new int[2]{ int.MinValue, int.MaxValue};
            }

            if(root.left == null && root.right == null)
            {
                return new int[2] {root.val, root.val };
            }

            //记录到当前节点时候对应的最小值和最大值
            int[] leftChild = PostOrder(root.left, ref maxDiff);
            int[] rightChild = PostOrder(root.right, ref maxDiff);

            int[] currentMinMax = new int[2];

            if (root.left != null)
            {
                //当前节点跟它的左儿子对应的最大值、最小值之间的差
                maxDiff = Math.Max(maxDiff, Math.Abs(root.val - leftChild[0]));
                maxDiff = Math.Max(maxDiff, Math.Abs(root.val - leftChild[1]));

                //更新到当前节点时候的最大值、最小值
                currentMinMax[0] = Math.Min(leftChild[0], root.val);
                currentMinMax[1] = Math.Max(leftChild[1], root.val);
            }
            else //如果左儿子为空， 初始化currentMinMax为当前节点值
            {
                currentMinMax[0] = root.val;
                currentMinMax[1] = root.val;
            }

            if(root.right != null)
            {
                //当前节点跟它的右儿子对应的最大值、最小值之间的差
                maxDiff = Math.Max(maxDiff, Math.Abs(root.val - rightChild[0]));
                maxDiff = Math.Max(maxDiff, Math.Abs(root.val - rightChild[1]));

                //更新到当前节点时候的最大值、最小值
                currentMinMax[0] = Math.Min(currentMinMax[0], Math.Min(rightChild[0], root.val));
                currentMinMax[1] = Math.Max(currentMinMax[1], Math.Max(rightChild[1], root.val));
            }
            else
            {
                currentMinMax[0] = Math.Min(currentMinMax[0], root.val);
                currentMinMax[1] = Math.Max(currentMinMax[1], root.val);
            }

            return currentMinMax;
    }
}