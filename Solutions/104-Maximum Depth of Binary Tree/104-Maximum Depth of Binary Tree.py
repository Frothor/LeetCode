# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

#Third fastest
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return max(self.maxDepth(root.left)+1, self.maxDepth(root.right)+1)

#Second fastest
class Solution:
    maximum = 0
    def maxDepth(self, root: TreeNode, depth = 1) -> int:
        if root is None:
            return self.maximum
            
        if root.left is None and root.right is None:
            if self.maximum < depth:
                self.maximum = depth
            return self.maximum
        
        if root.left is not None:
            self.maxDepth(root.left, (depth + 1))
            
        if root.right is not None:
            self.maxDepth(root.right, (depth + 1))
            
        return self.maximum

#Fastest
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        
        return 1 + max(left, right)