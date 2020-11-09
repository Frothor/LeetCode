# LeetCode Medium 1026. Maximum Difference Between Node and Ancestor Solution
## Overview
The problem is one of the typical tree problems that can be implemented using recursion. We could simply perform recursive tree traversal. Also, with a little insight, we can implement a slightly different approach.

Below, we will discuss two similar approaches: *Recursion* and *Maximum Minus Minimum*. Both are recursive approaches, but the later one uses a little insight.

## Approach #1: Recursion
### Intuition

Let's start from **Brute Force**.

A typical Brute Force approach is to compare every node with its ancestors. In the worst case, we have to compare every node-pair (when the tree is a single line).

The time complexity would be ***O(N^2)***, given ***N*** is the number of nodes in the binary tree.

Can we simplify it?

Since the problem asks us the **Maximum Difference**, maybe we do not need to compare all ancestor for a given node and we only need to compare the ancestors with **Maximum** value and **Minimum** value.

Therefore, for a given node, we only need the maximum value and the minimum value from the root to this node.

To achieve this, we can define a function `helper` to start recursion, which receives a node and two integers, the maximum and minimum value of its ancestors, as input.

In the function `helper`, we need to update the maximum difference, the current maximum value, and the current minimum value.

### Algorithm

*Step 1:* Initialize a variable `result` to record the required maximum difference.

*Step 2:* Define a function helper, which takes three arguments as input.

* The first argument is the current node, and the second and third arguments are the maximum and minimum values along the root to the current node, respectively.

* In the function `helper`, update `result` and call `helper` on the left and right subtrees.

*Step 3:* Run `helper` on the `root`. It will automatically do recursion on every node.

*Step 4:* Finally, return `result`.

### Implementation

#### Java
```java
class Solution {
    // record the required maximum difference
    int result = 0;

    public int maxAncestorDiff(TreeNode root) {
        if (root == null) {
            return 0;
        }
        result = 0;
        helper(root, root.val, root.val);
        return result;
    }

    void helper(TreeNode node, int curMax, int curMin) {
        if (node == null) {
            return;
        }
        // update `result`
        int possibleResult = Math.max(Math.abs(curMax - node.val), Math.abs(curMin - node.val));
        result = Math.max(result, possibleResult);
        // update the max and min
        curMax = Math.max(curMax, node.val);
        curMin = Math.min(curMin, node.val);
        helper(node.left, curMax, curMin);
        helper(node.right, curMax, curMin);
        return;
    }
}
```

#### Python3
```python
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root:
            return 0
        # record the required maximum difference
        self.result = 0

        def helper(node, cur_max, cur_min):
            if not node:
                return
            # update `result`
            self.result = max(self.result, abs(cur_max-node.val),
                              abs(cur_min-node.val))
            # update the max and min
            cur_max = max(cur_max, node.val)
            cur_min = min(cur_min, node.val)
            helper(node.left, cur_max, cur_min)
            helper(node.right, cur_max, cur_min)

        helper(root, root.val, root.val)
        return self.result
```

### Complexity Analysis

Let ***N*** be the number of nodes in the binary tree.

* Time complexity: ***O(N)*** since we visit all nodes once.

* Space complexity: ***O(N)*** since we need stacks to do recursion, and the maximum depth of the recursion is the height of the tree, which is ***O(N)*** in the worst case and ***O(log(N))*** in the best case.

## Approach #2: Maximum Minus Minimum
### Intuition

An insight is that:

* Given any two nodes on the same root-to-leaf path, they must have the required **ancestor** relationship.

Therefore, we just need to record the maximum and minimum values of all root-to-leaf paths and return the maximum difference.

To achieve this, we can record the maximum and minimum values during the recursion and return the difference when encountering leaves.

### Algorithm

*Step 1:* Define a function `helper`, which takes three arguments as input and returns an integer.

* The first argument `node` is the current node, and the second argument `cur_max` and third argument `cur_min` are the maximum and minimum values along the root to the current node, respectively.

* Function `helper` returns `cur_max - cur_min` when encountering leaves. Otherwise, it calls `helper` on the left and right subtrees and returns their maximum.

*Step 2:* Run `helper` on the `root` and return the result.

### Implementation

#### Java
```java
class Solution {
    public int maxAncestorDiff(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return helper(root, root.val, root.val);
    }

    public int helper(TreeNode node, int curMax, int curMin) {
        // if encounter leaves, return the max-min along the path
        if (node == null) {
            return curMax - curMin;
        }
        // else, update max and min
        // and return the max of left and right subtrees
        curMax = Math.max(curMax, node.val);
        curMin = Math.min(curMin, node.val);
        int left = helper(node.left, curMax, curMin);
        int right = helper(node.right, curMax, curMin);
        return Math.max(left, right);
    }
}
```

#### Python3
```python
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root:
            return 0

        def helper(node, cur_max, cur_min):
            # if encounter leaves, return the max-min along the path
            if not node:
                return cur_max - cur_min
            # else, update max and min
            # and return the max of left and right subtrees
            cur_max = max(cur_max, node.val)
            cur_min = min(cur_min, node.val)
            left = helper(node.left, cur_max, cur_min)
            right = helper(node.right, cur_max, cur_min)
            return max(left, right)

        return helper(root, root.val, root.val)
```



## [Python] O(n): look at child, explained
Let us traverse our tree from top to bottom with `dfs` function, where we pass parameters:

1. `node` is current node we visiting
2. `high` is maximum over all node values, which are above our `node`, that is the maximum among parent, parent of parent, parent of parent of parent and so on.
3. `low` is minumum over all node values, which are above our `node`.

No, we iterate over our tree and:

1. Update our `self.Max`: look at two values `abs(node.val - low)` and `abs(node.val - high)`: it will be the biggest candidates for difference between node and its ancestor, where `node` is **lying in lower layer**.
2. Now, we run our `dfs` for left and right children, where we updated `low` and `high` values: we need to include current `node.val`.

We start with `dfs(root, root.val, root.val)`, because we do not have nodes which are above our root.

**Complexity:** time complexity is `O(n)`, space complexity is `O(h)`, as any usual dfs have.

```python
class Solution:
    def maxAncestorDiff(self, root):
        
        self.Max = 0
        def dfs(node, low, high):    
            if not node: return

            self.Max = max(self.Max, abs(node.val-low), abs(node.val-high))
            low1, high1 = min(low, node.val), max(high, node.val)
            dfs(node.left, low1, high1)
            dfs(node.right, low1, high1)
                
        dfs(root, root.val, root.val)
        return self.Max
```

[Link to originla post](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/discuss/929284/Python-O(n)%3A-look-at-child-explained)

### Complexity Analysis

Let ***N*** be the number of nodes in the binary tree.

* Time complexity: ***O(N)*** since we visit all nodes once.

* Space complexity: ***O(N)*** since we need stacks to do recursion, and the maximum depth of the recursion is the height of the tree, which is ***O(N)*** in the worst case and ***O(log(N))*** in the best case.

