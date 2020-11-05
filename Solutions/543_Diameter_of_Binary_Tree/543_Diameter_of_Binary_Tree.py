#Fourth fastest
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 1
        def depth(node):
            if not node: return 0
            L = depth(node.left)
            R = depth(node.right)
            self.ans = max(self.ans, L+R+1)
            return max(L, R) + 1

        depth(root)
        return self.ans - 1

#Third fastest
class Solution:
    def _height(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return max(self._height(root.left), self._height(root.right)) + 1
    
    def _diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        diameter = self._height(root.left) + self._height(root.right)
        
        return max(diameter, self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right))
    
    
    def _diameterOfBinaryTreeHelper(self, root: TreeNode) -> (int, int):
        if root is None:
            return 0, 0
        
        right_height, right_diameter = self._diameterOfBinaryTreeHelper(root.right)
        left_height, left_diameter = self._diameterOfBinaryTreeHelper(root.left)
        
        return max(left_height, right_height) + 1, max(left_height + right_height, left_diameter, right_diameter)
    
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        return self._diameterOfBinaryTreeHelper(root)[-1]

#Second fastest
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        res = 0
        
        def helper(root):
            nonlocal res
            if not root: return 0
            left = helper(root.left)
            right = helper(root.right)
            res = max(res, left + right)
            return max(left, right) + 1
        
        helper(root)
        
        return res

#Fastest
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        
        self.res = 1
        def Dimeter(root):
            if not root:
                return 0

            left = Dimeter(root.left)
            right = Dimeter(root.right)

            temp = 1 + max(left, right)
            self.res = max(self.res, 1 + left + right)

            return temp
        
        Dimeter(root)
        return self.res - 1
