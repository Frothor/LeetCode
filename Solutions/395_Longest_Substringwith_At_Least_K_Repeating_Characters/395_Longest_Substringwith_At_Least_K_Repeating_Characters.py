#Second fastest
import collections

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        return self.helper(s, 0, len(s), k)
    
    
    def helper(self, s: str, start: int, end: int, k: int) -> int:
        if end - start < k:
            return 0
        
        counter = Counter(s[start:end])
        
        for m in range(start, end):
            if counter[s[m]] >= k:
                continue
        
            left = m
            while m < end and counter[s[m]] < k:
                m += 1
        
            return max(
                self.helper(s, start, left, k),
                self.helper(s, m, end, k)
            )
        
        return end - start

#Fastest
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) < k or k == 0 or not s:
            return 0
        longest = 0
        sCount = Counter(s)
        split_index = 0
        while split_index < len(s) and k <= sCount[s[split_index]]:
            split_index += 1
        if split_index == len(s):
            return len(s)
        
        left = self.longestSubstring(s[:split_index], k)
        while split_index < len(s) and sCount[s[split_index]] < k:
            split_index += 1
        right = self.longestSubstring(s[split_index:], k)
        return max(left, right)
