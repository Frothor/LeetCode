class BSTIterator:
    def __init__(self, root):
        self.stack = []
        self.curr = root
        
    def next(self):
        while self.curr:
            self.stack.append(self.curr)
            self.curr = self.curr.left
        self.curr = self.stack.pop()
        out = self.curr.val
        self.curr = self.curr.right
        return out

    def hasNext(self):
        return self.stack or self.curr

#Third fastest
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.inOrder(root)
        
    def inOrder(self, root):
        if(root.right):
            self.inOrder(root.right)
        self.stack.append(root)
        if(root.left):
            self.inOrder(root.left)     
        
    def next(self) -> int:     
        while(self.hasNext()):
            return self.stack.pop().val


    def hasNext(self) -> bool:
        return len(self.stack) > 0

#Second fastest
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.st = []
        self.push_left(root)
    
    
    def push_left(self, node):
        cur = node
        while cur is not None:
            self.st.append(cur)
            cur = cur.left
        

    def next(self) -> int:
        top = self.st.pop()
        self.push_left(top.right)
        return top.val
        

    def hasNext(self) -> bool:
        return len(self.st) > 0

#Fastest
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.s = []
        
        while root:
            self.s.append(root)
            root = root.left

    def next(self) -> int:
        
        itm = self.s.pop()
        
        nxt = itm.right
        
        while nxt:
            self.s.append(nxt)
            nxt = nxt.left
            
        return itm.val
        
    def hasNext(self) -> bool:
        return len(self.s) > 0