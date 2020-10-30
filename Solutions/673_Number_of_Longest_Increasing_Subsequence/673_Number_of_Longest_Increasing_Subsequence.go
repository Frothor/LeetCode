//Most common
package main

// 300 lis using dp O(n*2)
// dp[i] = Max(dp[j] + 1) && j < i && nums[j] < nums[i] O(n*2)
// dp[0] = 1
func findNumberOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	dp := make([]int, len(nums), len(nums))
    lisNum := make([]int, len(nums), len(nums))
	for i := 0; i < len(dp); i ++ {
		dp[i] = 1
        lisNum[i] = 1
	}
	for i := 1; i < len(dp); i ++ {
		for j := 0; j < i; j ++ {
			if nums[j] < nums[i] {
                if dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1
                    lisNum[i] = lisNum[j]
                } else if dp[j] + 1 == dp[i] {
                    lisNum[i] = lisNum[i] + lisNum[j]
                }
			}
		}
	}
	
    count := 0
    val := 0
    for i := 0; i < len(dp); i ++ {
        if count < dp[i] {
            count = dp[i]
            val = lisNum[i]
        } else if count == dp[i] {
			val += lisNum[i]
		}  
    }
    return val
}

func max(a, b int) int {
	if a <= b {
		return b
	}
	return a
}

//Second fastest
func findNumberOfLIS(nums []int) int {
    length := len(nums)
    if length == 0 {
        return 0
    }
    dp := make([]int, length)
    re := make([]int, length)
    for i:=0;i<length;i++ {
        dp[i] = 1
        re[i] = 1
    }
    
    for i:=0;i<length;i++ {
        for j:=0;j<i;j++ {
            if nums[j] < nums[i] {
                if dp[i] < dp[j]+1 {
                    dp[i] = dp[j]+1
                    re[i] = re[j]
                }else if (dp[i] == dp[j]+1) {
                        re[i]+=re[j];
                }
              
            }
        }
    }
    
    res, temp := 0,0
    for i:=0;i<length;i++ {
        temp = max(temp, dp[i])
    }
    for i:=0;i<length;i++ {
        if temp == dp[i] {
            res +=re[i]
        }
    }
    return res
}

func max(i, j int) int {
    if i > j {
        return i
    }
    
    return j
}

//Fastest
func findNumberOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    curr:=[] [] [] int {}
    for i:=range(nums) {
        if len(curr) == 0 {
            curr = append(curr,[] [] int { [] int {nums[i],1}})
        } else {
            j:=0
            for j<len(curr) {
                if curr[j][len(curr[j])-1][0] < nums[i] {
                    j++
                } else {
                    break
                }
                
            }
            j--
            val:=0
            if j >= 0 {
                for k:=range(curr[j]) {
                    if curr[j][k][0]<nums[i] {
                        val+=curr[j][k][1]
                    }
                }
            } else {
                val = 1
            }
            //fmt.Println(j)
            if j == len(curr)-1 {
                curr = append(curr,[][]int{[] int {nums[i],val}})
            } else if  curr[j+1][len(curr[j+1])-1][0]>nums[i] {
                curr[j+1] = append(curr[j+1],[] int {nums[i],val})
            } else {
                curr[j+1][len(curr[j+1])-1][1]+=val
            }
        }
    }
    res:=0 
    for i:=range(curr[len(curr)-1]) {
        res+=curr[len(curr)-1][i][1]
    }
    return res
}
