#Third fastest
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        m = A[-1] - A[0]
        l = A[-1]-K
        for i in range(len(A)-1):
            f = min(A[i+1]-K, A[0]+K)
            if l < A[i]+K:
                l = A[i]+K
            if l - f < m:
                m = l - f
        return m

#Second fastest
from bisect import bisect
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        # A = sorted(set(A))
        A.sort()
        gap = A[-1]-A[0]
        if gap<=K: return gap
        if gap>=4*K: return gap - K*2

        for i in range(len(A) - 1):
            a, b = A[i], A[i+1]
            gap = min(gap, max(A[-1]-K, a+K) - min(A[0]+K, b-K))
        return gap

#Fastest
from bisect import bisect
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A = sorted(set(A))
        gap = A[-1]-A[0]
        if gap<=K: return gap
        if gap>=4*K: return gap - K*2

        for i in range(len(A) - 1):
            a, b = A[i], A[i+1]
            gap = min(gap, max(A[-1]-K, a+K) - min(A[0]+K, b-K))
        return gap