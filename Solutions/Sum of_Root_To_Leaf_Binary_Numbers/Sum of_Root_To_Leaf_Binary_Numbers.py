# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root):
        def dfs(node):
            if not node.left and not node.right: self.sum += node.val
            for child in filter(None, [node.left, node.right]):
                child.val += node.val * 2
                dfs(child)
          
        self.sum = 0
        dfs(root)
        return self.sum


#Fastest
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        """
        Same as previous solution, but you the fact that bits
        are base 2 to increment, rather than doing string conversion.
        Recursive DFS to save paths
        """
        self.total = 0
        def DFS(root, binary):
            if root == None:
                return
            binary = binary * 2 + root.val
            if root.left == None and root.right == None:
                self.total += binary
            else:
                DFS(root.left, binary)
                DFS(root.right, binary)
        DFS(root, 0)
        return int(self.total)
