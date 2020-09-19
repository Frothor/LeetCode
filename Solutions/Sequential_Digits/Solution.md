# LeetCode Sequential Digits Solution

## [Python] Solution, using queue, explained

Let us create queue, where we put numbers **1,2,3,4,5,6,7,8,9** at the beginning. Then on each step we are going to extract number and put this number with added to the end incremented last digit: so we have on the next step:

**2,3,4,5,6,7,8,9,12**
**3,4,5,6,7,8,9,12,23**
...
**12,23,34,45,56,67,78,89**
**23,34,45,56,67,78,89,123**,
...

On each, when we extract number from the beginning we check if it is in our range and if it is, we put it into our out list. Then we add new candidate to the end of our queue. In this way we make sure, that we generate elements in increasing order.

Complexity: There will be **9+8+...+ 1** numbers with sqeuential digits at all and for each of them we need to check it at most once (though in practice we wil finish earlier), so time complexity is **O(45) = O(1)**. Space complexity is also **O(45) = O(1)**.

```python
class Solution:
    def sequentialDigits(self, low, high):
        out = []
        queue = deque(range(1,10))
        while queue:
            elem = queue.popleft()
            if low <= elem <= high:
                out.append(elem)
            last = elem % 10
            if last < 9: queue.append(elem*10 + last + 1)
                    
        return out
```

[Link to original post](https://leetcode.com/problems/sequential-digits/discuss/853592/Python-Solution-using-queue-explained)