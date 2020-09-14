#Fastest
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return(0)
        
        dp = [0]*(len(nums))
        dp[0] = nums[0]
        
        for i in range(1,len(nums)):
            dp[i] = max(dp[i-1], nums[i] + (dp[i-2] if i > 1 else 0))
        return(dp[-1])

#Most common
class Solution:
    def td_recur_without_memo(self, nums, i):
        if i < 0:
            return 0
        return max(self.td_recur_without_memo(nums, i-1), self.td_recur_without_memo(nums, i-2) + nums[i])
    
    def recur_dp(self, nums, dp, i):
        if i < 0:
            return 0
        if dp[i] == -1:
            dp[i] = max(self.recur_dp(nums, dp, i-1), nums[i] + self.recur_dp(nums, dp, i-2))
        return dp[i]
    
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        # return self.td_recur_without_memo(nums, len(nums) - 1)
        dp = [-1 for i in range(n)]
        return self.recur_dp(nums, dp, n -1)
