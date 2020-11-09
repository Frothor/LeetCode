# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root):
        
        self.Max = 0
        def dfs(node, low, high):    
            if not node: return

            self.Max = max(self.Max, abs(node.val-low), abs(node.val-high))
            low1, high1 = min(low, node.val), max(high, node.val)
            dfs(node.left, low1, high1)
            dfs(node.right, low1, high1)
                
        dfs(root, root.val, root.val)
        return self.Max

#Second fastest
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(root, path , ans) :
            if root :
                path.append(root.val) 
                if not root.left and not root.right :
                    ans.append(abs(max(path) -min(path)))
                else :
                    dfs(root.left,path,ans) 
                    dfs(root.right,path, ans) 
                path.pop()
  
        path=[]
        ans =[] 
        dfs(root , path, ans) 
        return max(ans)

#Fastest
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        
        if not root:
            return 0
        
        self.ans = float('-inf')
        
        def helper(node):
            
            val = node.val
            if not node.left and not node.right:
                return val, val
            
            lo, hi = val, val
            if node.left:
                lwr, upper = helper(node.left)
                diff = max(abs(val - lwr), abs(val - upper))
                self.ans = max(self.ans, diff)
                lo = min(lwr, lo) 
                hi = max(upper, hi)
            if node.right:
                lwr, upper = helper(node.right)
                diff = max(abs(val - lwr), abs(val - upper))
                self.ans = max(self.ans, diff)
                lo = min(lwr, lo) 
                hi = max(upper, hi)
            return lo, hi            
        
        helper(root)
        return self.ans