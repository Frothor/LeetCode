#Fourth fastest
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        sorted_nodes = []
        self.dfs(root, sorted_nodes)
        for i in range(len(sorted_nodes) - 1):
            node = sorted_nodes[i]
            node.right = sorted_nodes[i + 1]
            node.left = None
        sorted_nodes[-1].left = None
        sorted_nodes[-1].right = None
        return sorted_nodes[0]

    def dfs(self, root, sorted_nodes):
        if root is None:
            return
        if root.left is None and root.right is None:
            sorted_nodes.append(root)
            return
        self.dfs(root.left, sorted_nodes)
        sorted_nodes.append(root)
        self.dfs(root.right, sorted_nodes)

#Third fastest
class Solution:
    def tree(self,queue,node:TreeNode)->TreeNode:
        for i in range(1,len(queue)):
            node.right=TreeNode(queue[i])
            node=node.right
        return node
    def que(self,q,root: TreeNode):
        if root==None:
            return 0
        self.que(q,root.left)
        q.append(root.val)
        self.que(q,root.right)
        return q
    def increasingBST(self, root: TreeNode) -> TreeNode:
        if root==None:
            return 0
        queue=collections.deque()
        queue=self.que(queue,root)
        node=TreeNode(queue[0])
        self.tree(queue,node)
        return node


#Second fastest
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        return self.BSTHelper(root)
    
    def BSTHelper(self, root, tail=None):
        if (root is None):
            return tail
        res = self.BSTHelper(root.left, root)
        root.left = None
        root.right = self.BSTHelper(root.right, tail)
        return res

#Fastest
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        global roots
        roots=root
        global first
        global joiner
        joiner = None
        first = 1

        def helper(nde):
            global first
            global roots
            global joiner
            if nde.left:
                helper(nde.left)
            if first:
                roots = nde
                joiner = nde
                first = 0
            else:
                nde.left = None
                joiner.right = nde
                joiner = nde
            if nde.right:
                helper(nde.right)

        helper(roots)
        return roots