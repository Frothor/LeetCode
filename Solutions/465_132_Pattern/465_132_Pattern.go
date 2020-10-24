//Most common
func find132pattern(nums []int) bool {
    n := len(nums)
    if n < 3 {
        return false
    }
    stack := make([]int, 0,n)
    min := make([]int, n)
    min[0] = nums[0]
    for i := 1; i < n; i++ {
        min[i] = Min(min[i-1], nums[i])
    }
    
    for j := n - 1; j >= 0; j-- {
        if nums[j] > min[j] {
            for len(stack) != 0 && stack[len(stack)-1] <= min[j] {
                stack = stack[0:len(stack)-1]
            }
            size := len(stack)
            if size != 0 && stack[size-1] < nums[j] {
                return true
            } 
            stack = append(stack, nums[j])
        }
    }
    return false
}

func Min(a, b int) int {
    if  a < b {
        return a
    }
    return b
}

//Second fastest
func find132pattern(nums []int) bool {
    n := len(nums)
    if n < 3 {
        return false
    }
    stack := make([]int, 0,n)
    min := make([]int, n)
    min[0] = nums[0]
    for i := 1; i < n; i++ {
        min[i] = Min(min[i-1], nums[i])
    }
    
    for j := n - 1; j >= 0; j-- {
        if nums[j] > min[j] {
            for len(stack) != 0 && stack[len(stack)-1] <= min[j] {
                stack = stack[0:len(stack)-1]
            }
            size := len(stack)
            if size != 0 && stack[size-1] < nums[j] {
                return true
            } 
            stack = append(stack, nums[j])
        }
    }
    return false
}

func Min(a, b int) int {
    if  a < b {
        return a
    }
    return b
}

//Fastest
func find132pattern(nums []int) bool {
	if len(nums) < 3 {
		return false
	}
	minL := make([]int, len(nums))
	min := nums[0]
	for i, v := range nums {
		if v < min {
			min = v
		}
		minL[i] = min
	}
	stack := make([]int, 0)
	for i := len(nums)-1; i >= 1; i-- {
        // if ≤ minL[i-1], ingore
		if nums[i] <= minL[i-1] {
			continue
		}
        // stack is empty, just append and continue
        if len(stack) == 0 {
            stack = append(stack, nums[i])
            continue
        }
		for len(stack) > 0 {
			if nums[i] > stack[len(stack)-1] {
				if stack[len(stack)-1] > minL[i-1] {
					return true
				}
				stack = stack[:len(stack)-1]
			} else {
				if nums[i] < stack[len(stack)-1] {
					stack = append(stack, nums[i])
				}
				break
			}
		}
        if len(stack) == 0 {
            stack = append(stack, nums[i])
        }
	}
	return false
}