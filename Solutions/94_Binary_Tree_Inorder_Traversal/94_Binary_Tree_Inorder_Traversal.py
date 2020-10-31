#Iterative
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        visited = set()
        result = []
        stack = []
        if root: stack.append(root)
        
        while(len(stack) > 0):
            curr = stack.pop()
            
            if curr.left and curr.left not in visited:
                stack.append(curr)
                stack.append(curr.left)
                continue
            
            visited.add(curr)
            result.append(curr.val)
        
            if curr.right and curr.right not in visited:
                stack.append(curr.right)
        
        return result

#Recursive
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        return self.helper(root, [])
        
    
    def helper(self, node, acc):
        if not node: return acc
        if node.left:
            self.helper(node.left, acc)
        
        acc.append(node.val)
        
        if node.right:
            self.helper(node.right, acc)
        
        return acc

#Third fastest
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        res = []
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            res.append(cur.val)
            cur = cur.right
        return res

#Second fastest
class Solution:
    def traverse(self, arr, root):
        if not root:
            return
        self.traverse(arr,root.left)
        arr.append(root.val)
        self.traverse(arr, root.right)
    
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ret = []
        self.traverse(ret, root)
        return ret

#Fastest
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:

        res = []
        def inorder(root):
            if root == None:
                return
            if root.left != None:
                inorder(root.left)
            res.append(root.val)
            if root.right != None:
                inorder(root.right)
        inorder(root)
        return res
        