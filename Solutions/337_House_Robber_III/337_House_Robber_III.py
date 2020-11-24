#Most common
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        def dfs(node):
            if not node: return [0, 0]
            L = dfs(node.left)
            R = dfs(node.right)
            return [node.val + L[1] + R[1], max(L) + max(R)]
        
        return max(dfs(root))

#Fourth fastest
class Solution:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        def helper(node):
            if not node: 
                return (0, 0)
            l1, l2 = helper(node.left)
            r1, r2 = helper(node.right)
            
            return (node.val + l2 + r2, max(l1, l2) + max(r1, r2))
            
            
        return max(helper(root))

#Third fastest
class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(node):
            # return [rob this node, not rob this node]
            if not node:
                return (0, 0)
            left = helper(node.left)
            right = helper(node.right)
            # if we rob this node, we cannot rob its children
            rob = node.val + left[1] + right[1]
            # else we could choose to either rob its children or not
            not_rob = max(left) + max(right)
            return [rob, not_rob]

        return max(helper(root))

#Second fastest
class Solution:
    def rob(self, root: TreeNode) -> int:
        def traverse(root):
            if not root:
                return 0, 0
            
            left_can_add_root, left_cannot_add_root = traverse(root.left)
            right_can_add_root, right_cannot_add_root = traverse(root.right)
            
            cannot_add_root = left_cannot_add_root + right_cannot_add_root
            can_add_root = max(left_can_add_root + right_can_add_root + root.val, cannot_add_root)
            
            return cannot_add_root, can_add_root
        
        return max(traverse(root))

#Fastest
class Solution:
    def rob(self, root: TreeNode) -> int:
        def sub_rob(node):
            if not node:
                return (0, 0)
            l_child, l_grand_child = sub_rob(node.left)
            r_child, r_grand_child = sub_rob(node.right)
            
            child_profit =  l_child + r_child
            grand_profit = node.val + l_grand_child + r_grand_child
            node_profit = max(child_profit, grand_profit)
            return (node_profit, l_child + r_child)
        return max(sub_rob(root))