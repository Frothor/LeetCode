//Most common
public class Solution {
    public IList<int> FindMinHeightTrees(int n, int[][] edges) {
            if (n <= 0) return new List<int>();
            if (n == 1 || edges == null || edges.Length == 0) return new List<int>() { 0};
            IList<int> res = new List<int>();
            Queue<int> q = new Queue<int>();
            IList<IList<int>> adjacency = new List<IList<int>>();
                    for (int i = 0; i < n; i++)
            {
                adjacency.Add(new List<int>());
            }
            foreach (int[] edge in edges)
            {
                adjacency[edge[0]].Add(edge[1]);
                adjacency[edge[1]].Add(edge[0]);
            }
            for (int i = 0; i < n; i++)
            {
                if (adjacency[i].Count == 1) q.Enqueue(i);
            }
            while (n > 2)
            {
                int size = q.Count;
                n -= size;
                for (int i = 0; i < size; i++)
                {
                    int cur = q.Dequeue();
                    foreach (int adj in adjacency[cur])
                    { 
                        adjacency[adj].Remove(cur);
                        if (adjacency[adj].Count == 1) q.Enqueue(adj);
                    }                    
                }
            }
            while (q.Count != 0)
            {
                res.Add(q.Dequeue());
            }
            return res;        
    }
}

//Third fastest
public class ResultSet{
    public int Index;
    public int Height;
}

public class Solution {
    public IList<int> FindMinHeightTrees(int n, int[][] edges) {
        Dictionary<int, List<int>> graph = new Dictionary<int, List<int>>();
        
        int anyEdge = -1;
        for(int i = 0; i < edges.Length; i++)
        {
            int edge1 = edges[i][0];
            int edge2 = edges[i][1];
            anyEdge = edge1;
            
            if(graph.ContainsKey(edge1))
            {
                graph[edge1].Add(edge2);
            }
            else
            {
                graph.Add(edge1, new List<int>() { edge2 });
            }
            
            if(graph.ContainsKey(edge2))
            {
                graph[edge2].Add(edge1);
            }
            else
            {
                graph.Add(edge2, new List<int> (){ edge1 });
            }
        }
        
        List<int> leafNode = new List<int>();
        foreach(var item in graph)
        {
            if(item.Value.Count == 1)
                leafNode.Add(item.Key);
        }
        int remainingNode = n;
        
        while(remainingNode > 2)
        {
            List<int> newLeafNodes = new List<int>();

            for(int i = 0; i < leafNode.Count; i++)
            {
                var node = leafNode[i];
                var neighbours = graph[node];
                
                for(int j = 0; j < neighbours.Count; j++)
                {
                    graph[neighbours[j]].Remove(node);
                    if(graph[neighbours[j]].Count == 1)
                        newLeafNodes.Add(neighbours[j]);
                }
            }
            
            remainingNode -= leafNode.Count;                
            leafNode = new List<int>(newLeafNodes);
        }
        
        if(leafNode == null || leafNode.Count == 0)
        {
            leafNode.Add(0);
        }
        
        return leafNode;
    }
    
}

//Second fastest
public class Solution {
    public class Node {
        public int val;
        public List<Node> adj;
        public int deg;
        public Node(int _val){
            val = _val;
            adj = new List<Node>();
            deg = 0;
        }
    }
    
    public IList<int> FindMinHeightTrees(int n, int[][] edges) {
        
        if(n == 0) {
            return new List<int>();
        }
        
        if(n == 1) {
            return new List<int>(){0};
        }
        
        var nodes = BuildAdjList(n, edges);
        
        var q = new Queue<Node>();
        
        foreach(var node in nodes) {
            if(node.deg == 1) {
                --node.deg;
                q.Enqueue(node);
            }
        }
        
        return MoveToCenter(q, n);
        
    }
    
    public List<int> MoveToCenter(Queue<Node> q, int eleCnt){
        
        
        while(eleCnt > 2) {
            var count = q.Count;
            for(int i = 0; i < count; i++){
                Node n = q.Dequeue();
                eleCnt--;
                foreach(var node in n.adj) {
                    if(--node.deg == 1) {
                        --node.deg;
                        q.Enqueue(node);
                    }
                }
            }
        }
        
        return q.Select((e) => e.val).ToList();
        
    }
    
    public Node[] BuildAdjList(int n, int[][] edges){
        var nodes = new Node[n];
        for(int i = 0; i < edges.Length; i++){
            Node node1 = null, node2 = null;
            if((node1 = nodes[edges[i][0]]) == null) {
                node1 = new Node(edges[i][0]);
                nodes[edges[i][0]] = node1;
            }
            
            if((node2 = nodes[edges[i][1]]) == null) {
                node2 = new Node(edges[i][1]);
                nodes[edges[i][1]] = node2;
            }
            
            node1.adj.Add(node2);
            node1.deg++;
            
            node2.adj.Add(node1);
            node2.deg++;
        }
        
        return nodes;
    }
}

//Fastest
public class Solution {
    public IList<int> FindMinHeightTrees(int n, int[][] edges) {
            if(n < 2)
            {
                var result = new List<int>();
                for(var i = 0; i < n; i++)
                {
                    result.Add(i);
                }

                return result;
            }

            var neighbours = new List<int>[n];
            for(var i=0; i< n;i++)
            {
                neighbours[i] = new List<int>();
            }

            foreach(var edge in edges) {
                var start = edge[0];
                var end = edge[1];
                neighbours[start].Add(end);
                neighbours[end].Add(start);
            }

            var leaves = new List<int>();
            for (var i = 0; i < n; i++)
            {
                if(neighbours[i].Count == 1)
                {
                    leaves.Add(i);
                }
            }

            int remainingNodes = n;
            while(remainingNodes > 2)
            {
                remainingNodes = remainingNodes - leaves.Count;
                var newLeaves = new List<int>();
                foreach (var leaf in leaves)
                {
                    var toremoveFrom = neighbours[leaf];
                    foreach(var node in toremoveFrom)
                    {
                        neighbours[node].Remove(leaf);
                        if(neighbours[node].Count == 1)
                        {
                            newLeaves.Add(node);
                        }
                    }
                }

                leaves = newLeaves;
            }

            return leaves;
        }
}