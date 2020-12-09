//https://leetcode.com/problems/binary-search-tree-iterator/discuss/293278/C-inorder
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
public class BSTIterator {
    Stack<TreeNode> s = new Stack<TreeNode>();

    public BSTIterator(TreeNode root) {
        while(root != null){
            s.Push(root);
            root = root.left;
        }
    }
    
    public int Next() {
        var next = s.Pop();
        if(next.right != null){
            var curr = next.right;
            while(curr != null){
                s.Push(curr);
                curr = curr.left;
            }
        }
        return next.val;
    }
    
    public bool HasNext() {
        return s.Count != 0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */

//Third fastest
public class BSTIterator {
    Stack<TreeNode> stack = new Stack<TreeNode>();

    public BSTIterator(TreeNode root) => PullLeft(root);
    
    void PullLeft(TreeNode root)
    {
        while(root!=null){
            stack.Push(root);
            root = root.left;
        }
    }
   
    public int Next() {
        var cur = stack.Pop();
        PullLeft(cur.right);    
        return cur.val;
    }
    
    
    public bool HasNext() => stack.Count>0;
}


//Second fastest
public class BSTIterator 
{
    private Stack<TreeNode> stack;

    public BSTIterator(TreeNode root) 
    {
        stack = new Stack<TreeNode>();
        DFS(root);
    }
    
    /** @return the next smallest number */
    public int Next() 
    {
        TreeNode cur = stack.Pop();
        DFS(cur.right);
        return cur.val;
    }
    
    /** @return whether we have a next smallest number */
    public bool HasNext() 
    {
        return stack.Count > 0;
    }
    
    private void DFS(TreeNode parent)
    {
        if (parent == null)
            return;
        
        stack.Push(parent);
        DFS(parent.left);
    }
}

//Fastest
public class BSTIterator {

    TreeNode root;
    List<int> lnode = new List<int>();
    int index=0;
    public BSTIterator(TreeNode root) {
        this.root = root;
        InOrder(root);
        
    }
    private void InOrder(TreeNode root)
    {
        if(root == null) return;
        InOrder(root.left);
        lnode.Add(root.val);
        InOrder(root.right);
    }
    
    /** @return the next smallest number */
    public int Next() {
        return lnode[index++];
    }
    
    /** @return whether we have a next smallest number */
    public bool HasNext() {
        if(index>=lnode.Count) return false;
        else return true;
    }
}