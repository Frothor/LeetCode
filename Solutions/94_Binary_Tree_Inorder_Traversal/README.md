# LeetCode 94. Binary Tree Inorder Traversal
Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.

### Example 1:
![inorder1](images/inorder_1.jpg)
```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

### Example 2:
```
Input: root = []
Output: []
```

### Example 3:
```
Input: root = [1]
Output: [1]
```

### Example 4:
![inorder5](images/inorder_5.jpg)
```
Input: root = [1,2]
Output: [2,1]
```

### Example 5:
![inorder4](images/inorder_4.jpg)
```
Input: root = [1,null,2]
Output: [1,2]
``` 

### Constraints:

* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`
 

### Follow up:

Recursive solution is trivial, could you do it iteratively?