# LeetCode Teemo Attacking
## Approach 1: One pass
### Intuition

The problem is an example of merge interval questions which are now [quite popular in Google](https://leetcode.com/discuss/interview-question/280433/Google-or-Phone-screen-or-Program-scheduling).

Typically such problems could be solved in a linear time in the case of sorted input, like [here](https://leetcode.com/problems/insert-interval/solution/), and in ***O(NlogN)*** time otherwise, [here is an example](https://leetcode.com/problems/merge-intervals/solution/).

Here one deals with a sorted input, and the problem could be solved in one pass with a constant space. The idea is straightforward: consider only the interval between two attacks. Ashe spends in a poisoned condition the whole time interval if this interval is shorter than the poisoning time duration `duration`, and `duration` otherwise.

### Algorithm

* Initiate total time in poisoned condition `total = 0`.

* Iterate over `timeSeries` list. At each step add to the total time the minimum between interval length and the poisoning time duration `duration`.

* Return `total + duration` to take the last attack into account.

### Implementation

![ashe](images/ashe.png)

#### Java
```java
class Solution {
  public int findPoisonedDuration(int[] timeSeries, int duration) {
    int n = timeSeries.length;
    if (n == 0) return 0;

    int total = 0;
    for(int i = 0; i < n - 1; ++i)
      total += Math.min(timeSeries[i + 1] - timeSeries[i], duration);
    return total + duration;
  }
}
```

#### Python
```python
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        n = len(timeSeries)
        if n == 0:
            return 0
        
        total = 0
        for i in range(n - 1):
            total += min(timeSeries[i + 1] - timeSeries[i], duration)
        return total + duration
```

### Complexity Analysis

* Time complexity : ***O(N)***, where N is the length of the input list, since we iterate the entire list.

* Space complexity : ***O(1)***, it's a constant space solution.

## [Python] Merge intervals O(n) solution, explained

If we look carefully at this problem we can see that all we need to do is to merge some intervals with equal length and return total length of merged intervals. Note also that intervals are already sorted by its beginings (and ends as well, because they have equal length), so usual sorting step can be skipped.

All we need to do is to traverse our `timeSeries` and check if difference between current point and previous is more than `duration`. If it is more, we add `duration` to total sum, if it is less, we add difference between current and previous elements. Also we need to deal with border case of empty array and if array is not empty, add `duration` in the end.

**Complexity:** time complexity is `O(n)`, space complexity is `O(1)`.

```python
class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        n, out = len(timeSeries), 0
        if n == 0: return 0
        for i in range(n-1):
            out += min(timeSeries[i+1] - timeSeries[i], duration)
        return out + duration
```

[Link to original post](https://leetcode.com/problems/teemo-attacking/discuss/864975/Python-Merge-intervals-O(n)-solution-explained)