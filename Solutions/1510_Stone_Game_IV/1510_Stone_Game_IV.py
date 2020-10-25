class Solution:
    def winnerSquareGame(self, n):
        
        @lru_cache(None)
        def dfs(state):
            if state == 0: return False
            for i in range(1, int(math.sqrt(state))+1):
                if not dfs(state - i*i): return True
            return False
        
        return dfs(n)

#Another
class Solution:
    dp = {}
    def winnerSquareGame(self, n: int) -> bool:
        if n in self.dp:
            return self.dp[n]
        if (n==0):
            return False
        self.dp[n] = any((not self.winnerSquareGame(n - i**2)) for i in range(int(n**0.5), 0, -1))
        return self.dp[n]

#Another
import math

class Solution:
    @lru_cache(None)
    def winnerSquareGame(self, n: int) -> bool:
        if n == 0:
            return False
        i = int(math.sqrt(n))
        while i >= 1:
            if self.winnerSquareGame(n-i*i) == False:
                return True
            i -= 1
        return False