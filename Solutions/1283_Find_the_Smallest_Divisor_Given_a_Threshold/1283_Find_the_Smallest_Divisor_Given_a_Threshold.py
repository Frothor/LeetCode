'''
It this problem we need to find the smallest divisor, given a threshold. Notice, that this is perfect problem for binary search: we have row of answers for questions are we higher than threshold for given number? : no, no, no, ... no, yes, yes, ... yes and we need to find the place with first yes.

1. We define beg = 0, end = max(nums) + 1, so we know that answer for beg is no and we also know that answer for end is yes.
2. Look at the middle number: if answer is yes, it means, that we need to look at the right part: so you again have range with no in the beginning and yes in the end. If answer is no, we consider the second half.
3. Finally, we will find interval with size 2: no, yes, and we need to return end.

Complexity: time complexity is O(n log N), where n is lenght of nums and N is biggest number from nums. Space complexity is O(n).
'''

class Solution:
    def smallestDivisor(self, nums, threshold):
        beg, end = 0, max(nums) + 1
        while beg + 1 < end:
            mid = (beg + end)//2
            if sum(ceil(num/mid) for num in nums) <= threshold:
                end = mid
            else:
                beg = mid        
        return end

#Second fastest
from numpy import array, ceil, sum
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        nums=array(nums)
        left=0
        right=max(nums)
        while(left<right):
            mid=left+((right-left)//2)
            if sum(ceil(nums/mid))>threshold:
                left=mid+1
            else:
                right=mid
        return left

#Fastest
from numpy import array, ceil, sum

class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        nums = array(nums)
        left, right = 1, max(nums)
        while left + 1 < right:
            mid = (left + right) // 2
            sum_ = sum(ceil(nums / mid))
            if sum_ > threshold: left = mid
            else: right = mid
        sum_ = sum(ceil(nums / left))
        
        return left if sum_ <= threshold else right