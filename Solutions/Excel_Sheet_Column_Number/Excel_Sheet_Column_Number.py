class Solution:
    def titleToNumber(self, s: str) -> int:
        return reduce(lambda a, x: a * 26 + ord(x) - 64, s, 0)


#Fastest
class Solution:
    def titleToNumber(self, s: str) -> int:
        n = 0
        while len(s):
            n, s = n * 26 + ord(s[0]) - 64, s[1:]
        return n

#Second Fastest
class Solution:
    def titleToNumber(self, s: str) -> int:
        # ord_A = ord('A')
        power = 1
        res = 0
        for l in reversed(s):
            res += (ord(l) - 64) * power
            power *= 26
            
        return res