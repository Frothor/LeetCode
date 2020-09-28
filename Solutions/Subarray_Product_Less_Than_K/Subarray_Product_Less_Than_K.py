#Sliding window
class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        out, beg, end, P = 0, 0, 0, 1
        while end < len(nums):
            P *= nums[end]
            while end >= beg and P >= k:
                P /= nums[beg]
                beg += 1
            out += end - beg + 1
            end += 1
        return out


//Fastest
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        # sliding window
        # move left while window product >= k
        # add (right - left + 1) if window < k
        
        if not nums or k <= 0:
            return 0
        
        n = len(nums)
        
        window = 1
        left = 0
        
        ret = 0
        
        for right in range(n):
            window *= nums[right]
            
            while left < right and window >= k:
                window //= nums[left]
                left += 1
            
            if window < k:
                ret += (right - left + 1)
        
        return ret