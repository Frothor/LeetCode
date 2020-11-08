class Solution:
    def findTilt(self, root):
        def dfs(node):
            if not node: return [0,0]
            t1, s1 = dfs(node.left)
            t2, s2 = dfs(node.right)
            return [t1+t2+abs(s1-s2), s1+s2+node.val]
        return dfs(root)[0]

#Third fastest
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        
        ans = 0
        def solve(root):
            nonlocal ans
            if root:
                left = solve(root.left)
                right = solve(root.right)
                ans += abs(left - right)
                return left + right+ root.val
            return 0
        solve(root)
        return ans

#Second fastest
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        tilt = 0

        def valueSum(node):
            nonlocal tilt
            if not node:
                return 0
            leftSum = valueSum(node.left)
            rightSum = valueSum(node.right)
            localTilt = abs(rightSum - leftSum)
            tilt += localTilt
            return node.val + leftSum + rightSum
        valueSum(root)

        return tilt

#Fastest
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        tilt = [0] 
        self.traverse(root, tilt)  
        return tilt[0]
    
    def traverse(self,root, tilt): 
        if (not root):  
            return 0

        left = self.traverse(root.left, tilt)  
        right = self.traverse(root.right, tilt)  
 
        tilt[0] += abs(left - right)  

        return left + right + root.val  