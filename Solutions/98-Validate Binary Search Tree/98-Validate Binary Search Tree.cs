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
    private List<int> list = new List<int>();
    
    private void InOrder(TreeNode root){
        if(root == null)
            return;
        InOrder(root.left);
        list.Add(root.val);
        InOrder(root.right);
        
    }
    public bool IsValidBST(TreeNode root) {
        if(root == null)
            return true;
        InOrder(root);
        for(int i = 1; i<list.Count; i++)
            if(list[i] <= list[i-1])
                return false;
        
        return true;
        
    }
}

//Fourth fastest
public class Solution {
    public bool IsValidBST(TreeNode root) {
        
        return IsBinarySeachTree(root,long.MinValue,long.MaxValue);
    }
    
     public static bool IsBinarySeachTree(TreeNode root, long min, long max)
        {
            if(root == null)
            {
                return true;
            }
         
          if (root.val >= max || root.val <= min)
            {
                return false;
            }


            if((IsBinarySeachTree(root.left,min,root.val) && (IsBinarySeachTree(root.right, root.val, max))))
            {
                return true;
            }

            return false;
        }
}

//Third fastest
public class Solution {
    public bool IsValidBST(TreeNode root) {
         return IsBST(root, null, null);
    }
    
    public bool IsBST(TreeNode root,int?lowerBound,int? upperBound)
    {
        if(root == null)
        {
            return true;
        }
        int iVal = root.val;
        if(lowerBound != null && iVal<=lowerBound)
            return false;
        if(upperBound != null && iVal>=upperBound)
            return false;
        return(IsBST(root.left,lowerBound,iVal) && IsBST(root.right,iVal,upperBound));
    }
}

//Second fastest
public class Solution {
    public bool IsValidBST(TreeNode root) {
       return IsValidBST(root,null,null);
    }
    
    public bool IsValidBST(TreeNode root, int? greaterval, int? lowerval)
    {
        if(root == null) 
            return true;
        
        if (greaterval != null && root.val >= greaterval.Value)
                return false;


            else if (lowerval != null && root.val <= lowerval.Value)
                return false;
        
        if(!IsValidBST(root.left,root.val,lowerval)) return false;
        if(!IsValidBST(root.right,greaterval,root.val)) return false;
        return true;
    }
}

//Fastest
public class Solution {
    public bool IsValidBST(TreeNode root) 
    {
        return Helper(root, long.MinValue, long.MaxValue);
    }
    
    public bool Helper(TreeNode root, long min, long max)
    {
        if (root == null) return true;
        
        if (root.val <= min || root.val >= max) return false;
        
        return Helper(root.left, min, (long)root.val) && Helper(root.right, (long)root.val, max);
    }
}