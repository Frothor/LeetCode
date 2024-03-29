# LeetCode 188 Best Time to Buy and Sell Stock IV
## [Python] O(nk) dynamic programming, explained

This problem is just extension of problem 123. **Best Time to Buy and Sell Stock III**

Explanations are exactly the same as problem 123: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/794633/Python-O(n)-solution-with-optimization-explained

**Complexity:** time and space complexity is `O(nk)`, space comlexity can be improved to `O(k)`

```python
class Solution:
    def maxProfit(self, k, prices):
        if len(prices) <= 1 or k == 0: return 0
        
        delta = [prices[i+1]-prices[i] for i in range (len(prices)-1)]
        B=[sum(delta) for _, delta in groupby(delta, key=lambda x: x < 0)]
        n = len(B) + 1

        if k > len(prices)//2: return sum(x for x in B if x > 0)
        
        dp = [[0]*(k+1) for _ in range(n-1)] 
        mp = [[0]*(k+1) for _ in range(n-1)] 

        dp[0][1], mp[0][1] = B[0], B[0]

        for i in range(1, n-1):
            for j in range(1, k+1):
                dp[i][j] = max(mp[i-1][j-1], dp[i-1][j]) + B[i]
                mp[i][j] = max(dp[i][j], mp[i-1][j])

        return max(mp[-1])
```
[Link to original solution](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/900151/Python-O(nk)-dynamic-programming-explained)

## Fully explained all buy and sell problems C++ || Recursive || Memoization || Minor difference

**To solve this problem just start from basic similar problem. After solving these peoblems we wil reach at final this problem.**

`I have discussed all the problems by recursive and memoization approach , so that everyone can figure out minor differences between the questions :)`

**Recursive Solution and memoize solutions:**

### 1. https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

**You can do at most one transaction**

```c++
class Solution {
public:
    int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int>> &v)
    {
        //if we have no stock or we have no chance of transaction(k=0)
        if(i>=prices.size()||k<=0) return 0;
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy)  //if we are buying then next time we will sell else next time we will buy
        {        //-prices[i], because bought stock of prices[i], expend money
            
           return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v)); 
        }
        else    //it's time to sell , now decrease k, we have done 1 transaction
        {       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
           return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(); 
        vector<vector<int>> v(n,vector<int> (2,-1));
        //passing here buy=1 because we will first buy then sell
        //we can do atmost k=1 transaction
        return find(prices,0,1,1,v);
    }
};
```

### 2. https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

**You can do as many transactions as you like**

```c++
class Solution {
public:
int find(int ind,vector<int> &v,bool buy,vector<vector<int>> &memo)
{    
    if(ind>=v.size()) return 0;
    if(memo[ind][buy]!=-1) return memo[ind][buy];
    
    if(buy) //if we are buying then next time we will sell else next time we will buy
    {      //-prices[i], because bought stock of prices[i], expend money, !buy because next time sell
        
       return memo[ind][buy]=max(-v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));  
    }
    else   //it's time to sell 
    {      //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
        
       return memo[ind][buy]=max(v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));  
    }
     
}
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int>> v(n+1,vector<int>(2,-1));
        //passing here buy=1 because we will first buy then sell 
        return find(0,prices,1,v); 
    }
};
```

### 3. https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

**You may complete at most two transactions.**

```c++
class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,vector<vector<vector<int>>> &memo)
    {   
        //if buy =1 means we have to buy now
        //else we have to sell now
        if(ind>=prices.size()||c>=2) return 0; //counter
        if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
            return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,memo),find(prices,ind+1,buy,c,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
            return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,memo),find(prices,ind+1,buy,c,memo));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        //here we can do maximum two transaction
        //Use 3-D vector because here three states i,k,buy/sell
        vector<vector<vector<int>>> memo(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
          
       return find(prices,0,1,0,memo); 
    }
};
```

### 4. https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

**You may complete at most k transactions.**

```c++
class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,int k,vector<vector<vector<int>>> &memo)
    {   //if buy =1 means we have to buy now
        //else we have to sell now
        if(ind>=prices.size()||c>=k) return 0; //counter
        
        else if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
         
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
        return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,k,memo),find(prices,ind+1,buy,c,k,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
        return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,k,memo),find(prices,ind+1,buy,c,k,memo));
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        
        //edge case we are not able to pick 2k points from n points, which means 
        //we will not reach the limit no matter how we try. 
        //if the price of day i arise, buy the stock in i-1th day and sell it at ith day.
        if (2 * k > prices.size()) {
            int res = 0;
            for (int i = 1; i < prices.size(); i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        
         //here we can do maximum k transaction
        vector<vector<vector<int>>> memo(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(prices,0,1,0,k,memo); 
    }
};
```

[Link to original post](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/900034/Fully-explained-all-buy-and-sell-problems-C%2B%2B-oror-Recursive-oror-Memoization-oror-Minor-difference)