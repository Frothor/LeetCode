//Third fastest
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                res += (prices[i] - prices[i - 1]);
        return res;
    }
};

//Second fastest
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        
        int maxprofit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;

    }
};

//Fastest
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n=prices.size(),i,profit=0;
        for(i=0;i<n-1;i++){
            if(prices[i]<prices[i+1])
                profit+=(prices[i+1]-prices[i]);
        }
        return profit;
    }
};