class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if m == n:
	        return m
        difference = n - m
        msb = 1 << math.floor(math.log2(difference))
        bits_to_remove = (msb << 1) - 1
        return m & n & ~bits_to_remove

#Second fastest
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        return n if n <= m else self.rangeBitwiseAnd(m, n&(n-1))

#Fastest
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        while (m < n):
            n-=(n&-n)
        return n;
        