func rob(nums []int) int {
    l := len(nums)
    if l < 1 {
        return 0
    } else if l == 1 {
        return nums[0]
    } else if l == 2 {
        return max(nums[0], nums[1])
    }
    // considering 1st element and ignoring last
    dp := make([]int, l)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    
    for i := 2; i < l-1; i++ {
        dp[i] = max(nums[i] + dp[i-2], dp[i-1])
    }
    
    // considering last element and ignoring 1st
    dps := make([]int, l)
    dps[0] = 0
    dps[1] = nums[1]
    for i := 2; i < l; i++ {
        dps[i] = max(nums[i] + dps[i-2], dps[i-1])
    }
    
    return max(dp[l-2], dps[l-1])
}


func max (a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}