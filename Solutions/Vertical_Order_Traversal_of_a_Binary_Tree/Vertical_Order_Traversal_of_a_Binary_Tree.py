# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict,deque
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        mp = defaultdict(lambda:[])
        minh = 0
        maxh = 0
        q = deque()
        q.append( (root,0) )
        h= 0 
        while q:
            l = len(q)
            h-=1
            tmp = defaultdict(lambda :[])
            for _ in range(l):
                r,x = q.popleft()
                tmp[x].append(r.val)
                if r.left:
                    q.append( (r.left,x-1) )
                if r.right:
                    q.append( (r.right,x+1) )
            
            for k in tmp:
                tmp[k].sort()
                mp[k].extend(tmp[k])
                
        ans = [ (k,v) for k,v in mp.items() ]
        ans.sort(key = lambda x:x[0] )
        ans = [ x[1] for x in ans ]
        return ans

#Fastest
class Solution:
     def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        
        if not root:
            return []
        
        cols = collections.defaultdict(list)
        queue = deque([(root, 0, 0)])
        min_col = max_col = 0
        result = []
        
        while queue:
            
            node, row, col = queue.popleft()
            if node: 
                cols[col].append((row, node.val))
                min_col = min(min_col, col)
                max_col = max(max_col, col)
                
                if node.left:
                    queue.append((node.left, row + 1, col - 1))
                
                if node.right:
                    queue.append((node.right, row + 1, col + 1))
                    
        
        for col in range(min_col, max_col + 1):
            result.append([val for row, val in sorted(cols[col])])
            
        return result