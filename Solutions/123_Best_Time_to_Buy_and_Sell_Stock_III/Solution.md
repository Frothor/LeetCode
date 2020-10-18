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