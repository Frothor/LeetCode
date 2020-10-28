# LeetCode 228. Summary Ranges Solution
## [Python] Two pointers O(n) solution, explained

What we need to in this problem is just traverse our data and create our ranges. Like if we have `1,2,3,4,5,7`, we see at `1`, `2`, `3`, `4` and `5`, and then we need to stop and start new range. We use two pointers approach with `beg` and `end` pointers. We increase our `end` pointers until next number is not equal to current + 1. Also we need to check if we have range with only one number of with more than one.

**Complexity**: time complexity is `O(n)`, because we pass only once over our data. Space complexity is also potentially `O(n)`, because it can be the size of our answer.

```python
class Solution:
    def summaryRanges(self, nums):
        i, result, N = 0, [], len(nums)
        
        while i < N:
            beg = end = i
            while end < N - 1 and nums[end] + 1 == nums[end + 1]: end += 1
            result.append(str(nums[beg]) + ("->" + str(nums[end])) *(beg != end))     
            i = end + 1
        
        return result
```

[Link to original post](https://leetcode.com/problems/summary-ranges/discuss/913432/Python-Two-pointers-O(n)-solution-explained)