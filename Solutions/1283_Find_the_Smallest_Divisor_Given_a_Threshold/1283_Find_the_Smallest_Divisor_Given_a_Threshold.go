func smallestDivisor(nums []int, threshold int) int {
	l, r := 1, max(nums...)
	for l <= r {
		m := (l + r) >> 1
		v := helper(nums, m)
		if v <= threshold {
			r = m-1
		} else {
			l = m+1
		}
	}
	return l
}

func helper(nums []int, d int) int {
	summary := 0
	for _, v := range nums {
		summary += v / d
		if v % d != 0 {
			summary++
		}
	}
	return summary
}

func max(values ...int) int {
	maxValue := math.MinInt32
	for _, v := range values {
		if v > maxValue {
			maxValue = v
		}
	}
	return maxValue
}

//Third fastest
func smallestDivisor(nums []int, threshold int) int {
    max := 0
    for _, n := range nums {
        if n > max {
            max = n
        }
    }
    
    start, end := 1, max
    divisor := 0
    
    for start < end {
        sum := 0
        divisor = (end + start) / 2
        for _, n := range nums {
            sum += n / divisor
            if n % divisor > 0 {
                sum++
            }
            if sum > threshold {
                break
            }
        }
        
        if sum > threshold {
            start = divisor + 1
        } else {
            end = divisor
        }
    }
    
    return end
}

//Second fastest
func smallestDivisor(nums []int, threshold int) int {
    max := 0
    for _, n := range nums {
        if n > max {
            max = n
        }
    }
    
    start, end := 1, max
    divisor := 0
    
    for start < end {
        sum := 0
        divisor = (end + start) / 2
        for _, n := range nums {
            sum += int(math.Ceil(float64(n) / float64(divisor)))
            if sum > threshold {
                break
            }
        }
        
        if sum > threshold {
            start = divisor + 1
        } else {
            end = divisor
        }
    }
    
    return end
}

//Fastest
func smallestDivisor(nums []int, threshold int) int {
    max := 0
    for _, n := range nums {
        if n > max {
            max = n
        }
    }
    
    start, end := 1, max
    divisor := 0
    
    for start < end {
        sum := 0
        divisor = (end + start) / 2
        for _, n := range nums {
            sum += int(math.Ceil(float64(n) / float64(divisor)))
            if sum > threshold {
                break
            }
        }
        
        if sum > threshold {
            start = divisor + 1
        } else {
            end = divisor
        }
    }
    
    return end
}