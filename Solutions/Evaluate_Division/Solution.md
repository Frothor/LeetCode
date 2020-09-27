# LeetCode Evaluate Division
## [Python] dfs O(V+E), explained

First of all, if we look carefully at this problem we can see, that it is graph problem: let our variables be nodes and divistions be connections. It is also given, that there is no contradictions in this graph and divisions by zero, so we do not need to think about it. Let us use `dfs(start, comp, w)` function, with parameters:

1. `start` is current node(variable) we visit
2. `comp` number of connected component: imagine we have `x/y = 4`, `y/z = 3` and `a/b = 2`, then first component is `(x,y)` and second is `(a,b)`.
3. `w` is current weight or value of our node: imagine that we start with node `x`, then we have weight for `x = 1`, weight for ` = 1/4` and weight for `z = 1/12`.

So, what `dfs` function will do? for given `start` value it traverse our graph and check if `self.w[j][0] = -1`. We define `for var in varbs: self.w[var] = [-1,-1]` in the beginning: first value is responsible for number of connected component and second number is responsible for weight. So, if we have neighbour, which is not visited yet, we run `dfs` recursively.

Main function: first we grab the names of all variables (nodes), using `varbs = set(chain(*equations))`, then we create defaultdict of edges: for every equation we add two connections: one for direct and one for inversed. Next we iterate over all variables and run `dfs` if this variable(node) is not visited yet.
Finally, we traverse `queries` and we found that one of the variables is not in `varbs` or they both are, but they are in two different connected components, we return `-1`. If it is not the case, we return division of weights.

**Complexity:** Time complexity is `O(E+V+Q)`, where `V` is number of variables (nodes), `E` is number of equations (edges) and `Q` is number of queries, because complexity of dfs is `O(E+V)` and we also have `Q` queries. Space complexity is also `O(E+V+Q)` to keep all nodes, edges and answers for queries.

```python
class Solution:
    def dfs(self, start, comp, w):
        self.w[start] = [comp, w]
        for j, weight in self.edges[start]:
            if self.w[j][0] == -1:
                self.dfs(j, comp, w/weight)
      
    def calcEquation(self, equations, values, queries):
        varbs = set(chain(*equations))
        result, it = [], 0
        self.edges = defaultdict(list)
        for it, [i,j] in enumerate(equations):
            self.edges[i].append([j, values[it]])
            self.edges[j].append([i, 1/values[it]])
            
        self.w = defaultdict(list)
        for var in varbs: self.w[var] = [-1,-1]
            
        for key in varbs:
            if self.w[key][0] == -1:
                self.dfs(key, it, 1)
                it += 1
                
        for a,b in queries:
            if a not in varbs or b not in varbs or self.w[a][0] != self.w[b][0]:
                result.append(-1.0)
            else:
                result.append(self.w[a][1]/self.w[b][1])
                
        return result
```

[Link to original post](https://leetcode.com/problems/evaluate-division/discuss/867030/Python-dfs-O(V%2BE)-explained)