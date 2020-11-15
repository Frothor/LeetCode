# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def dfs(node):
            if not node: return
            if low <= node.val <= high: self.out += node.val
            if node.val > low:  dfs(node.left)
            if node.val < high: dfs(node.right)
                
        self.out = 0
        dfs(root)
        return self.out

#Fourth solution
class Solution(object):
    def rangeSumBST(self, root, L, R):
        def dfs(node):
            if node:
                if L <= node.val <= R:
                    self.ans += node.val
                if L < node.val:
                    dfs(node.left)
                if node.val < R:
                    dfs(node.right)

        self.ans = 0
        dfs(root)
        return self.ans

#Third fastest
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        total = 0
        def recurse(root):
            nonlocal total
            if not root:
                return
            if low <= root.val <= high:
                total += root.val
            if low < root.val:
                recurse(root.left)
            if high > root.val:
                recurse(root.right)
        recurse(root)
        return total

#Second fastest
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        def dfs(node):
            if node:
                if L <= node.val <= R:
                    self.ans += node.val
                if node.val > L:
                    dfs(node.left)
                if node.val < R:
                    dfs(node.right)

        self.ans = 0
        dfs(root)
        return self.ans

#Fastest
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        self.ans = 0
        def dfs(head):
            if  head : 
                if L <= head.val <= R:
                    self.ans +=head.val 
                if L <head.val :
                    dfs(head.left)
                if head.val <R :
                    dfs(head.right)
        dfs(root)
        return self.ans
