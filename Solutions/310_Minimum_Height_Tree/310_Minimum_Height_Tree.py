#Most common
from collections import defaultdict 

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n ==1:
            return [0]
        adjList = defaultdict(set)
        
        for i in edges:
            adjList[i[0]].add(i[1])
            adjList[i[1]].add(i[0])
        countLeaves = 0
        leaves = []
        
        for k, v in adjList.items():
            if len(v) == 1:
                countLeaves += 1
                leaves.append(k)
        
        while n > 2:
            n -= countLeaves
            countLeaves = 0
            nextleaves = []
            for leaf in leaves:
                for key in adjList[leaf]:
                    adjList[key].remove(leaf)
                    if len(adjList[key]) == 1:
                        countLeaves += 1
                        nextleaves.append(key)
            leaves = nextleaves
            
        return leaves

#Third fastest
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        
        if n<2:
            return [0]
        
        adj = collections.defaultdict(set)
        for a, b in edges:
            adj[a].add(b)
            adj[b].add(a)
            
            
        # initialize with leaves
        leaves = collections.deque()
        for i in range(n):
            if len(adj[i]) == 1:
                leaves.append(i)
                
        num_nonleaf = n 
        
        while num_nonleaf > 2:
            num_nonleaf -= len(leaves)
            
            new_leaves = collections.deque()
            
            while leaves:
                leaf = leaves.popleft()
                for nei in adj[leaf]:
                    adj[nei].remove(leaf)
                    
                    if len(adj[nei]) == 1:
                        new_leaves.append(nei)
              
            leaves = new_leaves

            
        
        return leaves
                    
            
            
        
            
            
            
#         nodes = set(range(n))
#         while len(nodes) > 2:            
            
#             # find leaves 
#             leaves = set([ node for node in nodes if len(adj[node]) == 1])
            
#             # remove leaves
#             nodes -= leaves
#             for n in nodes:
#                 #adj[n] -= leaves
#                 adj[n] = adj[n].difference(leaves)
                
#         return list(nodes)
                
                
                


#Second fastest
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:return [0]
        adj = [set() for _ in range(n)]
        for i, j in edges:
            adj[i].add(j)
            adj[j].add(i)
        leaves = [i for i in range(n) if len(adj[i]) == 1]
        while n > 2:
            n -= len(leaves)
            new_leaves = []
            for i in leaves:
                j = adj[i].pop()
                adj[j].remove(i)
                if len(adj[j]) == 1:
                    new_leaves.append(j)
            leaves = new_leaves
        return leaves

#Fastest
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:        
        graph = {i: [] for i in range(n)}
        
        if n == 1:
            return [0]
        
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
            
        leaves = []
        for node in graph:
            if len(graph[node]) == 1:
                leaves.append(node)
        
        while n > 2:
            l = len(leaves)
            n -= l
            new_leaves = []
            for leaf in leaves:
                neighbor = graph[leaf][0]
                graph[neighbor].remove(leaf)
                if len(graph[neighbor]) == 1:
                    new_leaves.append(neighbor)
            leaves = new_leaves
        return leaves
                
                
        
#         def bfs_height(node):
#             queue = [node]
#             level = -1
#             visited = [0] * n
#             visited[node] = 1
#             while queue:
#                 level += 1
#                 to_add = []
#                 for node in queue:
#                     for child in graph[node]:
#                         if visited[child] != 1:
#                             to_add.append(child)
#                             visited[child] = 1
#                 queue = to_add    
#             return level
        
#         min_h = float('inf')
#         res = []
#         for i in range(n):
#             h = bfs_height(i)
#             if h < min_h:
#                 res = [i]
#                 min_h = h
#             elif h == min_h:
#                 res.append(i)
#         return res
            
                
