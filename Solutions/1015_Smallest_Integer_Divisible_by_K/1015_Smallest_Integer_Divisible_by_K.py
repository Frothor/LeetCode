#https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/948435/Python-Math-Pigeon-holes-explained
class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0: return -1
        rem, steps = 1, 1
        while rem % K != 0:
            rem = (rem*10 + 1) % K
            steps += 1
        return steps

#A little faster
class Solution:
    def smallestRepunitDivByK(self, K):
        if K % 2 == 0 or K % 5 == 0:
            return -1
        remainder = 1
        for digits in range(1, K+1):
            if remainder % K == 0:
                return digits
            remainder = ((10*remainder) + 1) % K