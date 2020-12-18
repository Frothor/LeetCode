#Fourth fastest
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def check(root, minimum, maximum):
            if not root:
                return True
            
            if root.val <= minimum or root.val >= maximum:
                return False
            
            left, right = True, True 
            if root.left:
                left = check(root.left, minimum, root.val)
            if root.right:
                right = check(root.right, root.val, maximum)
            
            return left and right
        return check(root, float("-inf"), float("inf"))

#Third fastest
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def rec(root, a, b):
            return not root or (a < root.val < b and rec(root.left,a, root.val) and rec(root.right, root.val, b))
        
        return rec(root, float("-inf"), float("inf"))

#Second fastest
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def isValid(root, mini, maxi):
            if not root:
                return True
            if root.val >= maxi or root.val <= mini:
                return False
            return isValid(root.left, mini, root.val) and isValid(root.right, root.val, maxi)
            
            
        return isValid(root, float('-inf'), float('inf'))

#Fastest
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        if not root:
            return True
        stack = []
        pre = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pre != None and pre.val >= root.val:
                return False
            pre = root
            root = root.right
            
        return True
            
                
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
#         if not root:
#             return True
            
#         stack = [(float('-inf'), root, float('inf'))] 
#         while stack:
#             lower, root, upper = stack.pop()
#             if not root:
#                 continue
#             val = root.val
#             if val <= lower or val >= upper:
#                 return False
#             stack.append((val, root.right, upper))
#             stack.append((lower, root.left, val))
#         return True  



