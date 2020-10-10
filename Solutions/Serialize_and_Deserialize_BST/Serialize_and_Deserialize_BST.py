# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        res = []
        def preorder(root):
            if not root:
                return None
            res.append(root.val)
            preorder(root.left)
            preorder(root.right)
        preorder(root)
        return ' '.join(map(str, res))
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        inputs = data.split()
        inputs = list(map(int, inputs))
        def build(minv,maxv):
            if inputs and minv < inputs[0] < maxv:
                v = inputs.pop(0)
                root = TreeNode(v)
                root.left = build(minv, v)
                root.right = build(v, maxv)
                return root
        
        node = build(float('-inf'), float('inf'))
        return node
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans

#Third fastest
class Codec:

    def serialize(self, root):
        vals = []

        def preOrder(node):
            if node:
                vals.append(node.val)
                preOrder(node.left)
                preOrder(node.right)

        preOrder(root)

        return ' '.join(map(str, vals))

    # O( N ) since each val run build once
    def deserialize(self, data):
        vals = collections.deque(int(val) for val in data.split())

        def build(minVal, maxVal):
            if vals and minVal < vals[0] < maxVal:
                val = vals.popleft()
                node = TreeNode(val)
                node.left = build(minVal, val)
                node.right = build(val, maxVal)
                return node

        return build(float('-infinity'), float('infinity'))

#Second fastest
class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        # pre-order traverse
        if root == None:
            return ""    
        return "->".join([str(root.val), self.serialize(root.left), self.serialize(root.right)])
    
    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        s = collections.deque(data.split("->"))
        
        def helper(datalist:collections.deque()) -> TreeNode:
            val = datalist.popleft()
            if val == "":
                return None
            root = TreeNode(int(val), None, None)
            root.left = helper(datalist)
            root.right = helper(datalist)
            return root
        
        return helper(s)
        


#Fastest
def serialize1(root: TreeNode) -> str:
    """Return a string of node values in preorder traversal"""
    data = []
    
    def dfs(node):
        if node:
            data.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
    
    dfs(root)
    return ','.join(data)

def deserialize1(data: List[str]) -> TreeNode:
    """Use preorder and inorder traversal data to recover a bst
    This approach assumes the node values of the bst are distinct 
    
    """
    if not data:
        return None
    
    preorder = [int(x) for x in data.split(',')]
    inorder = sorted(preorder)
    
    node_to_inorder_index= {v: i for i,v in enumerate(inorder)}
    
    def build_binary_tree(preorder_start, preorder_end, 
                         inorder_start, inorder_end):
        """Build a binary tree from
        preorder[preorder_start: preorder_end]
        inorder[inorder_start: inorder_end]
        """
        if preorder_start >= preorder_end:
            return None
        
        
        root_inorder_index = node_to_inorder_index[preorder[preorder_start]]
        
        # inorder traversal of the left substree 
        # is inorder[inorder_start: root_inorder_index]
        left_tree_size = root_inorder_index - inorder_start
        
        left = build_binary_tree(preorder_start+1, preorder_start+1+left_tree_size,
                                inorder_start, root_inorder_index
                                )
        
        right = build_binary_tree(preorder_start+left_tree_size+1, preorder_end,
                                 root_inorder_index+1, inorder_end
                                 )
        
        root = TreeNode(inorder[root_inorder_index])
        root.left = left; root.right = right
        
        return root
    
    return build_binary_tree(0, len(preorder), 0, len(inorder))
    
def serialize2(root):
    return root

def deserialize2(data):
    return data
    
class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        return serialize2(root)
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        return deserialize2(data)
        