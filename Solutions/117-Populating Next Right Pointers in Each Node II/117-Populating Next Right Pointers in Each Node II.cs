//Third fastest
public class Solution {
    public Node Connect(Node root) {
        Node cur = root;
        if(root==null) return null;
        Queue<Node> q = new Queue<Node>();
        q.Enqueue(cur);
        int count=0;
        while(q.Count>0)
        {
            count = q.Count;
            Node temp=null, prev=null;
            for(int i=0;i<count;i++)
            {
                temp = q.Dequeue();
                if(prev!=null) prev.next = temp;
                if(temp.left!=null) q.Enqueue(temp.left);
                if(temp.right!=null) q.Enqueue(temp.right);
                prev = temp;
            }
            temp.next = null;
        }
        return root;
    }
}

//Second fastest
public class Solution {
    public Node prev;
    public Node l;
    
    public Node Connect1(Node root) {
        if(root == null)
            return root;
        
        this.l = root;
        Node p = l;
        while(this.l != null)
        {
            p = this.l;
            this.l = null;
            this.prev = null;
            while(p != null)
            {   
                ProcessChild(p.left);
                ProcessChild(p.right); 
                p = p.next;
            } 
        }
        
        return root;
    }
    public void ProcessChild(Node childNode)
    {
        if(childNode != null)
        {    
            if(this.prev != null)
            {
                this.prev.next = childNode;
            }
            else
            {
                this.l = childNode;
            }
            this.prev = childNode;
        }
    }
    
    
    
    public Node Connect(Node root)
    {
        if(root == null)
            return null;
        
        // Queue
        Queue<Node> q = new Queue<Node>();
        
        q.Enqueue(root); 
        while(q.Count > 0)
        {
            int size = q.Count();
            
            for(var i = 0; i < size; i++)
            {   
                Node c = q.Dequeue();
                
                if(i < size - 1)
                    c.next = q.Peek();
                
                if(c.left != null)
                    q.Enqueue(c.left);
                if(c.right != null)
                    q.Enqueue(c.right);
            }
        }
        return root;
    }
        
    
}

//Fastest
public class Solution {
    public Node Connect(Node root) {
        var first = root;
        while (first != null)
        {
            var current = first;
            Node prevChild = null;
            Node firstChild = null;
            while (current != null)
            {
                // Need to take care both left and right
                if (current.left != null)
                {
                    if (prevChild != null)
                    {
                        prevChild.next = current.left;
                    }
                    if (current.right == null)
                    {
                        prevChild = current.left;
                    }
                    else
                    {
                        current.left.next = current.right;
                        prevChild = current.right;
                    }
                    if (firstChild == null)
                    {
                        firstChild = current.left;
                    }                             
                }
                else if (current.right != null)
                {
                    if (prevChild != null)
                    {
                        prevChild.next = current.right;
                    }
                    prevChild = current.right;
                    if (firstChild == null)
                    {
                        firstChild = current.right;
                    }                                        
                }
                current = current.next;
            }
            first = firstChild;
        }
        return root;
    }
}