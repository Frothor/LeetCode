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
    public TreeNode SubtreeWithAllDeepest(TreeNode root) {
        int d = GetDepth(root.left) - GetDepth(root.right);
        if(d == 0)
            return root;
        else if(d > 0)
            return SubtreeWithAllDeepest(root.left);
        else 
            return SubtreeWithAllDeepest(root.right);
    }
    
    private int GetDepth(TreeNode root){
        if(root == null)
            return 0;
        int left = GetDepth(root.left);
        int right = GetDepth(root.right);
        return 1 + Math.Max(left, right);
    }
}

//Fourth fastest
public class Solution {
       public class SubTree
        {
            public TreeNode parent { get; set; }
            public int level { get; set; }
            public SubTree(TreeNode p,int l)
            {
                parent = p;
                level = l;
            }
        }

        public SubTree FindSubTree(TreeNode root,int level, TreeNode parent)
        {
            if (root == null)
                return new SubTree(root, level);
            SubTree left = FindSubTree(root.left, level + 1, root);
            SubTree right = FindSubTree(root.right, level + 1, root);
            if (left.level > right.level)
            {
                return left;
            }
            else if (left.level < right.level)
            {
                return right;
            }
            return new SubTree(root, left.level);
        }

        public TreeNode SubtreeWithAllDeepest(TreeNode root)
        {
            SubTree subtree = FindSubTree(root,0, root);
            if (subtree != null)
                return subtree.parent;
            return null;
        }
}

//Third fastest
public class Solution {
    public TreeNode SubtreeWithAllDeepest(TreeNode root) {
        var maxDepth = FindDepth(root);
        return FindSubtree(root, 1, maxDepth);
    }
    
    TreeNode FindSubtree(TreeNode node, int depth, int maxDepth){
        if(null == node) return null;
        
        var isLeaf = (null == node.left && null == node.right);
        if(isLeaf && depth == maxDepth)
            return node;
        
        var left = FindSubtree(node.left, depth+1, maxDepth);
        var right = FindSubtree(node.right, depth+1, maxDepth);
        if(null != left && null != right)
            return node;
        return left ?? right;
    }
    
    int FindDepth(TreeNode node){
        if(null == node) return 0;
        return 1 + Math.Max(FindDepth(node.left), FindDepth(node.right));
    }
}

//Second fastest
public class Solution {
    public TreeNode SubtreeWithAllDeepest(TreeNode root) {
        var (_, node) = SubtreeWithAllDeepest(root, 0);
        
        return node;
    }
    
    public (int,TreeNode) SubtreeWithAllDeepest(TreeNode root, int depth) {
        if(root == null)
        {
            return (-1, null);
        }
        
        var (lDepth, lNode) = SubtreeWithAllDeepest(root.left, depth+1);
        var (rDepth, rNode) = SubtreeWithAllDeepest(root.right, depth+1);
        
        if(lDepth == rDepth)
        {
            if(lDepth == -1)
            {
                return (depth, root);
            }
            else
            {
                return (lDepth, root);
            }
        }
        
        if(lDepth>rDepth)
            return (lDepth, lNode);
        else
            return (rDepth, rNode);
    }
}

//Fastest
public class Solution {
    public TreeNode SubtreeWithAllDeepest(TreeNode root) {
        var result = dfs(root); 
        return result.Item1;
    }
    
    private Tuple<TreeNode, int>dfs(TreeNode node) {
        if (node == null) {
            return new Tuple<TreeNode, int> (null, 0);
        }
        
        var left = dfs(node.left); 
        var right = dfs(node.right);
        
        if (left.Item2 > right.Item2) {
            return new Tuple<TreeNode, int> (left.Item1, left.Item2 + 1);
        }
        else if (left.Item2 < right.Item2) {
             return new Tuple<TreeNode, int> (right.Item1, right.Item2 + 1);
        }
        else {
            return new Tuple<TreeNode, int> (node, right.Item2 + 1);
        }
    }
}