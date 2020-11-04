#This (O(V+E) | O(V)) is not the best implementation available out there, but I've learned 3 new problems today in graph theory through this problem. Thought to share with others, hope someone finds them useful and something new...

#{Although the solution using Centroid Finding is more efficient in terms of total number of operations performed}

def bfs(graph, src):
	"""Just a bfs traversal from src to other vertices, nothing fancy here"""
    dist = [-1]*len(graph)
    dist[src] = 0
    deq = deque()
    deq.append(src)
    while deq:
        curr = deq.popleft()
        for node in graph[curr]:
            if dist[node] == -1:
                dist[node] = dist[curr] + 1
                deq.append(node)
    return dist
        

def get_farthest_distance_from_each_node(graph):
    """
    Theory/Prerequsite before solving this problem:
        1) In any Connected Undi.Graph, two longest paths will always have a common vertex.
            So there can be only one longest path in such Graph.
        2) How to "Find longest Path Between Any Two Nodes In an Unidirected Graph(Diameter)."
        3) Using (2), "Find farthest Node From Each Node in Undirected Tree."
    
    Ans2 => Do BFS from any vertex and find the farthest node from it. That node must
            be one end of the Diameter of Tree.(See Proof elsewhere) From that End1, 
            find the other farthest node "End2" of diameter. 
    
    Ans3 => Farthest node from every node will always be one of the two ends of diameter.(See Proof elsewhere)
    
    # let End1, End2 be the two ends of the diameter of graph
    
    TimeComplexity: O(V+E)
    SpaceComplexity: O(V)
    """
    
    dist = bfs(graph, 0) # do bfs from any vertex(here 0) to find End1
    End1 = max(range(len(graph)), key = lambda x: dist[x])
    
    dist_from_end1 = bfs(graph, End1) # distance of every node from End1
    End2 = max(range(len(graph)), key = lambda x: dist_from_end1[x])
    
    dist_from_end2 = bfs(graph, End2) # distance of every node from End2
    
    # Finding farthest node from every node in graph
    distance = [0]*len(graph)
    for i in range(len(graph)):
        distance[i] = max(dist_from_end1[i], dist_from_end2[i])
    
    return distance    
    

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = [[] for node in range(n)]
        for src, dest in edges:
            graph[src].append(dest)
            graph[dest].append(src)
        
        distance = get_farthest_distance_from_each_node(graph)
        mini_height = min(distance)
        
        return [node for node in range(len(distance)) if distance[node] == mini_height]