class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit=0
        buy=prices[0]
        for i in range(1,len(prices)):
            if prices[i]>buy:
                profit+=prices[i]-buy
                buy=prices[i]
                
            else:
                buy=prices[i]
        return profit

#Fourth fastest
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = []
        for i in range(len(prices)-1):
            if prices[i+1] > prices[i]:
                ans.append(prices[i+1] - prices[i])
        return sum(ans)

#Third fastest
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, b-a) for a, b in zip(prices[:-1], prices[1:]))

#Second fastest
class Solution:
    def maxProfit(self, prices):
         
        if len(prices) == 0:
            return 0
        
        profit = 0
        for i in range(1,len(prices)):
            if (prices[i] - prices[i-1])>0:
                profit = profit+prices[i]-prices[i-1]
        return profit

#Fastest
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        profit = 0
        finalProfit = 0
        for i in range(1, len(prices)):
            if prices[i] <= prices[i-1]:
                minPrice = prices[i]
                finalProfit += profit
                profit = 0
            else:
                profit = prices[i] - minPrice
        return profit + finalProfit
