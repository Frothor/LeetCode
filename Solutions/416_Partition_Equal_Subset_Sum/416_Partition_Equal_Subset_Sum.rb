def can_partition(nums)
  sum = nums.inject(0, &:+)
  n = nums.size
  dp = Array.new(n+1) { Array.new(sum+1, false) }
  i = 0
  while i <= n
    dp[i][0] = true
    i+=1
  end
  i = 1
  while i <= n
    j = 1
    while j <= sum/2
      dp[i][j] = dp[i-1][j]
      if nums[i-1] <= j
        dp[i][j] |= dp[i-1][j-nums[i-1]]
      end
      j+=1
    end
    i+=1
  end
  j = sum/2
  return dp[n][j] == true && sum - j == j
end

#Second fastest
def can_partition(nums)
    return false if nums.sum % 2 == 1
    
    @memo = Array.new(nums.size) { Array.new(nums.sum / 2 + 1) }
    return dfs(nums, nums.sum / 2, 0)
end

def dfs(nums, sum, idx)
    return true if sum == 0
    return false if idx >= nums.size || sum < 0
    
    if (val = @memo[idx][sum]) != nil 
        return val
    end
    
    result = dfs(nums, sum - nums[idx], idx + 1) || dfs(nums, sum, idx + 1)
    @memo[idx][sum] = result
end