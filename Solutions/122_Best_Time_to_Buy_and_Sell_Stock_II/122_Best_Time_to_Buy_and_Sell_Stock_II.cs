public class Solution {
    public int MaxProfit(int[] prices) {
        int n=prices.Length, profit=0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1])
                profit+=(prices[i+1]-prices[i]);
        }
        return profit;
    }
}

//Third fastest
public class Solution {
    public int MaxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int max = 0;
        while (i < prices.Length - 1) {
            while (i < prices.Length - 1 && prices[i] >= prices[i+1]) {
                i++;
            }
            valley = prices[i];
            while (i < prices.Length - 1 && prices[i] <= prices[i+1]) {
                i++;
            }
            peak = prices[i];
            max += peak-valley;
        }
        return max;
    }
}

//Second fastest
public class Solution
{
	public int MaxProfit(int[] prices)
	{
		int? startIndex = null;
		int profit =0;

		for(int i=0;i<prices.Length-1;i++)
		{
			if(prices[i]<prices[i+1])
			{
				startIndex = i;
				break;
			}
		}
		if(startIndex == null)
			return profit;

		int currentBuyPrice = prices[startIndex.Value];
		
		for(int i=startIndex.Value; i<prices.Length-1;i++)
		{

			if(prices[i] < prices[i + 1])
			{
				profit += prices[i+1] - prices[i];				
			}
		}
		
		return profit;
	}
}

//Fastest
public class Solution {
    public int MaxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int max = 0;
        while (i < prices.Length - 1) {
            while (i < prices.Length - 1 && prices[i] >= prices[i+1]) {
                i++;
            }
            valley = prices[i];
            while (i < prices.Length - 1 && prices[i] <= prices[i+1]) {
                i++;
            }
            peak = prices[i];
            max += peak-valley;
        }
        return max;
    }
}