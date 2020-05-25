class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int lenA = A.size(), lenB = B.size();
        vector<vector<int>> dp(lenA+1, vector<int>(lenB+1));
        
        for(int i=0; i<=lenA; ++i){
            for(int j =0; j<=lenB; ++j){
                if(i == 0 || j==0)
                    dp[i][j] = 0;
                else if(A[i-1]==B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[lenA][lenB];
        
    }
};

/*
Fastest:
class Solution {
public:
   int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
        return dp[m][n];
    }

};
*/