class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        for(int i=0; i<=coins.size(); i++){
            for(int j=0; j<=amount; j++){
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + (j-coins[i-1] < 0 ? 0 : dp[i][j-coins[i-1]]);
            }
        }
        return dp[coins.size()][amount];
    }
};

/*
Fastest:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (const auto & c : coins) {
            for (int i = c; i <= amount; ++i) {
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};

Most common:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        	int n = coins.size();

		vector<int>res(amount+1,0);

		res[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j =coins[i]; j <= amount; j++) {
					res[j] =res[j]+res[j-coins[i]];
			}
		}

		return res[amount];
        
    }
};
*/