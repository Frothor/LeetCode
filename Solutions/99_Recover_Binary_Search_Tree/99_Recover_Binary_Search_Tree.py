class Solution:
    def recoverTree(self, root):
        cur, node, cands = root, TreeNode(-float("inf")), []
        while cur:
            if cur.left:
                pre = cur.left
                while pre.right and pre.right != cur:
                    pre = pre.right
                if not pre.right:
                    pre.right = cur
                    cur = cur.left
                else:
                    pre.right = None
                    if cur.val < node.val:
                        cands += [node, cur]
                    node = cur
                    cur = cur.right
            else:
                if cur.val < node.val:
                    cands += [node, cur]
                node = cur
                cur = cur.right
            
        cands[0].val, cands[-1].val = cands[-1].val, cands[0].val

#Third fastest
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def find_two_swaped(root):
            nonlocal x, y, prev
            if root is None:
                return 
            find_two_swaped(root.left)
            if prev and root.val < prev.val:
                y = root
                if x is None:
                    x = prev
                else:
                    return
            prev = root
            find_two_swaped(root.right)
        x = y = prev = None
        find_two_swaped(root)
        x.val, y.val = y.val, x.val


#Second fastest
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        x = y = prev = pred = None
        while root:
            if root.left:
                prev = root.left
                while prev.right and prev.right!=root:
                    prev = prev.right
                if prev.right == None:
                    prev.right = root
                    root = root.left
                else:
                    if pred and root.val < pred.val:
                        y = root
                        if x == None:
                            x = pred
                    pred = root
                    prev.right = None
                    root = root.right
            else:
                if pred and root.val<pred.val:
                    y = root
                    if x == None:
                        x = pred
                pred = root
                root =root.right
        x.val, y.val = y.val, x.val
                    

#Fastest
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        
        stack = []
        self.addLeftNodes(stack, root)
        prev = None
        swapNodes = [None, None]
        
        while stack:
            node = stack.pop()
            if prev and node.val < prev.val:
                swapNodes[0] = node
                if swapNodes[1] is None:
                    swapNodes[1] = prev
                else:
                    break
            prev = node
            self.addLeftNodes(stack, node.right)
        
        swapNodes[0].val, swapNodes[1].val = swapNodes[1].val, swapNodes[0].val
            
        
    
    def addLeftNodes(self, stack, root):
        while root:
            stack.append(root)
            root = root.left