//BFS
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
    public int RangeSumBST(TreeNode root, int low, int high) {
        int sum = 0;
        var q = new Queue<TreeNode>();
        q.Enqueue(root);
        while(q.Count != 0){
            var node = q.Dequeue();
            if(node.left != null)
                q.Enqueue(node.left);
            if(node.right != null)
                q.Enqueue(node.right);
            if(node.val >= low && node.val <= high)
                sum+=node.val;
        }
        
        return sum;
    }
}

//Fourth fastest
public class Solution {
    int ans;
    public int RangeSumBST(TreeNode root, int L, int R) {
        ans = 0;
        dfs(root, L, R);
        return ans;
    }

    public void dfs(TreeNode node, int L, int R) {
        if (node != null) {
            if (L <= node.val && node.val <= R)
                ans += node.val;
            if (L < node.val)
                dfs(node.left, L, R);
            if (node.val < R)
                dfs(node.right, L, R);
        }
    }
}

//Third fastest
public class Solution {
    int sum = 0;
    public int RangeSumBST(TreeNode root, int L, int R) {
        trav(root, L, R);
        return sum;
    }
    
    private void trav(TreeNode node, int L, int R)
    {
        if(node != null)
        {
            if(node.val >= L && node.val <= R)
                sum += node.val;
            trav(node.left, L, R);
            trav(node.right, L, R);
        }
    }
}

//Second fastest
public class Solution {
    int sum = 0;
    public int RangeSumBST(TreeNode root, int L, int R) 
    {
        InOrder(root,L,R);
        return sum;
    }
    
    private void InOrder(TreeNode node, int L, int R)
    {
        if(node == null)
            return;
        
        if(node.val >=L && node.val <= R)
        {
            sum+= node.val;
            if(node.val<=R)
                InOrder(node.left,L,R);
            if(node.val>=L)
                InOrder(node.right,L,R);
            
        }
        else if(node.val < L)
        {
            InOrder(node.right,L,R);
        }
        else if(node.val > R)
        {
            InOrder(node.left,L,R);
        }
    }
    
}

//Fastest
public class Solution {
    private int _low;
    private int _high;
    private int _sum;
    public int RangeSumBST(TreeNode root, int low, int high) {
        _low = low;
        _high = high;
        _sum = 0;
        void Traverse(TreeNode node)
        {
            if (node == null) return;
            
            if (low <= node.val && node.val <= _high)
            {
                _sum += node.val; 
                Traverse(node.right);
                Traverse(node.left);
            }
            else if (node.val >= _high)
            {
                Traverse(node.left);
            }
            else if (node.val <= _low)
            {
                Traverse(node.right);
            }
        }
        
        Traverse(root);
        return _sum;
    }
}