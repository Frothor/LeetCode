# Solution
## Approach: Swap with Next Node [Accepted]
The usual way of deleting a node **node** from a linked list is to modify the **next** pointer of the node *before* it, to point to the node *after* it.

![Ex1](images/237_LinkedList.png)

Since we do not have access to the node *before* the one we want to delete, we cannot modify the **next** pointer of that node in any way. Instead, we have to replace the value of the node we want to delete with the value in the node after it, and then delete the node after it.

![Ex2](images/237_LinkedList2.png)

Because we know that the node we want to delete is not the tail of the list, we can guarantee that this approach is possible.

**Java**
```java
public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}
```
### Complexity Analysis

Time and space complexity are both *O(1)*.

Analysis written by: @noran