#BFS
#https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/961834/Python3-simple-BFS-using-deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        queue = deque([root])
        while queue:
            level = len(queue)                         # count the node in current level
            pre = None
            while level:                               # pop the remain nodes in the same level
                cur = queue.popleft()
                level -= 1
                if cur.left: queue.append(cur.left);
                if cur.right: queue.append(cur.right);
                if pre: pre.next = cur
                pre = cur
            pre.next = None
        return root

#Third fastest
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return
        q=collections.deque([root])
        level=collections.deque([])
        while q:
            # level=[]
            node=q.popleft()
            if node.left:
                level.append(node.left)
            if node.right:
                level.append(node.right)
            
            if q:
                node.next=q[0]
            if not q:
                q,level=level,q
        return root


#Second fastest
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        Q = deque([root])
        
        while Q:
            size = len(Q)
            
            for i in range(size):
                node = Q.popleft()
                if i < size - 1:
                    node.next = Q[0]
                
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)

                node = node.next 
        return root

#Fastest
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        
        queue = collections.deque()
        queue.append(root)
        while queue:
            length = len(queue)
            pre = None
            for _ in range(length):
                node = queue.popleft()
                if pre is not None:
                    pre.next = node
                pre = node
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
                    
        return root