class Solution:
    def repeatedSubstringPattern(self, s):
        N = len(s)
        for i in range(1, N//2+1):
            if N % i == 0 and s[:i]* (N//i) == s:
                return True
        return False


#Fastest
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        ss = (s + s)[1:-1]
        print(ss)
        print(s)
        return ss.find(s) != -1