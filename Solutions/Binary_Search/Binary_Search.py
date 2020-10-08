class Solution:
    def search(self, nums, target):
        beg, end = 0, len(nums) - 1
        while beg <= end:
            mid = (beg + end)//2
            if nums[mid] == target: return mid
            if nums[mid] < target:
                beg = mid + 1
            else:
                end = mid - 1
        return -1

#Second fastest
class Solution:
    def search(self, nums: List[int], target: int) -> int:            
        l = 0
        r = len(nums)
        while l < r - 1:
            m = l + (r - l) // 2 
            if nums[m] > target:
                r = m
            else:
                l = m
        if nums[l] == target:
            return l
        else:
            return -1


#Fastest
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        left, right = 0, len(nums)-1
        
        while left <= right:
            pivot = left + ((right - left) >> 1)
            if nums[pivot] == target:
                return pivot
            if nums[pivot] < target:
                left = pivot + 1
            else:
                right = pivot - 1
                
        return -1