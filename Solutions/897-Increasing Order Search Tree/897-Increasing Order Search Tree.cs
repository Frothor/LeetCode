//Third fastest
public class Solution {
    private Queue<TreeNode> q = new Queue<TreeNode>();

    private void InOrderTraversal(TreeNode root){
        if(root != null){
            InOrderTraversal(root.left);
            Console.WriteLine(root.val);
            q.Enqueue(new TreeNode(root.val));
            InOrderTraversal(root.right);
        }
    }
    public TreeNode IncreasingBST(TreeNode root) {
        if(root == null)
            return root;
       
        InOrderTraversal(root);
        var newRoot = q.Dequeue();
        var curr = newRoot;
        while(q.Count >0){
            curr.right = q.Dequeue();
            curr = curr.right;
        }
        return newRoot;
    }
}

//Another
public class Solution {
    public TreeNode IncreasingBST(TreeNode root) {
       if (root == null || (root.left == null && root.right == null))
                return root;
            TreeNode temp = root;
            Stack<TreeNode> stack = new Stack<TreeNode>();
            while (temp != null)
            {
                stack.Push(temp);
                temp = temp.left;
            }
            TreeNode tempRoot = stack.Peek();
            tempRoot.left = null;
            TreeNode prev = null;
            while (stack.Count > 0)
            {
                TreeNode t = stack.Pop();
                t.left = null;
                if (prev == null)
                {
                    prev = tempRoot;
                }
                else
                {
                    prev.right = t;
                    prev = prev.right;
                }
                if (t.right != null)
                {
                    stack.Push(t.right);
                    TreeNode tt = t.right.left;
                    while (tt != null)
                    {
                        stack.Push(tt);
                        tt = tt.left;
                    }

                }

            }
            return tempRoot;
    }
    
}

//Second fastest
public class Solution {
    public TreeNode IncreasingBST(TreeNode root) {
        
        List<TreeNode> inorder = new List<TreeNode>();
        InOrder(root, inorder);        
       
        //first element of the list is root
        TreeNode newroot = new TreeNode (inorder[0].val);
        //inorder.Remove(inorder[0]);
        
        TreeNode currentroot = newroot;
        
        for(int i = 1; i< inorder.Count; i++)
        {
            TreeNode rightnode  = new TreeNode (inorder[i].val);
            currentroot.right = rightnode;
            currentroot.left = null;
            currentroot = rightnode;
        }
        
        return newroot;
        
    }
    
    public void InOrder(TreeNode root, List<TreeNode> inorder)
    {
        
        if(root == null)
            return;
        
        InOrder(root.left, inorder);
        
        inorder.Add(root);
        
        InOrder(root.right,inorder);
        
    }
}

//Fastest
public class Solution {
    public TreeNode IncreasingBST(TreeNode root) {
        if (root == null) return null;
        
        var table = new List<int>();
        Inorder(root, table);
        
        TreeNode newRoot = new TreeNode(table[0]);
        TreeNode currentNode = newRoot;
        for(int i = 1; i < table.Count(); i++){
            currentNode.right = new TreeNode(table[i]);
            currentNode = currentNode.right;
        }
        
        return newRoot;
    }
    
    private void Inorder(TreeNode root, List<int> table){
        if (root == null) return;
        
        Inorder(root.left, table);
        table.Add(root.val);
        Inorder(root.right, table);
    }
}