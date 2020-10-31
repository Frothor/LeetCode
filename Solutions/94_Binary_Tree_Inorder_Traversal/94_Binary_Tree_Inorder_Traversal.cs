//Morris inorder
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
    public IList<int> InorderTraversal(TreeNode root) {
        var result = new List<int>();
        
        TreeNode cur = root;
        
        while(cur != null){
            if(cur.left != null){
                TreeNode temp = cur.left;
                TreeNode nxtcur = cur.left;
                while(temp.right != null)
                    temp = temp.right;
                temp.right = cur;
                cur.left = null;
                cur = nxtcur;
            }
            else {
                result.Add(cur.val);
                cur = cur.right;
            }
        }
        
        return result;
    }
}

//Third fastest
public class Solution {
    
    
    public IList<int> InorderTraversal(TreeNode root) {
      List<int> result = new List<int>();
        
      Stack<TreeNode> nodes = new Stack<TreeNode>();
      TreeNode current = root;
        
      while(current != null || nodes.Count > 0)
      {
          while(current != null)
          {
              nodes.Push(current);
              current = current.left;
          }
          
          var node = nodes.Pop();
          result.Add(node.val);
          
          current = node.right;
      }
      
      return result;
    }
}

//Second fastest
public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        var resultList = new List<int>();
        
        if(root == null)
            return resultList;
        
        if(root.left == null && root.right == null){
            resultList.Add(root.val);
            return resultList;
        }
            
        var inOrderStack = new Stack<TreeNode>();
        inOrderStack.Push(root);
        
        while(inOrderStack.Count != 0 && root != null){
            root = inOrderStack.Pop();
            
            while(root.left != null){
                inOrderStack.Push(root);
                root = root.left;
            } 
            
            resultList.Add(root.val);
            
            while(root.right == null && inOrderStack.Count != 0){
                root = inOrderStack.Pop();
                resultList.Add(root.val);
            }
            
            if(root.right != null){
                inOrderStack.Push(root.right);
            }
        }
        
        return resultList;
    }
}

//Fastest
public class Solution {
    //iterative approach (maintain explicit stack)
    //values are not unique so we will use dictionary
    public IList<int> InorderTraversal(TreeNode root) {
        
        List<int> visited = new List<int>();
        HashSet<TreeNode> visitedNodes = new HashSet<TreeNode>();
        
        if(root == null)
            return visited;
        
        Stack<TreeNode> toVisit = new Stack<TreeNode>();
        
        toVisit.Push(root);
                
        while(toVisit.Count != 0)
        {
            var node = toVisit.Pop();
            if(node.left != null && visitedNodes.Add(node.left))
            {
                toVisit.Push(node);
                toVisit.Push(node.left);
            }
            else
            {
                visited.Add(node.val);
                visitedNodes.Add(node);
                if(node.right != null)
                {
                    toVisit.Push(node.right);
                    
                }                
            }
            
        }

        
        return visited;
    }
}