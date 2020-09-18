# LeetCode Best Time to Buy and Sell Stock Solution

## Intuition
We need to find out the maximum difference (which will be the maximum profit) between two numbers in the given array. Also, the second number (selling price) must be larger than the first one (buying price).

In formal terms, we need to find *max(prices[j]−prices[i])*, for every *i* and *j* such that *j>i*.

## Approach 1: Brute Force

**Java**
```java
public class Solution {
    public int maxProfit(int prices[]) {
        int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
}
```

### Complexity Analysis

* Time complexity : *O(n^2)*. Loop runs *n(n-1)/2* times.

* Space complexity : *O(1)*. Only two variables - *maxprofit* and *profit* are used.

## [Python] O(n) dynamic programming solution, explained

Classical dynamic programming problem. Let **dp[i]** be a maximum profit we can have if we sell stock at **i-th** moment of time. Then we can get, that **dp[i+1] = max(dp[i] + q, q)**, where **q = nums[i+1] - nums[i]**, we have two choices, either we just buy and immeditely sell and get **q** gain, or we use **dp[i] + q** to merge two transactions.

Note now, that we do not really need to keep all **dp** array, but we can keep only last state.

**Complexity:** time complexity is **O(n)**, space complexity is **O(1)**.
```python
class Solution:
    def maxProfit(self, nums):
        ans, dp = 0, 0
        for i in range(0, len(nums)-1):
            q = nums[i+1] - nums[i]
            dp = max(dp + q, q)
            ans = max(ans, dp)
        return ans
```

**PS** Look also my solutions to similar problems:
Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/794633/Python-O(n)-solution-with-optimization-explained
Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/761720/Python-dp-O(n)-solution-using-differences-explained

[Link to original post](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/851941/Python-O(n)-dynamic-programming-solution-explained)