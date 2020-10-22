# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#Most common
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0;
        if root.left is None and root.right is None:
            return 1
        
        if root.left is None:
            return self.minDepth(root.right) + 1
        if root.right is None:
            return self.minDepth(root.left) + 1
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1


#Third fastest
import sys
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        if not (root.left or root.right):
            return 1
        res = sys.maxsize
        if root.left:
            res = min(res, self.minDepth(root.left))
        if root.right:
            res = min(res, self.minDepth(root.right))
        return res + 1


#Second fastest
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        leftChild = rightChild = 0
        if root.left:
            leftChild = self.minDepth(root.left)
        if root.right:
            rightChild = self.minDepth(root.right)
            
        if leftChild and not rightChild:
            return 1 + leftChild
        elif rightChild and not leftChild:
            return 1 + rightChild
        else:
            return min(leftChild+1,rightChild+1)

#Fastest
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        queue = [root]
        level = 1
        while queue:
            next_queue = []
            for node in queue:
                if not node.left and not node.right:
                    return level
                if node.left:
                    next_queue.append(node.left)
                if node.right:
                    next_queue.append(node.right)
            queue = next_queue
            level += 1
        return level