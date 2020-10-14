# LeetCode 213 House Robber II Solution
## [Python] Just use House Robber twice

This problem can be seen as follow-up question for problem **198. House Robber**. Imagine, that we can already solve this problem: for more detailes please see my post:
https://leetcode.com/problems/house-robber/discuss/846004/Python-4-lines-easy-dp-solution-explained

Now, what we have here is circular pattern. Imagine, that we have `10` houses: `a0, a1, a2, a3, ... a9`: Then we have two possible options:

1. Rob house `a0`, then we can not rob `a0` or `a9` and we have `a2, a3, ..., a8` range to rob
2. Do not rob house `a0`, then we have `a1, a2, ... a9` range to rob.

Then we just choose maximum of these two options and we are done!

**Complexity:** time complexity is `O(n)`, because we use `dp` problem with complexity `O(n)` twice. Space complexity is `O(1)`, because in python lists passed by reference and space complexity of House Robber problem is `O(1)`.

```python
class Solution:
    def rob(self, nums):
        def rob_helper(nums):
            dp1, dp2 = 0, 0
            for num in nums:
                dp1, dp2 = dp2, max(dp1 + num, dp2)          
            return dp2
    
        return max(nums[0] + rob_helper(nums[2:-1]), rob_helper(nums[1:]))
```