class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int min_v = prices[0], ans = 0;
        for(int i = 1; i < prices.size(); i ++){
            ans = max(ans, prices[i] - min_v);
            min_v = min(min_v, prices[i]);
        }
        return ans;
    }
};