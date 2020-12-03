# LeetCode Easy 897. Increasing Order Search Tree
## Approach 1: In-Order Traversal
### Intuition

The definition of a binary search tree is that for every node, all the values of the left branch are less than the value at the root, and all the values of the right branch are greater than the value at the root.

Because of this, an *in-order traversal* of the nodes will yield all the values in increasing order.

### Algorithm

Once we have traversed all the nodes in increasing order, we can construct new nodes using those values to form the answer.

### Java
```java
class Solution {    
    public TreeNode increasingBST(TreeNode root) {
        List<Integer> vals = new ArrayList();
        inorder(root, vals);
        TreeNode ans = new TreeNode(0), cur = ans;
        for (int v: vals) {
            cur.right = new TreeNode(v);
            cur = cur.right;
        }
        return ans.right;
    }

    public void inorder(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        inorder(node.left, vals);
        vals.add(node.val);
        inorder(node.right, vals);
    }
}
```

### Python3
```python
class Solution:
    def increasingBST(self, root):
        def inorder(node):
            if node:
                yield from inorder(node.left)
                yield node.val
                yield from inorder(node.right)

        ans = cur = TreeNode(None)
        for v in inorder(root):
            cur.right = TreeNode(v)
            cur = cur.right
        return ans.right
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the number of nodes in the given tree.

* Space Complexity: ***O(N)***, the size of the answer.

## Approach 2: Traversal with Relinking
### Intuition and Algorithm

We can perform the same in-order traversal as in *Approach 1*. During the traversal, we'll construct the answer on the fly, reusing the nodes of the given tree by cutting their left child and adjoining them to the answer.

### Java
```java
class Solution {
    TreeNode cur;
    public TreeNode increasingBST(TreeNode root) {
        TreeNode ans = new TreeNode(0);
        cur = ans;
        inorder(root);
        return ans.right;
    }

    public void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        node.left = null;
        cur.right = node;
        cur = node;
        inorder(node.right);
    }
}
```

### Python
```python
class Solution:
    def increasingBST(self, root):
        def inorder(node):
            if node:
                inorder(node.left)
                node.left = None
                self.cur.right = node
                self.cur = node
                inorder(node.right)

        ans = self.cur = TreeNode(None)
        inorder(root)
        return ans.right
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the number of nodes in the given tree.

* Space Complexity: ***O(H)*** in additional space complexity, where ***H*** is the height of the given tree, and the size of the implicit call stack in our in-order traversal.