class Solution:
    def insertIntoBST(self, root, val):
        def dfs(root):
            if val < root.val:
                if root.left:
                    dfs(root.left)
                else:
                    root.left = TreeNode(val)
            else:
                if root.right:
                    dfs(root.right)
                else:
                    root.right = TreeNode(val)
        
        if not root: return TreeNode(val)
        dfs(root)
        return root

#Third fastest
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root: return TreeNode(val)
        self.insertTarget(root, val)
        return root
    
    def insertTarget(self, root, val):
        # recursive
        if not root.left and not root.right:
            if root.val > val:
                root.left = TreeNode(val)
            else:
                root.right = TreeNode(val)
            return None
                
        if root.val > val and root.left:
            self.insertIntoBST(root.left, val)
        elif root.val > val and not root.left:
            root.left = TreeNode(val)
            return None
        elif root.val < val and root.right:
            self.insertIntoBST(root.right, val)
        else:
            root.right = TreeNode(val)
            return None

#Second fastest
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        if val < root.val:
            if not root.left:
                root.left = TreeNode(val)
            else:
                self.insertIntoBST(root.left, val)
        else:
            if not root.right:
                root.right = TreeNode(val)
            else:
                self.insertIntoBST(root.right, val)
        return root

#Fastest
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        
        if root.val < val:
            root.right = self.insertIntoBST(root.right, val)
        else:
            root.left = self.insertIntoBST(root.left, val)
        
        return root