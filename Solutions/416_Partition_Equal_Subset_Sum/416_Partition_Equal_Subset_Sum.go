//https://leetcode.com/problems/partition-equal-subset-sum/discuss/309715/golang
func canPartition(nums []int) bool {
	if len(nums) <= 1 {
		return false
	}
	sum := 0
	for _, num := range nums {
		sum += num
	}

	if sum%2 == 1 {
		return false
	}
	target := sum / 2
	dp := make([]bool, target+1)
	dp[0] = true
	for _, num := range nums {
		for i := target; i >= 1; i-- {
			if i-num >= 0 && dp[i-num] {
				dp[i] = true
				if i == target {
					return true
				}
			}
		}
	}

	return false
}

//Another
func canPartition(nums []int) bool {
	var sum int
	for _, num := range nums {
		sum += num
	}
	if sum%2 == 1 {
		return false
	}
	sum = sum / 2

	dp := make([]bool, sum+1)
	dp[0] = true
	for _, num := range nums {
        if dp[sum]{
            return true
        }
		for j := sum; j > 0; j-- {
			if j >= num && dp[j-num] {
				dp[j] = true
			}
		}
	}
	return dp[sum]
}

//Second fastest
unc canPartition(nums []int) bool {
    var sum int
    for _, n := range nums {
        sum += n
    }
    
    if sum%2 != 0 {
        return false
    }
    
    cache := make(map[int]bool)
    return partition(nums, 0, sum/2, cache)
}

func partition(nums []int, i int, target int, cache map[int]bool) bool {
    if i == len(nums) {
        return false
    }
    if target == 0 {
        return true
    }
    
    k := key(i, target)
    if v, ok := cache[k]; ok {
        return v
    }
 
    diff := target - nums[i]
    if diff >= 0 {
        if partition(nums, i+1, diff, cache) {
            cache[k] = true
            return true
        }
    }
    
    if partition(nums, i+1, target, cache) {
        cache[k] = true
        return true
    }
    
    cache[k] = false
    return false
}

func key(i, target int) int {
    return i*100 + target
}
// 5
// 11
// 5, 11

// 5
// 5, 11
// 5, 5
// 5, 11, 5

// [1,5,11,5]
// [1,5,11,5]
// [1,5,11,5]

//Fastest
func canPartition(nums []int) bool {
    sum := 0
    for _, v := range nums {
        sum += v
    }
    if sum%2 != 0 {
        return false
    }
    sum /= 2
    return dfs(nums, 0, sum)
}

func dfs(nums []int, idx int, target int) bool {
    if target == 0 {
        return true
    }
    if idx == len(nums) || target < 0 {
        return false
    }
    if dfs(nums, idx+1, target-nums[idx]) {
        return true
    }
    k := idx+1
    for k<len(nums) && nums[idx] == nums[k] {
        k++
    }
    return dfs(nums, k, target)
}