public class Solution {
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        Dictionary<string, Dictionary<string, double>> lookup = new Dictionary<string, Dictionary<string, double>>();
        
        for(int i=0; i< equations.Count; i++)
        {
            if (!lookup.ContainsKey(equations[i][0]))
            {
                lookup[equations[i][0]] = new Dictionary<string, double>();
            }
            
            if (!lookup.ContainsKey(equations[i][1]))
            {
                lookup[equations[i][1]] = new Dictionary<string, double>();
            }
            
            lookup[equations[i][0]][equations[i][1]] = 1/values[i];
            lookup[equations[i][1]][equations[i][0]] = values[i];
        }
        
        
        double[] results = new double[queries.Count];
        HashSet<string> visited = new HashSet<string>();
        
        for(int i=0; i < queries.Count; i++)
        {
            results[i] = FindPath(queries[i][1], queries[i][0], lookup, visited); 
        }
        
        return results;
    }
   
    private double FindPath(string source, string target, Dictionary<string, Dictionary<string, double>> lookup, HashSet<string> visited)
    {
        if (!lookup.ContainsKey(source)) { return -1; }
        if (target == source) { return 1; }
        double crnt = -1;
        
        visited.Add(source);
        
        foreach(string d in lookup[source].Keys)
        {
           if (visited.Contains(d)) { continue; }         
           crnt = FindPath(d, target, lookup, visited);
           if (crnt != -1) { crnt *= lookup[source][d]; break; }
        }
        
       visited.Remove(source);
       return crnt;
    }
}

//Most common
public class Solution {
    
    public class DivisionNode
    {
        public string Variable { get; set; }
        public double Value { get; set; }

    }
    
    public class NextNode
    {
        public string Variable { get; set; }
        public double CurrentValue { get; set; }
    }
    
    
    
public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries)
        {
            var adjList = ConvertToAdjList(equations, values);

            var answers = new double[queries.Count];
            
            for(int i = 0; i<queries.Count; i++)
            {
                answers[i] = TraverseGraph(adjList, queries[i]);
            }   

            return answers;
        }

        public double TraverseGraph(IDictionary<string, IList<DivisionNode>> adjList, IList<string> queries)
        {
            if (queries[0] == queries[1] && adjList.ContainsKey(queries[0])) return 1;
            
            // Traverse the graph using BFS
            var visited = new HashSet<string>();
            var queue = new Queue<NextNode>();

            // First node
            queue.Enqueue(new NextNode
            {
                Variable = queries[0],
                CurrentValue = 1
            });

            while (queue.Count > 0)
            {
                var curNode = queue.Dequeue();
                visited.Add(curNode.Variable);

                // Add children to queue
                IList<DivisionNode> childrenList;
                if(adjList.TryGetValue(curNode.Variable, out childrenList))
                {
                    foreach (var n in childrenList)
                    {
                        if (visited.Contains(n.Variable)) continue;
                        var newNode = new NextNode
                        {
                            Variable = n.Variable,
                            CurrentValue = curNode.CurrentValue * n.Value
                        };

                        if (n.Variable == queries[1])
                        {
                            return newNode.CurrentValue;
                        }

                        queue.Enqueue(newNode);
                    }
                }
            }

            return -1.0;
        }


        public IDictionary<string, IList<DivisionNode>> ConvertToAdjList(IList<IList<string>> equations, double[] values)
        {
            var adjList = new Dictionary<string, IList<DivisionNode>>();

            for(int i=0; i<equations.Count; i++)
            {
                var first = equations[i][0];
                var second = equations[i][1];
                var value = values[i];

                var forwardNode = new DivisionNode
                {
                    Variable = second,
                    Value = value
                };

                var backwardNode = new DivisionNode
                {
                    Variable = first,
                    Value = 1/value
                };

                if (!adjList.ContainsKey(first))
                {
                    adjList.Add(first, new List<DivisionNode>() { forwardNode });
                }
                else
                {
                    adjList[first].Add(forwardNode);
                }

                if (!adjList.ContainsKey(second))
                {
                    adjList.Add(second, new List<DivisionNode>() { backwardNode });
                }
                else
                {
                    adjList[second].Add(backwardNode);
                }
            }

            return adjList;
        }
}

//Fastest
public class Solution {
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        Dictionary<string, Dictionary<string,double>> graph = new Dictionary<string,Dictionary<string,double>>();
        
        for(int i=0;i<equations.Count;i++)
        {
            var a = equations[i][0];
            var b = equations[i][1];
            var c = values[i];
            
            if(!graph.ContainsKey(a))
            {
                graph[a] = new Dictionary<string,double>();
            }
            if(!graph.ContainsKey(b))
            {
                graph[b] = new Dictionary<string,double>();
            }
            
            graph[a][b]=c;
            graph[b][a]=1.0/c;
            
        }
        var results = new double[queries.Count];
        
        for(int i=0;i<queries.Count;i++)
        {
            var a = queries[i][0];
            var b = queries[i][1];
            if(!graph.ContainsKey(a) || !graph.ContainsKey(b))
            {
                results[i]=-1.0;
            }
            else if(a==b)
            {
                results[i]=1.0;
            }
            else
            {
                var result = DFS(graph,a,b,1.0,new HashSet<string>());
                results[i]=result;
            }
        }
        
        return results;
    }
    
    double DFS(Dictionary<string,Dictionary<string,double>> graph, string current, string target, double product, HashSet<string> visitedNodes)
    {
        visitedNodes.Add(current);
        double retVal = -1.0;
        
        var candidates = graph[current];
        if(candidates.ContainsKey(target))
        {
            retVal = product * candidates[target];
        }
        else
        {
            foreach(var candidate in candidates)
            {
                if(visitedNodes.Contains(candidate.Key))
                    continue;
                retVal = DFS(graph, candidate.Key, target, product * candidate.Value, visitedNodes);
                if(retVal!=-1.0)
                    break;
            }
        }
        
        visitedNodes.Remove(current);
        return retVal;
        
    }
    
    
}