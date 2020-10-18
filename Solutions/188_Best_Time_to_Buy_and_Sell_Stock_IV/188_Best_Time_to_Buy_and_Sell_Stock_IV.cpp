class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0||n==1 ||k==0){
            return 0;
        }
		//this is for u can do as many as transaction u can do ....
        if(k >= n/2){ 
            int prof = 0;
            for(int i=1;i<n;i++){
                
                if(prices[i]>prices[i-1])
                    prof +=prices[i]-prices[i-1];
            }
            return prof;
        }
        int dp[k+1][n];
        memset(dp , 0 , sizeof(dp));
        // for 1<=k<n/2
        for(int i=1;i<k+1;i++){
            int maxprofitbefore  = INT_MIN;
            for(int j=1;j<n;j++){
                maxprofitbefore = max(maxprofitbefore , dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j]+maxprofitbefore);
            }
        }
        /*for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cout<< dp[i][j]<<" ";
            }cout<<endl;
        }*/
        return dp[k][n-1];   
    }
};

//Second fastest
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) return 0;
        int n = prices.size();
        if(k >= n/2){
            //same as infinite transactions
            int max_profit = 0;
            for(int i=1; i<n; i++){
                max_profit += max(0, prices[i] - prices[i-1]);
            }
            
            return max_profit;
        }
        else{
            //allow at max k transactions
            // vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, INT_MIN)));
            int dp[n][k+1][2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= k; j++) {
                    dp[i][j][0] = -1000000000;
                    dp[i][j][1] = -1000000000;
                }
            }
            dp[0][0][0] = 0;
            dp[0][1][1] = -prices[0];
            
            for(int i=1; i<n; i++){
                for(int j=0; j<=k; j++){
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                    if(j > 0)
                        dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                }
            }
            
            int max_profit = 0;
            for(int j=0; j<=k; j++) max_profit = max(max_profit, dp[n-1][j][0]);
            // return dp[n-1][k][0];
            return max_profit;
        }
    }
};


//Fastest
	// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        vector<int> profits;
        vector<pair<int, int>> v_p_stk;  // mono stack, where v is increasing and p is strictly decreasing
        for (int v = -1, p = -1; p + 1 < size(prices);) { // at most O(n) peaks, so v_p_stk and profits are both at most O(n) space
            for (v = p + 1; v + 1 < size(prices); ++v) {
                if (prices[v] < prices[v + 1]) {
                    break;
                }
            }
            for (p = v; p + 1 < size(prices); ++p) {
                if (prices[p] > prices[p + 1]) {
                    break;
                }
            }
            while (!empty(v_p_stk) && (prices[v_p_stk.back().first] > prices[v])) {  // not overlapped
                const auto [v, p] = move(v_p_stk.back()); v_p_stk.pop_back();
                profits.emplace_back(prices[p] - prices[v]);  // count [prices[v], prices[p]] interval
            }
            while (!empty(v_p_stk) && (prices[v_p_stk.back().second] <= prices[p])) {  // overlapped
                // prices[last_v] <= prices[v] <= prices[last_p] <= prices[p],
                // treat overlapped as [prices[v], prices[last_p]], [prices[last_v], prices[p]] intervals due to invariant max profit
                const auto [last_v, last_p] = move(v_p_stk.back()); v_p_stk.pop_back();
                profits.emplace_back(prices[last_p] - prices[v]);  // count [prices[v], prices[last_p]] interval
                v = last_v;  
            }
            v_p_stk.emplace_back(v, p);  // keep [prices[last_v], prices[p]] interval to check overlapped
        }        
        while (!empty(v_p_stk))  {
            const auto [v, p] = move(v_p_stk.back()); v_p_stk.pop_back();
            profits.emplace_back(prices[p] - prices[v]);  // count [prices[v], prices[p]] interval
        }
        if (k > size(profits)) {
            k = size(profits);
        } else {
            nth_element(begin(profits), begin(profits) + k, end(profits), greater<int>());
        }
        return accumulate(cbegin(profits), cbegin(profits) + k, 0);  // top k profits of nonoverlapped intervals
    }
};