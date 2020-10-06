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
    private void Dfs(ref TreeNode root, int val) {
        if(val < root.val){
            if(root.left == null)
                root.left = new TreeNode(val);
            else
                Dfs(ref root.left, val);
        }
        else {
            if(root.right == null)
                root.right = new TreeNode(val);
            else
                Dfs(ref root.right, val);
        }
    }
    public TreeNode InsertIntoBST(TreeNode root, int val) {
        if(root == null)
            return new TreeNode(val);
        
        Dfs(ref root, val);
        return root;
    }
}

//Third fastest
public class Solution {
    public TreeNode Insert(TreeNode root, int val)
    {
        if(root==null)
        {
            return new TreeNode(val);
        }
        if(root.val<val)
        {
            root.right = Insert(root.right,val);
        }
        if(root.val>val)
        {
            root.left = Insert(root.left,val);
        }
        
        return root;
    }
    public TreeNode InsertIntoBST(TreeNode root, int val) {
        return Insert(root,val);
    }
}

//Second fastest
public class Solution {
    public TreeNode InsertIntoBST(TreeNode root, int val) {
        if (root == null){
            return new TreeNode(val);
        }
        
        InsertIntoBSTRec(root, val);
        return root;
    }
    
    private void InsertIntoBSTRec(TreeNode root, int val) {
        if (root.val < val){
            if (root.right == null){
                root.right = new TreeNode(val);
                return;
            }
            
            InsertIntoBSTRec(root.right, val);
            return;
        }   
        
        // root.val > val
        if (root.left == null){
            root.left = new TreeNode(val);
            return;
        }
        
        InsertIntoBSTRec(root.left, val);
    }
}

//Fastest
public class Solution {
    public TreeNode InsertIntoBST(TreeNode root, int val) {
			if (root == null) return new TreeNode(val);

			// find appropriate place to put node:
			var current = root;
			var parent = root;
			while (current != null)
			{
				parent = current;
				current = val < current.val ? current.left : current.right;
			}
			
			if(val < parent.val)
				parent.left = new TreeNode(val);
			else
				parent.right = new TreeNode(val);

			return root;
    }
}