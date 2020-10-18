//Third fastest
public class Solution {
    public int MaxProfit(int[] prices) {
        int maxProfit = 0;
        int minPrice = int.MaxValue;
        
        for(int i = 0; i < prices.Length; i++){
            minPrice = Math.Min(minPrice, prices[i]);
            maxProfit = Math.Max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
}

//Second fastest
public class Solution {
    public int MaxProfit(int[] prices) {
       int t_i10 = 0, t_i11 = int.MinValue;
        for(int i=0;i< prices.Length;i++){
            t_i10 = Math.Max(t_i10,t_i11 +prices[i]);
            t_i11 =Math.Max(t_i11, -prices[i]);
        }
        return t_i10;
    }

//Fastest
public class Solution {
    public int MaxProfit(int[] prices) {
        if(prices == null || prices.Length == 0)
            return 0;
        int profit = 0;
        int buy =  Int32.MaxValue;
        for(int i= 0; i < prices.Length; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else if(prices[i] - buy> profit){
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
}