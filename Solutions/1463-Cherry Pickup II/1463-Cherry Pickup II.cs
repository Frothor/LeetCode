/*
Let dp[r, c1, c2] store maximum number of cheery we can collect if we start at row r, robot 1 in c1 and robot 2 in c2
When moving down a row, there is at most 9 possible ways: left, down, right for robot 1 and robot 2.
Time O(rowcol^2)
Space O(rowcol^2)
*/
//https://leetcode.com/problems/cherry-pickup-ii/discuss/664938/C-DP-with-comments
public class Solution {
    public int CherryPickup(int[][] grid)
        {
            int row = grid.Length, col = grid[0].Length;
            int?[,,] dp = new int?[row, col, col];
            return (int)dfs(grid, row, col, 0, 0, col-1, dp);
        }

        public int? dfs(int[][] grid, int row, int col, int currentRow, int c1, int c2, int?[,,] dp)
        {
            if (currentRow == row) return 0; //finished all rows
            if (dp[currentRow, c1, c2] != null) return dp[currentRow, c1, c2];
            int ans = 0;
            for (int i = -1; i <= 1; i++) //Given current c1 and c2, there are total of 9 possible steps
            {
                for(int j = -1; j <= 1; j++)
                {
                    int newC1 = c1 + i, newC2 = c2 + j;
                    if(newC1 >= 0 && newC1 < newC2 && newC2 < col) //edge check, optimized so robot1 is always left of robot2
                    {
                        ans = Math.Max(ans, (int)dfs(grid, row, col, currentRow + 1, newC1, newC2, dp));
                    }
                }
            }
			//We can only collect cheery once if c1 == c2
            dp[currentRow, c1, c2] = c1 == c2 ? ans + grid[currentRow][c1] : ans + grid[currentRow][c1] + grid[currentRow][c2]; 
            return dp[currentRow, c1, c2];
        }
}

//Second fastest
public class Solution {
    public int CherryPickup(int[][] grid) {
        if (grid.Length <= 0) return 0;
        
        int rows = grid.Length, cols = grid[0].Length;
        var dp = new int[rows,cols,cols];
        return PickCheries(grid, dp, rows, cols, 0, 0, cols-1);
    }
    
    int PickCheries(int[][] grid, int[,,] dp, int rows, int cols, 
                    int row, int col1, int col2) {
        
        if (dp[row,col1,col2] > 0) return dp[row,col1,col2];
        
        if (row + 1 == rows) {
            return grid[row][col1] + grid[row][col2];
        }
        
        int max = 0;
        for (int c1 = col1 - 1; c1 < col1 + 2; c1++) {
            for (int c2 = col2 - 1; c2 < col2 + 2; c2++) {
                if (c1 >= c2 || c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols) continue;
                max = Math.Max(max, PickCheries(grid, dp, rows, cols, row + 1, c1, c2));
            }
        }
        max += grid[row][col1] + grid[row][col2];
        dp[row,col1,col2] = max;
        return max;
    }
}

//Fastest
public class Solution {
    static int[] jDelta = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    static int[] kDelta = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    
    public int CherryPickup(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;
        
        int[][][] dp = new int[m][][];
        for (int i = 0; i < m; i++) {
            dp[i] = new int[n][];
            for (int j = 0; j < n; j++) {
                dp[i][j] = new int[n];
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        int max = -1;
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        for (int i = 1; i < m; i++) {            
            for (int j = 0; j <= i && j < n; j++) {
                for (int k = n-1; k >= n-1-i && k >= 0; k--) {
                    for (int d = 0; d < 9; d++) {
                        int j2 = j + jDelta[d];
                        int k2 = k + kDelta[d];
                        
                        if (0 <= j2 && j2 < n && j2 < i && 0 <= k2 && k2 < n && n-1-i < k2) {
                            int temp = dp[i-1][j2][k2] + grid[i][j];
                            if (j != k) {
                                //if not sharing cell
                                temp += grid[i][k];
                            }
                            
                            if (dp[i][j][k] == -1 || dp[i][j][k] < temp) {
                                dp[i][j][k] = temp;
                                if (i == m-1 && temp > max) {
                                    max = temp;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return max;
    }
}