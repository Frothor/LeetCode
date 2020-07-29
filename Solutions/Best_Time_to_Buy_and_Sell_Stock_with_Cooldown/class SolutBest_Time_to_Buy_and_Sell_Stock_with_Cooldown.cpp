class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
        return 0;
        
        vector<vector<int>>dp(n,vector<int>(2,0));
    
        if(n==2 && prices[0]>prices[1])
        return 0;
        
        if(n==2 && prices[0]<=prices[1])
            return prices[1]-prices[0];
        
        //buy
        dp[0][0]= -prices[0];
        //sell
        dp[0][1]=  0;
        
        dp[1][0] = -1*min(prices[0], prices[1]);
        dp[1][1] = max(0, prices[1]-prices[0]);
        
        for(int i=2; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-2][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        
        return dp[n-1][1];
    }
};

/*
Most common:
class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n=price.size();
        if(n<2)
            return 0;
        int buy[n+1];
        int sell[n+1];
        buy[0]=0;
        buy[1]=-price[0];
        sell[0]=0;
        sell[1]=0;
        for(int i=2;i<=n;i++)
        {
            buy[i]=max(sell[i-2]-price[i-1],buy[i-1]);
            sell[i]=max(sell[i-1],buy[i-1]+price[i-1]);
        }
        return sell[n];
    }
};

Fastest:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;
        for (auto price : prices) {
            int preSold = sold;
            sold = held+price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }
        return max(sold, reset);
    }
};
*/