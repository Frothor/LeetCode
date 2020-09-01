#MOST COMMON

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return root
        if root.val > key:
            root.left = self.deleteNode(root.left, key )
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            node = root.right
            while node.left:
                node = node. left
            root.val = node.val
            root.right = self.deleteNode(root.right, root.val)
        return root
                

#FASTEST

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root:
            if key < root.val:
                root.left = self.deleteNode(root.left, key)
            elif key > root.val:
                root.right = self.deleteNode(root.right, key)
            else:
                if root.left is None: return root.right
                elif root.right is None: return root.left
                nxt = root.right
                while nxt.left:
                    nxt = nxt.left
                root.val = nxt.val
                root.right = self.deleteNode(root.right, nxt.val)
        return root