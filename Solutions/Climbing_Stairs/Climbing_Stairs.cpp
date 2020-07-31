class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};

/*Another
class Solution {
public:
    unordered_map<int, int> memo;
    
    int climb(int cur, int top) {
        if(auto itr = memo.find(cur) != memo.end())
            return memo[cur];
        
        if(cur > top)
            return 0;
        else if(cur == top)
            return 1;
        
        memo[cur+1] = climb(cur+1, top);
        memo[cur+2] = climb(cur+2, top);

        return memo[cur+1] + memo[cur+2];            
    }
    
    int climbStairs(int n) {
        long long a[50]={0};
        if(n==1)
            return 1;
        if(n==2)
            return 2;
       a[1]=1;
        a[2]=2;
        
       for (int i = 3; i <= n; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
};
*/