#Third fastest
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        flag = True
        
        def f(node):
            nonlocal flag
            if not node:
                return 0
            l = f(node.left)
            r = f(node.right)
            if abs(l - r) > 1:
                flag = False
            return max(l, r) + 1
        
        f(root)
        return flag

#Second fastest
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        
        def helper(node):
            if not node:
                return 0,True
            
            l_height,l_corr = helper(node.left)
            if not l_corr:
                return -1,False
            
            r_height,r_corr = helper(node.right)
            if not r_corr:
                return -1,False
            
            return (1 + max(l_height,r_height), abs(l_height - r_height) <= 1)
        
        return helper(root)[1]

#Fastest
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

    
class Solution(object):
    def helper(self, root):
        if root == None:
            return 0, True
        hl, lb = self.helper(root.left)
        hr, rb = self.helper(root.right)
        if lb and rb and abs(hl-hr) <= 1:
            return max(hl,hr) + 1, True
        else:
            return -1, False

    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        h, is_b = self.helper(root)
        return is_b