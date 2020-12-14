# LeetCode Medium 865. Smallest Subtree with all the Deepest Nodes Solution
## Approach 1: Paint Deepest Nodes
### Intuition

We try a straightforward approach that has two phases.

The first phase is to identify the nodes of the tree that are deepest. To do this, we have to annotate the depth of each node. We can do this with a depth first search.

Afterwards, we will use that annotation to help us find the answer:

* If the `node` in question has maximum depth, it is the answer.

* If both the left and right child of a node have a deepest descendant, then the answer is this parent `node`.

* Otherwise, if some child has a deepest descendant, then the answer is that child.

* Otherwise, the answer for this subtree doesn't exist.

### Algorithm

In the first phase, we use a depth first search `dfs` to annotate our nodes.

In the second phase, we also use a depth first search `answer(node)`, returning the answer for the subtree at that `node`, and using the rules above to build our answer from the answers of the children of `node`.

Note that in this approach, the `answer` function returns answers that have the deepest nodes of the entire tree, not just the subtree being considered.

### Java
```java
class Solution {
    Map<TreeNode, Integer> depth;
    int max_depth;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        depth = new HashMap();
        depth.put(null, -1);
        dfs(root, null);
        max_depth = -1;
        for (Integer d: depth.values())
            max_depth = Math.max(max_depth, d);

        return answer(root);
    }

    public void dfs(TreeNode node, TreeNode parent) {
        if (node != null) {
            depth.put(node, depth.get(parent) + 1);
            dfs(node.left, node);
            dfs(node.right, node);
        }
    }

    public TreeNode answer(TreeNode node) {
        if (node == null || depth.get(node) == max_depth)
            return node;
        TreeNode L = answer(node.left),
                 R = answer(node.right);
        if (L != null && R != null) return node;
        if (L != null) return L;
        if (R != null) return R;
        return null;
    }
}
```

### Python
```python
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        # Tag each node with it's depth.
        depth = {None: -1}
        def dfs(node, parent = None):
            if node:
                depth[node] = depth[parent] + 1
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root)

        max_depth = max(depth.itervalues())

        def answer(node):
            # Return the answer for the subtree at node.
            if not node or depth.get(node, None) == max_depth:
                return node
            L, R = answer(node.left), answer(node.right)
            return node if L and R else L or R

        return answer(root)
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the number of nodes in the tree.

* Space Complexity: ***O(N)***.

## Approach 2: Recursion
### Intuition

We can combine both depth first searches in *Approach #1* into an approach that does both steps in one pass. We will have some function `dfs(node)` that returns both the answer for this subtree, and the distance from node to the deepest nodes in this subtree.

### Algorithm

The `Result` (on some subtree) returned by our (depth-first search) recursion will have two parts:

* `Result.node`: the largest depth node that is equal to or an ancestor of all the deepest nodes of this subtree.
* `Result.dist`: the number of nodes in the path from the root of this subtree, to the deepest node in this subtree.

We can calculate these answers disjointly for `dfs(node)`:

* To calculate the `Result.node` of our answer:

    * If one `childResult` has deeper nodes, then `childResult.node` will be the answer.

    * If they both have the same depth nodes, then `node` will be the answer.

* The `Result.dist`of our answer is always 1 more than the largest `childResult.dist` we have.

### Java
```java
class Solution {
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }

    // Return the result of the subtree at this node.
    public Result dfs(TreeNode node) {
        if (node == null) return new Result(null, 0);
        Result L = dfs(node.left),
               R = dfs(node.right);
        if (L.dist > R.dist) return new Result(L.node, L.dist + 1);
        if (L.dist < R.dist) return new Result(R.node, R.dist + 1);
        return new Result(node, L.dist + 1);
    }
}

/**
 * The result of a subtree is:
 *       Result.node: the largest depth node that is equal to or
 *                    an ancestor of all the deepest nodes of this subtree.
 *       Result.dist: the number of nodes in the path from the root
 *                    of this subtree, to the deepest node in this subtree.
 */
class Result {
    TreeNode node;
    int dist;
    Result(TreeNode n, int d) {
        node = n;
        dist = d;
    }
}
```

### Python
```python
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        # The result of a subtree is:
        # Result.node: the largest depth node that is equal to or
        #              an ancestor of all the deepest nodes of this subtree.
        # Result.dist: the number of nodes in the path from the root
        #              of this subtree, to the deepest node in this subtree.
        Result = collections.namedtuple("Result", ("node", "dist"))
        def dfs(node):
            # Return the result of the subtree at this node.
            if not node: return Result(None, 0)
            L, R = dfs(node.left), dfs(node.right)
            if L.dist > R.dist: return Result(L.node, L.dist + 1)
            if L.dist < R.dist: return Result(R.node, R.dist + 1)
            return Result(node, L.dist + 1)

        return dfs(root).node
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the number of nodes in the tree.

* Space Complexity: ***O(N)***.
