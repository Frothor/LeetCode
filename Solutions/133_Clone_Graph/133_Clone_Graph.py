"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node):
        def dfs(node):
            mapping[node] = Node(node.val)
            for neigh in node.neighbors:
                if neigh not in mapping: dfs(neigh)
                mapping[node].neighbors += [mapping[neigh]]
        
        if not node: return node
        mapping  = {}
        dfs(node)
        return mapping[node]

#Third fastest
class Solution:
    def __init__(self):
        self.cache = {}
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        if node.val in self.cache:
            return self.cache[node.val]
        
        newNode = Node(node.val)
        self.cache[node.val] = newNode
        for neighbor in node.neighbors:
            newNode.neighbors.append(self.cloneGraph(neighbor))
        return newNode

#Second fastest
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        nodeMap = {}
        def cloneNode(node: 'Node'):
            newNode = Node(val = node.val, neighbors = [])
            nodeMap[node.val] = newNode
            
            for neigh in node.neighbors:
                if neigh.val in nodeMap:
                    newNode.neighbors.append(nodeMap[neigh.val])
                else:
                    newNode.neighbors.append(cloneNode(neigh))
            return newNode
            
        
        return None if node is None else cloneNode(node)

#Fastest
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return None
        
        new_nodes = dict()
        return self.dfs(node, new_nodes)
    
    
    def dfs(self, node, new_nodes: Dict) -> 'Node':
        # 'node' is always an 'old' node and not its copy (if it exists)
        if node.val in new_nodes:
            # node is already being cloned at upper levels of the recursion
            return new_nodes[node.val]
        
        # else this is our first encounter with the node
        new_neighbours = []
        new_node = Node(node.val, new_neighbours)
        new_nodes[node.val] = new_node
        
        for neighbour in node.neighbors:
            # recursively clone neighbour
            new_neighbour = self.dfs(neighbour, new_nodes)
            new_neighbours.append(new_neighbour)
            
        return new_node