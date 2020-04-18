/*
LeetCode Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7

Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                    continue;
                } 
                
                if(i==0)
                {
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                    continue;
                }
                if(j==0)
                {
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                    continue;
                }
                
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
    }
};

/*Naive recursive solution. Runtime fail
class Solution {

int min_sum(vector<vector<int>>& grid, int y, int x) { 
   if (y < 0 || x < 0) 
      return INT_MAX; 
   else if (y == 0 && x == 0) 
      return grid[y][x]; 
   else
      return grid[y][x] + std::min(min_sum(grid, y - 1, x), min_sum(grid, y, x - 1)); 
} 
    
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rows = grid.size();
        if(rows == 0)
            return 0;
        
        int cols = grid[0].size();
        
        int min = min_sum(grid, rows - 1, cols - 1);
        
        return min;
    }
};*/