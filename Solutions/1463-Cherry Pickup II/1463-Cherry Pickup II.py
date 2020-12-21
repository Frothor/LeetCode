#https://leetcode.com/problems/cherry-pickup-ii/discuss/977632/Python-DFSor-Simple-Solution
#Python DFS
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        if grid == [[]]:
            return 0
        
        m = len(grid)
        n = len(grid[0])
        @lru_cache(None) #  Would get TLE without this
        def dfs(row, c1, c2):
            #  Base Case
            
            if c1 < 0 or c1 >= n or c2 < 0 or c2 >= n:
                return - float("inf")

            res = 0
            res += grid[row][c1] + grid[row][c2]
            
            if c1 == c2:  #   Robots are on the same cell so we subtract one value
                res -= grid[row][c1]
                
            if row < m - 1: #  Recursively calling dfs function
                res += max(dfs(row + 1, i, j)
                          for i in [c1 - 1, c1, c1 + 1]
                          for j in [c2 - 1, c2, c2 + 1])
                
            return res
        
        return dfs(0, 0, n - 1)


#Faster but not the fastest
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[[0]*(n+2) for _ in range(n+2)] for _ in range(m)]
        # dp[i][j][k]: max cherry when robot1 is on (i, j) and robot2 is on (i, k)
        dp[0][1][-2] = grid[0][0] + grid[0][-1]
        for row in range(1, m):
            for j in range(1, min(n, row+1)+1):
                for k in range(max(1, n-row), n+1):
                    dp[row][j][k] = grid[row][j-1] + (grid[row][k-1] if j != k else 0) + max(
                        dp[row-1][j-1][k-1],
                        dp[row-1][j-1][k],
                        dp[row-1][j-1][k+1],
                        dp[row-1][j][k-1],
                        dp[row-1][j][k],
                        dp[row-1][j][k+1],
                        dp[row-1][j+1][k-1],
                        dp[row-1][j+1][k],
                        dp[row-1][j+1][k+1]
                    ) 
        return max(max(i) for i in dp[-1])
