//Most common
import "sort"

func findPairs(nums []int, k int) int {
    if k < 0 {
        return 0
    }
    sort.Ints(nums)
    modified := make([]int,len(nums))
    for i := range nums {
        modified[i] = nums[i] - k
    }
    i, j := 0, 0
    count := 0
    used := make(map[int]bool)
    for i < len(modified) && j < len(nums) {
        if modified[i] == nums[j] && i != j {
            if _, ok := used[modified[i] + nums[j]]; !ok {
                count++
                used[modified[i] + nums[j]] = true
            }
        }
        if modified[i] < nums[j] {
            i++
        } else {
            j++
        }
    }
    return count
}

//Second fastest
func findPairs(nums []int, k int) int {
    if k < 0 || len(nums) <= 0 {
        return 0
    }
    
    m := make(map[int]int)
    for _, v := range nums {
        m[v]++
    }
    
    result := 0
    for key, _ := range m {
        if k == 0 && m[key] > 1 {
            result++
        }
        if k > 0 && m[key+k] > 0 {
            result++
        }
    }
    return result
}

//Fastest
func findPairs(nums []int, k int) int {
	sort.Ints(nums)

	m := make(map[string]bool)
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[j]-nums[i] == k {
				m[fmt.Sprintf("%d%d", nums[j], nums[i])] = true
			}

			if nums[j]-nums[i] > k {
				break
			}
		}
	}

	return len(m)
}

//Another fastest
func findPairs(nums []int, k int) int {
        
	var res int
	m := map[int]int{}
	
	for _, n := range nums {
			m[n]++
	}
	
	for n, count := range m {
			if k > 0 && m[k+n] != 0 {
					res++
			} else if k == 0 && count > 1 {
					res++
			}
	}
	
	return res
}