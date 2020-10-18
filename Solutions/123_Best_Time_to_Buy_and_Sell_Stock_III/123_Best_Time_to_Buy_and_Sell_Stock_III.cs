//Fourth fastest
public class Solution {
    public int MaxProfit(int[] prices) {
if (prices.Length <= 1) return 0;

            if (prices.Length == 2)
            {
                if (prices[0] < prices[1])
                {
                    return prices[1] - prices[0];
                }
                else
                {
                    return 0;
                }
            }
            var len = prices.Length;            

            var prevNoStock = 0;
            var prevStock = prices[0] * -1;
        
            var prevSecondNoStock = 0;
            var prevSecondStock = int.MinValue;
            // 0 - no stock in hand
            // 1 = stock in hand

            for (int i = 1; i < len; i++)
            {
                prevNoStock = System.Math.Max(prevNoStock, prevStock + prices[i]);
                prevStock = System.Math.Max(prevStock, -1 * prices[i]);

                prevSecondStock = System.Math.Max(prevSecondStock, prevNoStock - prices[i]);
                prevSecondNoStock = System.Math.Max(prevSecondNoStock, prevSecondStock + prices[i]);
                
            }

            return prevSecondNoStock; 
    }
        public int[] maxProfitFromBegin(int[] prices)
        {
            var maxProfit = new int[prices.Length + 1];
            var minPrice = int.MaxValue;
            for (int i = 0; i < prices.Length; i++)
            {
                minPrice = System.Math.Min(minPrice, prices[i]);
                maxProfit[i + 1] = System.Math.Max(maxProfit[i], prices[i] - minPrice);
            }
            return maxProfit;
        }
        public int[] maxProfitFromEnd(int[] prices)
        {
            var maxProfit = new int[prices.Length + 1];
            var maxPrice = int.MinValue;
            for (int i = prices.Length - 1; i >= 0; i--)
            {
                maxPrice = System.Math.Max(maxPrice, prices[i]);
                maxProfit[i] = System.Math.Max(maxProfit[i + 1], maxPrice - prices[i]);
            }

            return maxProfit;
        }    
}

//Third fastest
public class Solution {
    public int MaxProfit(int[] prices) {
           if (prices.Length <= 1) return 0;

            if (prices.Length == 2)
            {
                if (prices[0] < prices[1])
                {
                    return prices[1] - prices[0];
                }
                else
                {
                    return 0;
                }
            }
            var len = prices.Length;

            var firstSell = 0;
            var firstBuy = prices[0] * -1;

            var secondSell = 0;
            var seconfBuy = int.MinValue;
            // 0 - no stock in hand
            // 1 = stock in hand

            for (int i = 1; i < len; i++)
            {
                firstSell = System.Math.Max(firstSell, firstBuy + prices[i]);
                firstBuy = System.Math.Max(firstBuy, -1 * prices[i]);

                seconfBuy = System.Math.Max(seconfBuy, firstSell - prices[i]);
                secondSell = System.Math.Max(secondSell, seconfBuy + prices[i]);

            }

            return secondSell;
    }
        public int[] maxProfitFromBegin(int[] prices)
        {
            var maxProfit = new int[prices.Length + 1];
            var minPrice = int.MaxValue;
            for (int i = 0; i < prices.Length; i++)
            {
                minPrice = System.Math.Min(minPrice, prices[i]);
                maxProfit[i + 1] = System.Math.Max(maxProfit[i], prices[i] - minPrice);
            }
            return maxProfit;
        }
        public int[] maxProfitFromEnd(int[] prices)
        {
            var maxProfit = new int[prices.Length + 1];
            var maxPrice = int.MinValue;
            for (int i = prices.Length - 1; i >= 0; i--)
            {
                maxPrice = System.Math.Max(maxPrice, prices[i]);
                maxProfit[i] = System.Math.Max(maxProfit[i + 1], maxPrice - prices[i]);
            }

            return maxProfit;
        }    
}

//Second fastest
public class Solution {
    public int MaxProfit(int[] prices) {
        if (prices == null)
            throw new ArgumentNullException("prices");
        
        var n = prices.Length;
        
        if (n < 2)
            return 0;
        
        var min = prices[0];
        var maxProfitsHead = new int[n];
        var maxProfitsTail = new int[n];
        maxProfitsHead[0] = 0;
        maxProfitsTail[n - 1] = 0;
        for (var i = 1; i < prices.Length; ++i) {
            var profit = prices[i] - min;
            maxProfitsHead[i] = Math.Max(maxProfitsHead[i - 1], profit);
            min = Math.Min(min, prices[i]);
        }
        
        var max = prices[n - 1];
        for (var i = n - 2; i >= 0; --i) {
            var profit = max - prices[i + 1];
            maxProfitsTail[i] = Math.Max(maxProfitsTail[i + 1], profit);
            max = Math.Max(max, prices[i + 1]);
        }
        
        var totalMax = 0;
        for (var i = 1; i < n; ++i)
            totalMax = Math.Max(totalMax, maxProfitsHead[i] + maxProfitsTail[i]);
        
        return totalMax;
    }
}

//Fastest
// Tag : Array, Dynamic Programming
public class Solution {
    public int MaxProfit(int[] prices) {
        
        var len = prices.Length;
        if (len <= 1 ) return 0;

        // get max profit by doing one transaction
        int[] profitsFirstRound = new int[len];
        int lowest = prices[0];
        int final_profits = 0;
        
        for (var i = 1; i < len; i++)
        {
            final_profits = Math.Max(final_profits, prices[i] - lowest);
            lowest = Math.Min(lowest, prices[i]);
            profitsFirstRound[i] = final_profits;
        }

        // get max profit by doing the second transaction;
        int highest = prices[len - 1];
        final_profits = 0;
        for (var i = len - 2; i >= 0; i--) {
            final_profits = Math.Max(final_profits,
                                     profitsFirstRound[i] + highest - prices[i]);
            highest = Math.Max(highest, prices[i]);
        }

        return final_profits;
    }
}