# LeetCode Delete Node in a BST Solution 

## [Python] O(h) solution, explained

It will be easier if we consider some tree and try to understand, what we need to do in different cases.

![sol1](images/sol1.png)

0. First we need to find our node in tree, so we just traverse it until **root.val == key**.
1. Case 1: node do not have any children, like **1**, **8**, **11**, **14**, **6** or **18**: then we just delete it and nothing else to do here.
2. Case 2: node has left children, but do not have right, for example **3** or **20**. In this case we can just delete this node and put connection betweeen its parent and its children: for example for **3**, we put connection **5->1** and for **20** we put connection **17->18**. Note, that the property of BST will be fulfilled, because for parent all left subtree will be less than its value and nothing will change for others nodes.
3. Case 3: node has right children, but do not have left, for example **13** and **17**. This case is almost like case 2: we just can delete node and reconnect its parent with its children.
4. Case 4: node has both children, like **12**, **5**, **7**, **9** or **15**. In this case we can not just delete it. Let us consider node **5**. We want to find succesor of this node: the node with next value, to do this we need to go one time to the right and then as left as possible. For node **5** our succesor will be **6**: we go **5->7->6**. How we can delete node **5** now? We swap nodes **5** and **6** (or just put value **6** to **5**) and then we need to deal with new tree, where we need to delete node which I put in square. How to do it? Just understand, that this node do not have left children, so it is either Case 1 or Case 3, which we already can solve.

![sol2](images/sol2.png)

**Complexity**: Complexity of finding node is **O(h)**, Cases 1,2,3 is **O(1)**. Complexity of Case **4** is **O(h)** as well, because we first find succesor and then apply one of the Cases 1,3 only once. So, overall complexity is **O(h)**. Space complexity is **O(h)** as well, because we use recursion and potentially we can find our node in the bottom of tree.
```python
class Solution(object):
    def deleteNode(self, root, key):
        if not root: return None
        
        if root.val == key:
            if not root.right: return root.left
            
            if not root.left: return root.right
            
            if root.left and root.right:
                temp = root.right
                while temp.left: temp = temp.left
                root.val = temp.val
                root.right = self.deleteNode(root.right, root.val)

        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else:
            root.right = self.deleteNode(root.right, key)
            
        return root
```

