//Most common
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
*/

public class Solution {
    public Node Connect(Node root) {
        if(root == null)
            return null;
        var q = new Queue<Node>();
        q.Enqueue(root);
        while(q.Count != 0){
            int n = q.Count;
            for(int i=0; i<n; i++){
                var cur = q.Dequeue();
                if(i == n-1)
                    cur.next = null;
                else
                    cur.next = q.Peek();
                if(cur.left != null)
                    q.Enqueue(cur.left);
                if(cur.right != null)
                    q.Enqueue(cur.right);
            }
        }
        return root;
    }
}

//Another
public class Solution {
    public Node Connect(Node root) {
        if(root == null)
            return null;
        
        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(root);
        
        while(queue.Count > 0){
            int cnt = queue.Count;                
                for(int i = 0; i < cnt; i++){
                Node curr = queue.Dequeue();
                    if(i< cnt-1)
                        curr.next = queue.Peek();
                if(curr.left != null)
                    queue.Enqueue(curr.left);
                if(curr.right != null)
                    queue.Enqueue(curr.right);
            }
        }
        
        return root;
    }
}

//Third fastest
public class Solution {
    public Node Connect(Node root) {

        if(root == null)
            return root;
        
        var p1 = root;
        Node p2;
        
        
        while(p1.left != null)
        {
            p1.left.next = p1.right;
            p2 = p1;
            while(p2 != null)
            {
                // connect left and right
                p2.left.next = p2.right;
                
                if(p2.next != null)
                {
                    p2.right.next = p2.next.left;
                }
                p2 = p2.next;
            }
            p1 = p1.left;
        }
        
        return root;
    }
}

//Second fastest
public class Solution {
  public Node Connect(Node root) {
      
      if(root == null) return root;
      var q = new Queue<Node>();

      q.Enqueue(root);

      while(q.Count != 0)
      {

        Node prev = null;
        Node cur = null;
        int level = q.Count;
        for(int i = 1; i<= level; i++)
        {
          cur = q.Dequeue();
          if(cur.left != null) q.Enqueue(cur.left);
          if(cur.right != null) q.Enqueue(cur.right);


          if(prev != null)
          {
            prev.next = cur;
          }
          
          if(i == level) {
            cur.next = null;
            break;
          } 

          prev = cur;
        }
      }

      return root;
  }
}

//Fastest
public class Solution {
    public Node Connect(Node root) {
        var leftNode = root;
        while(leftNode!=null && leftNode.left!=null) {
            PopulateNode(leftNode);
            leftNode = leftNode.left;
        }
        return root;
    }
    private void PopulateNode(Node selectedNode) {
        var currentNode  = selectedNode;
        while(currentNode!=null) {
            currentNode.left.next = currentNode.right;
            if(currentNode.next!=null)
                currentNode.right.next = currentNode.next.left;
            currentNode = currentNode.next;
        }
    }
}