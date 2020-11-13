"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root or not root.left: return root
        
        self.connect(root.left)
        self.connect(root.right)
        
        lft = root.left
        rgh = root.right
        lft.next = rgh

        while lft.right: 
            lft = lft.right
            rgh = rgh.left
            lft.next = rgh
        
        return root

#Fourth fastest
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:return None
        leftmost = root
        while leftmost.left:
            cur = leftmost
            
            while cur:
                if cur.left:
                    cur.left.next = cur.right
                
                if cur.next:
                    cur.right.next = cur.next.left
                    
                cur = cur.next
            leftmost = leftmost.left
            
        return root

#Third fastest
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        def dfs(root:'Node') -> None:
            if not root or not root.left:
                return
            else:
                upper_ptr = root
                while upper_ptr:
                    upper_ptr.left.next = upper_ptr.right
                    if upper_ptr.next:
                        upper_ptr.right.next = upper_ptr.next.left
                    upper_ptr = upper_ptr.next
                dfs(root.left)
        
        dfs(root)
        return root

#Second fastest
# class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root 
                
        leftmost = root
        
        while leftmost.left:
            head = leftmost
            
            while head:
                head.left.next = head.right
                
                if head.next:
                    head.right.next = head.next.left
                
                head = head.next
            leftmost = leftmost.left
                
        return root
        
'''
O(n) time and O(1) space
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root 
                
        leftmost = root
        
        while leftmost.left:
            head = leftmost
            
            while head:
                if head.left:
                    head.left.next = head.right
                
                if head.right and head.next:
                    head.right.next = head.next.left
                
                head = head.next
            leftmost = leftmost.left
                
        return root
        
        
        

O(n) timem= and space
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
                
        q = deque()
        q.append(root)
        
        while q:
            levelsize = len(q)
            for i in range(levelsize):
                n = q.popleft()
                
                if i < levelsize - 1:
                    n.next = q[0]
                
                if n.left:  q.append(n.left)
                if n.right: q.append(n.right)
            
                
        return root



O(n + nlogn time and space) nlogn factor is bcz of extra # for each level
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
                
        q = deque()
        q.append(root)
        q.append("x")
        
        while q:
            # print("qlen",len(q))
            n = q.popleft()
            # print(n)
            if n == "x":
                # print("x")
                if q:
                    q.append("x")
            else:
                # print(n.val)
                if n.left:  
                    # print("n.left", n.left.val)
                    if q and q[-1] != "x":
                        q[-1].next = n.left
                        # print(q[-1].val, "->", q[-1].next.val)
                    q.append(n.left)
                if n.right:
                    # print("n.right", n.right.val)
                    q.append(n.right)
                    if n.left: 
                        n.left.next = n.right
                        # print(n.left.val, "->", n.left.next.val)
            # print("qlen",len(q))
            
                
        return root
        
'''        

#Fastest
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        ret = root # save variable to return
        
        while root and root.left: # while we are not at the end of the tree
            next = root.left # the next node is the left node
            while root: # while we are not at the end
                root.left.next = root.right # the left root will point to the right root
                if root.next: # if there is a root still 
                    root.right.next = root.next.left # the next one of the right one is the next one of the left
                else: 
                    root.right.next = None # otherwise we are at the rightmost roots so set to None
                root = root.next  # go to the next root
            root = next 
            
        return ret