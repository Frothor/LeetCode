# LeetCode Easy 938. Range Sum of BST Solution
## Approach 1: Depth First Search
### Intuition and Algorithm

We traverse the tree using a depth first search. If `node.val` falls outside the range `[L, R]`, (for example `node.val < L`), then we know that only the right branch could have nodes with value inside `[L, R]`.

We showcase two implementations - one using a recursive algorithm, and one using an iterative one.

### Recursive Implementation

#### Java
```java
class Solution {
    int ans;
    public int rangeSumBST(TreeNode root, int L, int R) {
        ans = 0;
        dfs(root, L, R);
        return ans;
    }

    public void dfs(TreeNode node, int L, int R) {
        if (node != null) {
            if (L <= node.val && node.val <= R)
                ans += node.val;
            if (L < node.val)
                dfs(node.left, L, R);
            if (node.val < R)
                dfs(node.right, L, R);
        }
    }
}
```

#### Python
```python
class Solution(object):
    def rangeSumBST(self, root, L, R):
        def dfs(node):
            if node:
                if L <= node.val <= R:
                    self.ans += node.val
                if L < node.val:
                    dfs(node.left)
                if node.val < R:
                    dfs(node.right)

        self.ans = 0
        dfs(root)
        return self.ans
```

### Iterative Implementation

#### Java
```java
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        int ans = 0;
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (L <= node.val && node.val <= R)
                    ans += node.val;
                if (L < node.val)
                    stack.push(node.left);
                if (node.val < R)
                    stack.push(node.right);
            }
        }
        return ans;
    }
}
```

#### Python
```python
class Solution(object):
    def rangeSumBST(self, root, L, R):
        ans = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                if L <= node.val <= R:
                    ans += node.val
                if L < node.val:
                    stack.append(node.left)
                if node.val < R:
                    stack.append(node.right)
        return ans
```

### Complexity Analysis

* Time Complexity: ***O(N)***, where ***N*** is the number of nodes in the tree.

* Space Complexity: ***O(N)***

    * For the recursive implementation, the recursion will consume additional space in the function call stack. In the worst case, the tree is of chain shape, and we will reach all the way down to the leaf node.

    * For the iterative implementation, essentially we are doing a **BFS** (Breadth-First Search) traversal, where the stack will contain no more than two levels of the nodes. The maximal number of nodes in a binary tree is ***N/2***. Therefore, the maximal space needed for the stack would be ***O(N)***.