func rob(nums []int) int {
	dp := map[int]int{}
	for i := 0; i < len(nums); i++ {
		dp[i] = int(math.Max(float64(dp[i-2]+nums[i]), float64(dp[i-1])))
	}
	return dp[len(nums)-1]
}