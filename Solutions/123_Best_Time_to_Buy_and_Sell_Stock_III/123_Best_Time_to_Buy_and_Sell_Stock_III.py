class Solution:
    def maxProfit(self, arr: List[int]) -> int:
        
        if len(arr)<=1:
            return 0
        
        fb=float('-inf')
        fs=float('-inf')
        sb=float('-inf')
        ss=float('-inf')
        
        for i in arr:
            fb=max(fb,-i)
            fs=max(fs,fb+i)
            sb=max(sb,fs-i)
            ss=max(ss,sb+i)
            
        return ss

#Second fastest
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        forward, backward = [0] * len(prices), [0] * len(prices)

        mincost, profit = 2 ** 32, 0
        for i in range(len(prices)):
            if prices[i] < mincost:
                mincost = prices[i]
            else:
                profit = max(profit, prices[i] - mincost)
            forward[i] = profit
        
        maxcost, profit = -(2 ** 32), 0
        for i in reversed(range(len(prices))):
            if prices[i] > maxcost:
                maxcost = prices[i]
            else:
                profit = max(profit, maxcost - prices[i])
            backward[i] = profit
        
        res = 0
        for i in range(len(prices)-1):
            res = max(res, forward[i] + backward[i+1])
        return max(res, forward[-1], backward[0])


#Fastest
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret = self.maxProfit1(prices)
        if ret is None:
            return 0
        if len(prices) < 4:
            return prices[ret[1]]-prices[ret[0]]
        ret2 = (self.maxProfit1(prices[:ret[0]]), \
        self.maxProfit1([-pp for pp in prices[ret[0]+1:ret[1]]]), self.maxProfit1(prices[ret[1]+1:]))
        profit2 = [0, 0, 0]
        if ret2[0]:
            profit2[0] = prices[ret2[0][1]]-prices[ret2[0][0]]
        if ret2[1]:
            profit2[1] = prices[ret2[1][0]+ret[0]+1]-prices[ret2[1][1]+ret[0]+1]
        if ret2[2]:
            profit2[2] = prices[ret2[2][1]+ret[1]+1]-prices[ret2[2][0]+ret[1]+1]
        return prices[ret[1]]-prices[ret[0]]+max(profit2)
    
    def maxProfit1(self, prices):
        if not prices or len(prices)==1: return None
        if len(prices) == 2:
            return (0, 1) if prices[1]>prices[0] else None
        myMin, myMax = prices[0], 0
        myIn = 0
        ret = None
        for i in range(1, len(prices)):
            if prices[i]-myMin > myMax:
                myMax = prices[i]-myMin
                ret = (myIn, i)
            if prices[i] < myMin:
                myIn = i
                myMin = prices[i]
        return ret