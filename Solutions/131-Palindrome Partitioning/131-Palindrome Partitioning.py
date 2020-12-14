#Fourth fastest
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        mem = {}
        
        def part(string: str):
            if not string: return [[]]
            if mem.get(string, False): return mem[string]
            res = list()
            for i in range(len(string)):
                if string[:i+1] == string[i::-1]:
                    for a in part(string[i+1:]):
                        res.append([string[:i+1]]+a)
            mem[string] = res
            return res
        return part(s)
        

#Third fastest
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        pd = [[False] * n for _ in range(n)]
        for i in range(n-1):
            pd[i][i] = True
            if s[i] == s[i+1]: 
                pd[i][i+1] = True
        pd[n-1][n-1] = True
        # print(pd)
        for l in range(2, n):
            for i in range(n - l):
                pd[i][i+l] = pd[i+1][i+l-1] and s[i] == s[i + l]
        # print(pd)   
        
        def dfs(s, idx, curr, ans):
            if idx == n:
                # print(curr)
                ans.append(curr[:])
                # print(curr, ans)
                return
            
            for i in range(idx, n):
                if pd[idx][i]:
                    # print(idx, i, curr, ans)
                    curr.append(s[idx:i+1])
                    dfs(s, i+1, curr, ans)
                    # print(ans)
                    curr.pop()
        
        ans = []
        dfs(s, 0, [], ans)
        # if pd[0][n-1]: ans.append(s)
        # print(ans)
        return ans

#Second fastest
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        dp = [[False] * n for i in range(n)]
        res = [[] for i in range(n)]
        for i in range(n):
            for j in range(i+1):
                if s[i] == s[j] and (i - j <= 2 or dp[j+1][i-1]):
                    dp[j][i] = True
                    it = res[j-1] if j >0 else [[]]
                    substr = s[j:i+1]
                    for l in it:
                        res[i].append(l + [substr])
        return res[-1]

#Fastest
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s:
            return []
        
        dp = {0:[[]], 1:[[s[0]]]}
        
        for i in range(1, len(s)):
            dp[i+1] = []
            
            for j in range(0, i+1):
                if self.is_palindrome(s[j:i+1]):
                    for prev in dp[j]:
                        dp[i+1].append(prev + [s[j:i+1]])
        
        return dp[len(s)]
                
    
    def is_palindrome(self, s):
        re