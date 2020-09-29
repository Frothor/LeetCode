class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not s:
            return True
        n = len(s)
        DP = [False] * (n+1)
        DP[0] = True
        for i in range(1, n+1):
            for word in wordDict:
                len_word = len(word)
                if DP[i-1]:
                    if i-1+len_word <= n and s[i-1 : i-1+len_word] == word:
                        DP[i-1+len(word)] = True
        return DP[n]




#Fastest
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @lru_cache
        def helper(idx):
            if idx == len(s):
                return True
            if idx > len(s):
                return False
            
            for word in wordDict:
                if s.find(word, idx) == idx and helper(idx+len(word)) == True:
                        # Matched following words
                        return True
            return False
        return helper(0)