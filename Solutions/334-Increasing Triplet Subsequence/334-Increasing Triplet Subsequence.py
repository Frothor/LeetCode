#https://leetcode.com/problems/increasing-triplet-subsequence/discuss/976393/Python-O(n)-solution-explained
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        a = [float("inf")]*2
        for elem in nums:
            if elem < a[0] : a[0] = elem
            if elem < a[1] and elem > a[0]: a[1] = elem
            if elem > a[1] : return True
        return False

#https://leetcode.com/problems/increasing-triplet-subsequence/discuss/976326/Python-O(n)-time-and-O(1)-space
class Solution:
    def increasingTriplet(self, A):
        left = mid = all_min = float('inf')
        for x in A:
            if x > mid:
                return True
            elif mid > x > left:
                mid = x
            elif x > all_min:
                left, mid = all_min, x
            elif x < all_min:
                all_min = x
        return False