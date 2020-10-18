# LeetCode Best Time to Buy and Sell Stock III Solution

## Solution 1: Devide & Conquer
We can solve this problem by using devide and conquer. We use left[i] to track the maximum profit for transactions before i, and use right[i] to track the maximum profit for transactions after i.

Detailed Video Explanation https://youtu.be/e8K4c6OoK-Q?t=0
```
Example: Dry Run

Example: prices[] = [3,3,5,0,0,3,1,4]

Iterate from left to right to build left.
left[0] = 0;
left[i] = Math.max(left[i - 1], prices[i] - minLeft)

left[] = [0, 0, 2, 2, 2, 3, 3, 4]

Iterate from right to left to build right.
right[n - 1] = 0;
right[i] = Math.max(right[i + 1], maxRight - prices[i]);

right[] = [4, 4, 4, 4, 4, 3, 3, 0]

Now we will iterate left and right together and take max of left[i] + right[i] = 6 [max]
```

```java
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;

        int[] left = new int[n];
        int[] right = new int[n];

        int minLeft = prices[0];
        for (int i = 1; i < n; i++) {
            left[i] = Math.max(left[i - 1], prices[i] - minLeft);
            minLeft = Math.min(minLeft, prices[i]);
        }

        int maxRight = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = Math.max(right[i + 1], maxRight - prices[i]);
            maxRight = Math.max(maxRight, prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = Math.max(maxProfit, left[i] + right[i]);
        }

        return maxProfit;
    }
}
```
**TC - O(n)**
**SC - O(n)**

## Solution 2: Impressed with @shetty4l explanation and code solving using state diagram.

For completing two transaction of buy and sell there is 4 states involve say s1, s2, s3, s4.
s1 is buying first share
s2 is selling first share
s3 is buying second share
s4 is selling second share

for **s1** we can buy a share of spend money -prices[i] or continue skip.
for **s2** we can sell a share earn profit of s1 + prices[i] or continue skip
for **s3** we can buy a share spend money of s2 - prices[i] or continue skip
for **s4** we can sell a share earn profit of s3 + prices[i] or continue skip

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        
        int s1 = -prices[0], s2 = Integer.MIN_VALUE, s3 = Integer.MIN_VALUE, s4 = Integer.MIN_VALUE;
        for (int i = 1; i < prices.length; i++) {
            s1 = Math.max(s1, -prices[i]);
            s2 = Math.max(s2, s1 + prices[i]);
            s3 = Math.max(s3, s2 - prices[i]);
            s4 = Math.max(s4, s3 + prices[i]);
        }
        
        return Math.max(0, s4);
    }
}
```
**TC - O(n)**
**SC - O(1)**

[Link to original post](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/794684/2-Solutions-or-DandC-or-State-Machine-O(n)-time-O(1)-space)

## [Python] O(n) solution with optimization, explained 
This problem is a special case of problem **188. Best Time to Buy and Sell Stock IV**. The following solution works for both problems. The only difference is that here we have `k = 2` transactions and in problem 188 we can have different `k`.

My way to solve this problem is to first evaluate matrix `B` of differences and then what is asked is to find the maximum sum of **two(k)** contiguous subarrays. We can also make optimization `if k > len(prices)//2: return sum(x for x in B if x > 0)`, which will help us, if `k` is big (in this problem it is equal to `2`, so you can remove this line, but you need it for problem 188). If k is more than half of length of prices, we can just choose all positive elements, we will have enough trancastions to do it.

Let us create dp array with size `k+1` by n`-1`, where `dp[i][j]` is the maximum gain, where already made `j` transactions, that is choose `j` contiguous subarrays and used all elements before our equal number `i`. Also, `mp[i][j] = max(dp[0][j], ..., dp[i][j])`. We take `k+1` size, because we start with 0 transactions, which will be filled with zeros. We take `n-1` size, because original size is `n`, and size of differences is `n-1`. Also we start with `dp[0][1] = B[0]`, because we need to choose one contiguous subarray which ends with element `B[0]`, which is `B[0]` itself. Also we put `mp[0][1] = B[0]` for the same logic.

Now, about updates: we iterate over all `i` from `1` to `n-2` inclusive and `j` from `1` to `k` inclusive and:

1. Update `dp[i][j] = max(mp[i-1][j-1], dp[i-1][j]) + B[i]`. By definition we need to take `B[i]`. We can either say, that we add it to the last contiguous subarray: `dp[i-1][j] + B[i]`, or we say that it is new contiguous subarray: `mp[i-1][j-1] + B[i]`. Note, here we use `mp`, because we actually have `max(dp[0][j-1], ... , dp[i-1][j-1])`.
2. Update `mp[i][j] = max(dp[i][j], mp[i-1][j])`.
3. Finally, return maximum from the `mp[-1]`, we need to choose maximum, because optimal solution can be with less than `k` transactions.

**Complexity:** Time complexity is `O(nk) = O(n)`, because here `k = 2`. Space complexity is also `O(nk) = O(n)`.

```python
class Solution:
    def maxProfit(self, prices):
        if len(prices) <= 1: return 0
        n, k = len(prices), 2

        B = [prices[i+1] - prices[i] for i in range(len(prices) - 1)]
        if k > len(prices)//2: return sum(x for x in B if x > 0)
        
        dp = [[0]*(k+1) for _ in range(n-1)] 
        mp = [[0]*(k+1) for _ in range(n-1)] 

        dp[0][1], mp[0][1] = B[0], B[0]

        for i in range(1, n-1):
            for j in range(1, k+1):
                dp[i][j] = max(mp[i-1][j-1], dp[i-1][j]) + B[i]
                mp[i][j] = max(dp[i][j], mp[i-1][j])

        return max(mp[-1])
```

Optimization:
Note, that if we have array like `[1,5,7, -7, -4, -3, 10, 2, 7, -4, -8, 13, 15]`, then we can work in fact with smaller array `[1+5+7, -7-4-3, 10+2+7, -4-8, 13+15] = [13,-14,19,-12,28]`. So, instead of `B = [prices[i+1] - prices[i] for i in range(len(prices) - 1)]`, we can evaluate:
```
delta = [prices[i+1]-prices[i] for i in range (len(prices)-1)]
B=[sum(delta) for _, delta in groupby(delta, key=lambda x: x < 0)]
n, k = len(B) + 1, 2
```
When used this code, I have `132ms` to `64ms` improvement (which is faster than 99%).
Thanks `user2349` for providing shorter version of code!
=========================================================================================
A shorter way:
```python
delta = [prices[i+1]-prices[i] for i in range (len(prices)-1)]
B=[delta[0]]
for i in range(1,len(delta)):
     if(delta[i]*B[-1]>=0):B[-1]+=delta[i]
     else:B+=[delta[i]]
```

or

```python
delta = [prices[i+1]-prices[i] for i in range (len(prices)-1)]
B=[sum(delta) for _, delta in groupby(delta, key=lambda x: x < 0)]
```

[Link to original post](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/794633/Python-O(n)-solution-with-optimization-explained)