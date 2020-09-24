class Solution:
    def findTheDifference(self, s, t):
        return list((Counter(t) - Counter(s)).keys())[0]

#Most common
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ans=0
        for c in s:
            ans^=ord(c)
        for c in t:
            ans^=ord(c)
        return chr(ans)

#Fastest
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for i in range(97,97+26):
            if s.count(chr(i))!=t.count(chr(i)):
                return chr(i)