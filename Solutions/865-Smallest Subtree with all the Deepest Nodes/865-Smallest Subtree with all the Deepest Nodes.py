#Third fastest
#https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/969209/Python-O(n)-by-DFS-w-Comment
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        # --------------------------------------------
        def helper(node: TreeNode) -> (int, TreeNode):
            
            # first return item is depth
            # second return item is root of smallest subtree with deepest nooes
            
            if not node:
			
                # base case
                # empty node or empty tree
                return 0, None
            
            l_depth, l_node = helper(node.left)
            r_depth, r_node = helper(node.right)
            
            if l_depth > r_depth:
			
                # left subtree is deeper
                return l_depth+1, l_node
            
            elif r_depth > l_depth:
			
                # right subtree is deeper
                return r_depth+1, r_node
            
            else:
			
                # both subtrees are the same
                # current node is the root of smallest subtree with deepest nodes
                return l_depth+1, node
            
        # --------------------------------------------
        
        # second return item is the answer
        return helper(root)[1]

#Another
from functools import lru_cache

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        r'''
            0
          1    3
        null  2
        '''
        
        @lru_cache
        def nd(n):
            if not n: return 0
            else:
                return 1 + max(nd(n.left), nd(n.right))
                
                
        node = root
        while node:
            left_depth, right_depth = nd(node.left), nd(node.right)
            if left_depth == right_depth:
                return node
            elif left_depth > right_depth:
                node = node.left
            else:
                node = node.right
                
        return root

#Second fastest
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        q = [root]
        parents = {}
        parents[root] = None
        while q:
            next_q = []
            for node in q:
                if node.left:
                    parents[node.left] = node
                    next_q.append(node.left)
                if node.right:
                    parents[node.right] = node
                    next_q.append(node.right)
            if not next_q: break
            q = next_q
        self.ans = None
        deepest = q
        target = len(deepest)
        def dfs(cur):
            
            if not cur:
                return 0
            inc = 1 if cur in deepest else 0
            left = dfs(cur.left)
            right = dfs(cur.right)
            if left + right + inc == target and not self.ans: self.ans = cur
            return left + right + inc
            
        dfs(root)
        return self.ans if self.ans else root


#Fastest
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        parent = {root: None}
        
        curr = [root]
        prev = []
        
        while curr:
            prev = curr
            curr = []
            for n in prev:
                for c in [n.left, n.right]:
                    if c:
                        curr.append(c)
                        parent[c] = n
        
        res = set(prev)
        
        while len(res) > 1:
            res = set([parent[n] for n in res])
            
        return list(res)[0]