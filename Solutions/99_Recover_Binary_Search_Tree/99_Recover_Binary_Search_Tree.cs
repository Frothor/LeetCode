//Third fastest
public class Solution {
    public void RecoverTree(TreeNode root) {
           TreeNode first = null, second = null, preNode = null;
            var current = root;
            if (current == null) return ;

            while (current != null)
            {
                if (current.left == null)
                {
                    if (preNode != null && preNode.val > current.val)
                    {
                        if (first == null) first = preNode;
                        second = current;
                    }

                    preNode = current;
                    current = current.right;
                }
                else
                {
                    var pre = current.left;
                    while (pre.right != null && pre.right != current)
                    {
                        pre = pre.right;
                    }

                    if (pre.right == null)
                    {
                        pre.right = current;
                        current = current.left;
                    }
                    else
                    {
                        pre.right = null;

                        if (preNode != null && preNode.val > current.val)
                        {
                            if (first == null) first = preNode;
                            second = current;
                        }

                        preNode = current;

                        current = current.right;
                    }
                }
            }

            var temp = first.val;
            first.val = second.val;
            second.val = temp;
    }
}

//Second fastest
public class Solution {
    TreeNode left;
    TreeNode right;
    public void RecoverTree(TreeNode root) {
        left = null;
        right = null;
        
        __recover(root, null);
        
        
        __swap(left, right);
    }
    
    private TreeNode __recover(TreeNode root, TreeNode pre) {
        if (null != root.left)
            pre = __recover(root.left, pre);
        
        if (null != pre && pre.val > root.val) {
            if (null == left) left = pre;
            right = root;
        }
        
        pre = root;
        
        if (null != root.right)
            pre = __recover(root.right, root);
        
        return pre;
    }
    
    private void __swap(TreeNode n1, TreeNode n2) {
        int tmp = n1.val;
        n1.val = n2.val;
        n2.val = tmp;
    }
}

//Fastest
public class Solution {
    TreeNode prev = null;
    TreeNode firstNode = null;
    TreeNode endNode = null;
    public void RecoverTree(TreeNode root) {
        
        if(root == null)
            return;
        
        Recurse(root);
        
        int temp = firstNode.val;
        firstNode.val = endNode.val;
        endNode.val = temp;
    }
    
    private void Recurse(TreeNode root)
    {

        if(root == null)
            return;
        Recurse(root.left);
        if(prev != null)
        {
            if(root.val < prev.val)
            {
                if(firstNode == null)
                    firstNode = prev;
                endNode = root;
            }
        }
        prev = root;
        Recurse(root.right);
        
    }
}