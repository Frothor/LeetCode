# LeetCode Rotate List
## [Python] O(n) solution, explained

What we need to do in this problem is to find `k`-th element from the end, cut list in two parts and put second part after the first one. Let us do in it several steps:

1. Find `n`, length of our list, just traverse it until we reached end.
2. If `k % n == 0`, we do not need to rotate list, so return it as it is.
3. Find element where we need to cut our list: it has number `n - k%n`, but we need to cut previous connection, so we stop one element earlier.
4. Finally, put new head as `middle.next`, make connection between head and tail of original ist and remove connection between `middle` and its next, return new head.

**Complexity** is `O(n)` for time: we traverse our list twice at most; space complexity is `O(1)`, we did not use any additional space.

```python
class Solution:
    def rotateRight(self, head, k):
        if not head or not head.next: return head
        
        last, n = head, 1
        while last.next:
            last = last.next
            n += 1
            
        if k % n == 0: return head
        
        middle = head
        for i in range(n - k%n-1):
            middle = middle.next
            
        new_head = middle.next
        last.next = head
        middle.next = None
        return new_head
```