from sortedcontainers import SortedList

class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        SList = SortedList()
        for i in range(len(nums)):
            if i > k: SList.remove(nums[i-k-1])   
            pos1 = bisect_left(SList, nums[i] - t)
            pos2 = bisect_right(SList, nums[i] + t)
            
            if pos1 != pos2 and pos1 != len(SList): return True
            
            SList.add(nums[i])
        
        return False


#Most common
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        buckets = {}
        w = t + 1 # Divisible by 0
        if t < 0:
            return False
        for i in range(len(nums)):
            temp = nums[i]//w
            if buckets.get(temp, None) != None:
                return True
            if buckets.get(temp-1, None) and abs(nums[i] - buckets.get(temp-1)) < w:
                return True
            if buckets.get(temp+1, None) and abs(nums[i] - buckets.get(temp+1)) < w:
                return True
            buckets[temp] = nums[i]
            if i >= k:
                del buckets[nums[i-k]//w]
        return False

#Fastest
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0 or not nums or k <= 0:
            return False
        buckets = {}
        width = t + 1

        for i, n in enumerate(nums):
            buck = n // width
            if buck in buckets:
                return True
            buckets[buck] = n
            if buck+1 in buckets and (buckets[buck+1] - n) <= t:
                return True
            if buck-1 in buckets and (n - buckets[buck-1]) <= t:
                return True
            if i >= k:
                del buckets[nums[i - k] // width]
        return False