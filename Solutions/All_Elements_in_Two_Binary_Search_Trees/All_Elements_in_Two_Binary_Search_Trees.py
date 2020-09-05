class Solution:
    def getAllElements(self, root1, root2):
        def inorder(root, lst):
            if not root: return
            inorder(root.left, lst)
            lst.append(root.val)
            inorder(root.right, lst)
        
        lst1, lst2 = [], []
        inorder(root1, lst1)
        inorder(root2, lst2)
        
        i1, i2, res = 0, 0, []
        s1, s2 = len(lst1), len(lst2)
        
        while i1 < s1 and i2 < s2:
            if lst1[i1] < lst2[i2]:
                res += [lst1[i1]]
                i1 += 1
            else:
                res += [lst2[i2]]
                i2 += 1
                
        return res + lst1[i1:] + lst2[i2:]

#Most common
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        ans=[]
        def inorder(root):
            if(root==None):
                return
            inorder(root.left)
            ans.append(root.val)
            inorder(root.right)
        inorder(root1)
        inorder(root2)
        ans.sort()
        return ans


#Fastest
 Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        l1, stack1, root = [], [], root1
        while stack1 or root:
            while root:
                stack1.append(root)
                root = root.left
            root = stack1.pop()
            l1.append(root.val)
            root = root.right
        l2, stack2, root = [], [], root2
        while stack2 or root:
            while root:
                stack2.append(root)
                root = root.left
            root = stack2.pop()
            l2.append(root.val)
            root = root.right
        l = l1 + l2
        return sorted(l)