//Third fastest
public class Solution {
    public int MaxProfit(int k, int[] prices) {
        if (k >= prices.Length / 2)
            {
                int maxProfit1 = 0;
                for (int i = 0; i < prices.Length - 1; i++)
                {
                    maxProfit1 += Math.Max(0, prices[i + 1] - prices[i]);
                }

                return maxProfit1;
            }

            int[,] maxProfit2 = new int[k + 1, prices.Length];

            for (int i = 1; i <= k; i++)    // Transactions
            {
                int minPrice = prices[0];

                for (int j = 1; j < prices.Length; j++)
                {
                    minPrice = Math.Min(minPrice, prices[j] - maxProfit2[i - 1, j - 1]);
                    maxProfit2[i, j] = Math.Max(maxProfit2[i, j - 1], prices[j] - minPrice);
                }
            }

            return maxProfit2[k, prices.Length - 1];
    }
}

//Second fastest
public class Solution {
    public int MaxProfit(int k, int[] prices) {
      int len = prices.Length;
      if(k > len/2) return QuickSolve(prices);
      var profit = new int[k+1, len];
      for(int i=1; i<=k;i++){
        int tempMax = -prices[0]; 
        for(int j=1; j<len;j++){
          profit[i,j] = Math.Max(profit[i,j-1], prices[j] + tempMax);
          tempMax = Math.Max(profit[i-1,j-1] - prices[j],tempMax);
        }
      }
      return profit[k,len-1];
    }
    private int QuickSolve(int[] prices){
      int len = prices.Length, profit = 0;
      for (int i = 1; i < len; i++){
          // as long as there is a price gap, we gain a profit.
          if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
      }
      return profit;
    }
}

//Fastest
public class Solution {
    public int MaxProfit(int k, int[] prices) {
        if (k >= prices.Length/2) {
            var profit = 0;
            
            for (var i = 1; i < prices.Length; i++) {
                if (prices[i] > prices[i-1]) {
                    profit += prices[i] - prices[i-1];
                }
            }
            
            return profit;
        }
        
        var dp = new int[k+1,prices.Length];
        
        for (var i = 1; i <= k; i++) {
            var buy = -prices[0];
            
            for (var j = 1; j < prices.Length; j++) {
                
                dp[i,j] = Math.Max(buy + prices[j], dp[i,j-1]);
                buy = Math.Max(buy, dp[i-1,j-1] - prices[j]);
                
            }
            
        }
        
        return dp[k,prices.Length - 1];
    }
}