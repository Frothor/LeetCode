#Fourth fastest
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        from heapq import heapify, heappop
        
        if len(prices) < 2:
            return 0
        
        profits = []
        queue = []
        for i in range(1, len(prices)):
            p0, p1 = prices[i-1], prices[i]
            if p1 <= p0:
                continue
                
            while queue:
                q0, q1 = queue[-1]
                if p0 < q0:
                    profits.append(q0 - q1)
                    queue.pop()
                else:
                    break
            
            while queue:
                q0, q1 = queue[-1]
                if q0 <= p0 and q1 < p1:
                    if p0 - q1 < 0:
                        profits.append(p0 - q1)
                    p0, p1 = q0, p1
                    queue.pop()
                else:
                    break
                    
            queue.append((p0, p1))
            
        profits += [p0 - p1 for p0, p1 in queue]
        heapify(profits)
        
        answer = 0
        for _ in range(min(len(profits), k)):
            answer -= heappop(profits)
        return answer
        
    
    # Time: O(nk), Space: O(n+k)
    #
    # dp[i,k] = max(dp[j, k-1] - p[j]) + p[i]  for 0 <= j <= i
    # Keep track of max term as we go to turn quadratic into linear.
    # For each k, keep track of max profit and max diff.
    # 
    # Optimization: for huge k - since max number of trades is bound by n/2,
    # if k exceeds n/2 just make all profitable transactions.
    def maxProfit2(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if n / 2 <= k:
            return sum([max(prices[i+1]-prices[i], 0) for i in range(n-1)])
            
        dp = [[0, float('-inf')] for _ in range(k+1)]
        
        for price in prices:
            for j in range(1, k+1):
                profit, maxDiff = dp[j]
                dp[j][0] = max(profit, maxDiff + price)
                dp[j][1] = max(maxDiff, dp[j-1][0] - price)
        
        return dp[-1][0]

#Third fastest
class Solution:
    #Version 1: 1D DP
    #TC: O(nk), SC: O(n)
    '''
    def maxProfit(self, k: int, prices: List[int]) -> int:
        def unlimit():
            return sum([max(prices[i] - prices[i-1], 0) for i in range(1, n)])
        
        if not prices or not k:
            return 0
        n = len(prices)
        if k >= n//2:
            return unlimit()
        dp = [0]*n
        for i in range(1, k+1):
            nextDp = [0]*n
            val = dp[0] - prices[0]
            for j in range(n):
                nextDp[j] = max(nextDp[j-1], val + prices[j])
                val = max(val, dp[j] - prices[j])
            dp = nextDp
        return dp[-1]        
    '''
    
    #Version 2: Use variable for every states
    #TC: O(nk), SC: O(k)
    '''
    def maxProfit(self, k: int, prices: List[int]) -> int:
        def unlimit():
            return sum([max(prices[i] - prices[i-1], 0) for i in range(1, n)])
        
        if not prices or not k:
            return 0
        n = len(prices)
        if k >= n//2:
            return unlimit()
        
        buy = [float('inf')]*(k+1)
        sell = [float('-inf')]*(k+1)
        buy[0] = sell[0] = 0
        for num in prices:
            for i in range(1, k+1):
                buy[i] = min(buy[i], num - sell[i-1])
                sell[i] = max(sell[i], num - buy[i])
        return sell[-1]
    '''
    
    #Version 3: Use variable for every states
    #TC: O(nk), SC: O(k)
    '''
    def maxProfit(self, k: int, prices: List[int]) -> int:
        def unlimit():
            return sum([max(prices[i] - prices[i-1], 0) for i in range(1, n)])
        
        if not prices or not k:
            return 0
        n = len(prices)
        if k >= n//2:
            return unlimit()
        
        buy = [float('-inf')]*(k+1)
        sell = [float('-inf')]*(k+1)
        buy[0] = sell[0] = 0
        for num in prices:
            for i in range(1, k+1):
                buy[i] = max(buy[i], sell[i-1] - num)
                sell[i] = max(sell[i], num + buy[i])
        return sell[-1]
    '''
    
    #Version 4: Heap and Stack
    #Let's say we have two pairs of vally and peak. (v1, p1), (v2, p2), v1 < p2 < v2 < p2
    #1. If prices[v2] < prices[v1], for those vallay peak pair which can combine with (v1, p1) can also combine with (v2, p2). Further, it can earn more money by combining with (v2, p2).
    #Therefore, we can pop (v1, p1) pair from the stack.
    #2. If prices[p2] > prices[p1] and prices[v2] >= prices[v1], there is an overlap between these two pairs.
    #If we consider one transaction only, we would have prices[p2] - prices[v1]
    #For two transactions, we would have (prices[p1] - prices[v1]) + (prices[p2] - prices[v2]), in order to get the most beneficial result, we can reorder the profit to be (prices[p2] - prices[v1]) + (prices[p1] - prices[v2]) two transactions.
    #In this way, if we would like to have two transaction here, we can pick both of them, and we can also get the biggest profit for one transaction case.
    #TC: O(n + klogn), SC: O(n)
    #https://leetcode.wang/leetcode-188-Best-Time-to-Buy-and-Sell-StockIV.html
    def maxProfit(self, k: int, prices: List[int]) -> int:
        import heapq
        profit = []
        stack = []
        v = p = 0
        n = len(prices)
        while p < n:
            v = p
            while v+1 < n and prices[v] >= prices[v+1]:
                v += 1
            p = v
            while p+1 < n and prices[p] <= prices[p+1]:
                p += 1
            
            while stack and prices[v] < prices[stack[-1][0]]:
                heapq.heappush(profit, - (prices[stack[-1][1]] - prices[stack[-1][0]]))
                stack.pop()
            
            while stack and prices[p] > prices[stack[-1][1]]:
                heapq.heappush(profit, - (prices[stack[-1][1]] - prices[v]))
                v = stack[-1][0]
                stack.pop()
            if p == v:
                break
            
            stack.append([v, p])
        #print(stack)
        
        while stack:
            src, dst = stack.pop()
            heapq.heappush(profit, -(prices[dst] - prices[src]))
        
        ans = 0
        while k > 0 and profit: 
            ans -= heapq.heappop(profit)
            k -= 1
        return ans

#Second fastest
import heapq

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        N = len(prices)
        res = 0
        
        if not prices or not k: return 0
        
        valleys, peaks, profits = [], [], []
        start = end = 0
        
        while end < N:
            start = end
            
            while start < N - 1 and prices[start + 1] <= prices[start]: start += 1
                
            end = start + 1
        
            while end < N - 1 and prices[end + 1] >= prices[end]: end += 1
                                
            if start < end and end < N:
                while valleys and prices[valleys[-1]] > prices[start]:
                    profits.append(prices[valleys.pop()] - prices[peaks.pop()])

                while valleys and prices[peaks[-1]] <= prices[end]:
                    profits.append(prices[start] - prices[peaks.pop()])
                    start = valleys.pop()
                
                valleys.append(start)
                peaks.append(end)
            
        while valleys: profits.append(prices[valleys.pop()] - prices[peaks.pop()])
            
        heapq.heapify(profits)
        cnt = 0
        
        print(profits)
        
        while profits and cnt < k: 
            res += -heapq.heappop(profits)
            cnt += 1
            
        return res
                


#Fastest
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        from heapq import heapify, heappop
        
        if len(prices) < 2:
            return 0
        
        profits = []
        queue = []
        for i in range(1, len(prices)):
            p0, p1 = prices[i-1], prices[i]
            if p1 <= p0:
                continue
                
            while queue:
                q0, q1 = queue[-1]
                if p0 < q0:
                    profits.append(q0 - q1)
                    queue.pop()
                else:
                    break
            
            while queue:
                q0, q1 = queue[-1]
                if q0 <= p0 and q1 < p1:
                    if p0 - q1 < 0:
                        profits.append(p0 - q1)
                    p0, p1 = q0, p1
                    queue.pop()
                else:
                    break
                    
            queue.append((p0, p1))
            
        profits += [p0 - p1 for p0, p1 in queue]
        heapify(profits)
        
        answer = 0
        for _ in range(min(len(profits), k)):
            answer -= heappop(profits)
        return answer
        
    
    # Time: O(nk), Space: O(n+k)
    #
    # dp[i,k] = max(dp[j, k-1] - p[j]) + p[i]  for 0 <= j <= i
    # Keep track of max term as we go to turn quadratic into linear.
    # For each k, keep track of max profit and max diff.
    # 
    # Optimization: for huge k - since max number of trades is bound by n/2,
    # if k exceeds n/2 just make all profitable transactions.
    def maxProfit2(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if n / 2 <= k:
            return sum([max(prices[i+1]-prices[i], 0) for i in range(n-1)])
            
        dp = [[0, float('-inf')] for _ in range(k+1)]
        
        for price in prices:
            for j in range(1, k+1):
                profit, maxDiff = dp[j]
                dp[j][0] = max(profit, maxDiff + price)
                dp[j][1] = max(maxDiff, dp[j-1][0] - price)
        
        return dp[-1][0]