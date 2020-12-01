//Most common
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
    public int MaxDepth(TreeNode root) {
        return Dfs(root);
    }
    
    private int Dfs(TreeNode root){
        if(root == null)
            return 0;
        
        int left = Dfs(root.left);
        int right = Dfs(root.right);
        
        return Math.Max(left + 1, right +1);
    }
}

//Third fastest
public class Solution {
    public int MaxDepth(TreeNode root) {
        if(root == null) return 0;
        else {
            int left_height = MaxDepth(root.left);
            int right_height = MaxDepth(root.right);
            return Math.Max(left_height, right_height) + 1;
        }
    }
}

//Second fastest
public class Solution {
    public int MaxDepth(TreeNode root) {
        if (root == null)
            return 0;
        else
        {
            int leftHeight = MaxDepth(root.left);
            int rightHeight = MaxDepth(root.right);

            return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        }   
    }
}

//Fastest
public class Solution {
    public int MaxDepth(TreeNode root) {
        return MaxDepth4(root);
    }

    // DFS - PreOrder Traversal - Using Recursion
    public int MaxDepth1(TreeNode root) {
        if (root == null) return 0;
        
        return Math.Max(
                MaxDepth(root.left), 
                MaxDepth(root.right)
                ) + 1;
    }
    
    // DFS - InOrder Traversal - Using Stack
    public int MaxDepth2(TreeNode root) {
        if (root == null) return 0;
        var node = root;
        
        var nodes = new Stack<TreeNode>();
        var depths = new Stack<int>();

        var max = 0;
        var depth = 1;
        while (node != null || nodes.Count > 0) {
            if (node != null) {
                Console.WriteLine($"{node.val}");
                nodes.Push(node);
                depths.Push(depth);
                
                // Location for PreOrder Traversal
                // if (depth > max) max = depth;

                node = node.left;
                // depth++;
            } else {
                node = nodes.Pop();
                depth = depths.Pop();
                
                // Location for InOrder Traversal
                // if (depth > max) max = depth;
                
                node = node.right;
                // depth++;
            }
            if (depth > max) max = depth;
            depth++;

        }
        return max;
    }    

    // DFS - PreOrder Traversal - Using Stack
    public int MaxDepth4(TreeNode root) {
        if (root == null) return 0;
        
        var node = root;
        var depth = 0;
        var nodes = new Stack<TreeNode>();
        var depths = new Stack<int>();

        var max = 0;
        while (node != null || nodes.Count > 0) {
            if (node != null) {
                nodes.Push(node);
                depths.Push(++depth);

                if (depth > max) max = depth;

                node = node.left;
            } else {
                node = nodes.Pop();
                depth = depths.Pop();

                node = node.right;
            }
        }
        return max;
    }    
    
    // BFS - Level Order Traversal - Using Queue
    public int MaxDepth3(TreeNode root) {
        if (root == null) return 0;
        
        var queue = new Queue<Pair>();
        queue.Enqueue(new Pair(root, 1));    

        var max = 0;
        while (queue.Count > 0) {
            var pair = queue.Dequeue();
            var node = pair.Node;
            var depth = pair.Depth;

            max = Math.Max(max, depth);

            if (node.left != null) queue.Enqueue(new Pair(node.left, depth+1));
            if (node.right != null) queue.Enqueue(new Pair(node.right, depth+1));
        }
        return max;
    }    
            
    private class Pair {
        public TreeNode Node;
        public int Depth;

        public Pair (TreeNode node, int depth) {
            Node = node;
            Depth = depth;
        }
    }
}