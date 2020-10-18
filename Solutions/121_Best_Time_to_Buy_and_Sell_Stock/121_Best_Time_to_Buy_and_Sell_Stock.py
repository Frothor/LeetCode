#Classical dynamic programming problem. Let dp[i] be a maximum profit we can have if we sell stock at i-th moment of time. Then we can get, that dp[i+1] = max(dp[i] + q, q), where q = nums[i+1] - nums[i], we have two choices, either we just buy and immeditely sell and get q gain, or we use dp[i] + q to merge two transactions.

#Note now, that we do not really need to keep all dp array, but we can keep only last state.

#Complexity: time complexity is O(n), space complexity is O(1).
#Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/851941/Python-O(n)-dynamic-programming-solution-explained 

class Solution:
    def maxProfit(self, nums):
        ans, dp = 0, 0
        for i in range(0, len(nums)-1):
            q = nums[i+1] - nums[i]
            dp = max(dp + q, q)
            ans = max(ans, dp)
        return ans

#A little faster
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # if len(prices) == 0:
        #     return 0
        # minIndex = 0
        # maxIndex = 0
        # for i in range(len(prices)):
        #     if maxIndex < minIndex or prices[i] > prices[maxIndex]:
        #         maxIndex = i
        #     if prices[i] < prices[minIndex]:
        #         minIndex = i
        # if prices[minIndex] > prices[maxIndex] or minIndex > maxIndex:
        #     return 0
        # return prices[maxIndex] - prices[minIndex]
        minIndex = 0
        maxProfit = 0
        for i in range(len(prices)):
            if prices[i] < prices[minIndex]:
                minIndex = i
            if prices[i] - prices[minIndex] > maxProfit:
                maxProfit = prices[i] - prices[minIndex]
        return maxProfit

#Faster
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        min_el = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            # check new min element
            if prices[i] < min_el:
                min_el = prices[i]
            
            # replace max profit
            if prices[i] - min_el > max_profit:
                max_profit = prices[i] - min_el
        return max_profit
