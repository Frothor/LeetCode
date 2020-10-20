/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }
    
    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution
{
    public Node CloneGraph(Node node)
    {
        return CloneRecursive(node, new Node[101]);
    }
    
    private Node CloneRecursive(Node node, Node[] clonedCache)
    {
        if(node is null) return null;
        if(clonedCache[node.val] != null) return clonedCache[node.val];
        Node cloned = clonedCache[node.val] = new Node(node.val);
        cloned.neighbors = node.neighbors.Select(x => CloneRecursive(x, clonedCache)).ToList();
        return cloned;
    }
}

//Third fastest
public class Solution {
    Dictionary<Node, Node> visited = new Dictionary<Node, Node>();
    
    public Node CloneGraph(Node node) {
        if (node == null) return node;
        
        if (visited.ContainsKey(node))
            return visited[node];
      
        
        var clonedNode = new Node(node.val, new List<Node>());
    
        visited.Add(node, clonedNode);
        foreach(var n in  node.neighbors)
        {
             clonedNode.neighbors.Add(CloneGraph(n));
        }
        
       
        return clonedNode;
    }
}

//Second fastest
public class Solution {
    
    Dictionary<int, Node> visited = new Dictionary<int, Node>();
    
    public Node CloneGraph(Node node) {
        if (node == null)
            return null;
        
        Node result = new Node(node.val, new List<Node>{});
        visited.Add(result.val, result);
        
        foreach(Node neighbor in node.neighbors) {
            if (visited.ContainsKey(neighbor.val))
                result.neighbors.Add(visited[neighbor.val]);
            else
                result.neighbors.Add(CloneGraph(neighbor));
        }
        
        return result;
    }
}

//Fastest
public class Solution {
    public Node CloneGraph(Node node) {
        if(node==null) return null;
        Dictionary<Node,Node> dict=new Dictionary<Node,Node>();        
        Queue<Node> queue=new Queue<Node>();
        HashSet<int> visited=new HashSet<int>();
        
        queue.Enqueue(node);
        visited.Add(node.val);
        
        while(queue.Count>0)
        {
            Node cur=queue.Dequeue();
            Node temp=new Node(cur.val);
            
            dict.Add(cur,temp);
            
            foreach(var item in cur.neighbors)
            {
                if(!visited.Contains(item.val))
                {
                    queue.Enqueue(item);
                    visited.Add(item.val);
                }
            }
        }
         foreach (var item in dict.Keys)
            foreach (var nei in item.neighbors)
                dict[item].neighbors.Add(dict[nei]);
        
        return dict[node];
        
    }
}