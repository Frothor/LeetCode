class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob_helper(nums):
            dp1, dp2 = 0, 0
            for num in nums:
                dp1, dp2 = dp2, max(dp1 + num, dp2)
            return dp2
        
        return max(nums[0] + rob_helper(nums[2:-1]), rob_helper(nums[1:]))

#Third fastest
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        elif len(nums) <= 3: return max(nums)
        a = (nums[0], nums[1])
        b = (max(nums[:2]), max(nums[1:3]))
        c = (max(nums[1], nums[0] + nums[2]), max(nums[2], nums[1] + nums[3]))
        for i in range(3, len(nums) - 1):
            a = b
            b = c
            c = (max(b[0], a[0] + nums[i]), max(b[1], a[1] + nums[i + 1]))
        return max(c)

#Second fastest
class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob(nums):
            now = prev = 0
            for n in nums:
                now, prev = max(now, prev + n), now
            return now
        return max(rob(nums[len(nums) != 1:]), rob(nums[:-1]))

#Fastest
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        if n <= 3:
            return max(nums)
        dp1 = [-1] * (n-1)
        dp2 = [-1] * n
        dp1[0] = nums[0]
        dp1[1] = max(nums[0], nums[1])
        for i in range(2, n-1):
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i])
        dp2[1] = nums[1]
        dp2[2] = max(nums[1], nums[2])
        for i in range(3, n):
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i])
            
        return max(dp1[-1], dp2[-1])