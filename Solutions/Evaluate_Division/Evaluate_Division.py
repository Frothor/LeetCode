#Second Fastest
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        if len(equations) == 0:
            return [-1.0 for i in range(len(queries))]
        if len(queries) == 0:
            return []
        
        self.dict1 = collections.defaultdict(dict)
        
        for i,equation in enumerate(equations):
            self.dict1[equation[0]][equation[1]] = values[i]
            self.dict1[equation[1]][equation[0]] = 1/values[i]
        self.result = []
        for query in queries:
            self.visited = set()
            temp = self.bfs(query[0],query[1],1)
            self.result.append(temp)
        
        return self.result
    
    def bfs(self,start,end,val):
        q = collections.deque()
        q.append((start,val))
        self.visited.add(start)
        if end not in self.dict1:
            return -1.0
        while q:
            s,val = q.popleft()
            if s not in self.dict1:
                return -1.0
            if s == end:
                return val  
            for news in self.dict1[s]:
                if news not in self.visited:
                    self.visited.add(news)
                    q.append((news,val*self.dict1[s][news]))
        return -1.0

#Fastest
from collections import defaultdict
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        result = [-1.0]*len(queries)
        # construct the graph
        graph = defaultdict(dict)
        for ind, (i, j) in enumerate(equations):
            graph[i][j]= values[ind]
            graph[j][i]= 1/values[ind]
            
        def helper(x, y):
            # find path from x to y, given a graph
            queue = [(x,1)]
            visited = set()
            while queue:
                node, val = queue.pop()
                if node in visited:
                    continue
                visited.add(node)
                neighbors = graph[node] # a dict {node:value}
                if y in neighbors:
                    return val*neighbors[y]
                else:
                    for n in neighbors:
                        queue.append((n, val*neighbors[n]))
                # queue = next_queue
            return -1.0
        
        for ind, (x, y) in enumerate(queries):
            if x not in graph or y not in graph:
                continue
            elif x==y and x in graph[x]:
                result[ind] = 1.0
            elif y in graph[x]:
                result[ind] = graph[x][y]
            else:
                # find the transition path
                # there maybe multiple paths, but since the assumption is there is no contradiction, it is safe to pick random one
                # depth first search, search neighbors and neighbors' neighbors until get the target
                
                result[ind] = helper(x, y)
        return result