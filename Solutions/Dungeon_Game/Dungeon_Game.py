class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        r = len(dungeon)
        c = len(dungeon[0])
        ans = [[0]*c for i in range(r)]
        ans[r-1][c-1] = 1 if dungeon[r-1][c-1] > 0 else (1 - dungeon[r-1][c-1])
        
        for i in range(r-2, -1, -1):
            ans[i][c-1] = max(ans[i+1][c-1] - dungeon[i][c-1], 1)
        for j in range(c-2, -1, -1):
            ans[r-1][j] = max(ans[r-1][j+1] - dungeon[r-1][j], 1)
            
        for i in range(r-2, -1, -1):
            for j in range(c-2, -1, -1):
                ans[i][j] = max(min(ans[i+1][j], ans[i][j+1]) - dungeon[i][j], 1)
                
        return ans[0][0]
        
#Fastest:
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        if not dungeon:
            return 0
        
        num_row, num_col = len(dungeon), len(dungeon[0])
        dp = [float('inf')] * num_col
        dp[num_col - 1] = 1
        
        for row in reversed(range(num_row)):
            for col in reversed(range(num_col)):
                if row == num_row - 1 and col == num_col - 1:
                    dp[col] = max(1, 1 - dungeon[row][col])
                elif row == num_row - 1:
                    dp[col] = max(1, dp[col + 1] - dungeon[row][col])
                elif col == num_col - 1:
                    dp[col] = max(1, dp[col] - dungeon[row][col])
                else:
                    dp[col] = max(1, min(dp[col], dp[col + 1]) - dungeon[row][col])
        
        return dp[0]
        