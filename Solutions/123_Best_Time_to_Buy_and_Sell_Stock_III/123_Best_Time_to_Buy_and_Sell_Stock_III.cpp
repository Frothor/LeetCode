class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        
        int p1 = prices[0], p2 = prices[n-1];
        vector<int> profit1(n, 0), profit2(n, 0);
        
        for(int i = 1; i < n; i++){
            profit1[i] = max(profit1[i-1], prices[i] - p1);
            p1 = min(p1, prices[i]);
            
            int j = n - 1 - i;
            profit2[j] = max(profit2[j+1], p2 - prices[j]);
            p2 = max(p2, prices[j]);
        }
        
        int profit = 0;
        for(int i = 0; i < n; i++)
            profit = max(profit, profit1[i] + profit2[i]);
        return profit;
    }
};

//Somewhat faster
class Solution {
public:
    int maxProfit( vector<int>& a) {
        int i,n=a.size(),fb=INT_MIN,sb=INT_MIN,fs=0,ss=0;
        for(i=0;i<n;i++)
        {
            fb=max(fb,-a[i]);
            fs=max(fs,fb+a[i]);
            sb=max(sb,fs-a[i]);
            ss=max(ss,sb+a[i]);
        }
        return ss;
    }
};

//Fastest
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int debit_t1 = INT_MIN, credit_t1 = 0;
        int debit_t2 = INT_MIN, credit_t2 = 0;
        
        for(int i = 0; i < prices.size(); ++i){
            debit_t1 = max(debit_t1, -prices[i]);
            credit_t1 = max(credit_t1, debit_t1 + prices[i]);
            debit_t2 = max(debit_t2, credit_t1 - prices[i]);
            credit_t2 = max(credit_t2, debit_t2 + prices[i]);
        }
        
        return credit_t2;
        
//         int K = 2, offset = 0;
//         vector<int> debit(K, INT_MIN), credit(K);
//         for(int i = 0; i < prices.size(); ++i){
//             for(int k = 0, offset = 0; k < K; ++k){
//                 if(k > 0)
//                     offset = credit[k - 1]; //price offset
//                 debit[k] = max(debit[k], offset -prices[i]);
//                 credit[k] = max(credit[k], debit[k] + prices[i]);
//             }
//         }
        
//         return credit.back();
    }
};

//Second Fastest
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (2 >= prices.size()/2) {
            int res = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i-1]) 
                    res += std::max(prices[i] - prices[i-1], 0);
            return res;
        }

        int hold[2+1];
        int sell[2+1];
        for (int i=0; i<=2; ++i){
            hold[i] = INT_MIN;
            sell[i] = 0;
        }

        for (int i = 0; i < prices.size(); i++) {
            for (int j = 1; j <= 2; j++) {   
                sell[j] = std::max(sell[j], hold[j] + prices[i]);
                hold[j] = std::max(hold[j], sell[j-1] - prices[i]);

            }
        }
        return sell[2];
    }
};