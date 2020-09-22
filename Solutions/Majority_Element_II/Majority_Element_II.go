//Most common
func majorityElement(nums []int) []int {
	// since we are checking if a num appears more than 1/3 of the time
	// it is only possible to have at most 2 nums (>1/3 + >1/3 = >2/3)
	count1, count2, candidate1, candidate2 := 0, 0, 0, 1
	// Select Candidates
	for _, num := range nums {
		if num == candidate1 {
			count1++
		} else if num == candidate2 {
			count2++
		} else if count1 <= 0 {
			// We have a bad first candidate, replace!
			candidate1, count1 = num, 1
		} else if count2 <= 0 {
			// We have a bad second candidate, replace!
			candidate2, count2 = num, 1
		} else {
			// Both candidates suck, boo!
			count1--
			count2--
		}
	}
	// Recount!
	count1, count2 = 0, 0
	for _, num := range nums {
		if num == candidate1 {
			count1++
		} else if num == candidate2 {
			count2++
		}
	}
	length := len(nums)
	if count1 > length/3 && count2 > length/3 {
		return []int{candidate1, candidate2}
	}
	if count1 > length/3 {
		return []int{candidate1}
	}
	if count2 > length/3 {
		return []int{candidate2}
	}
	return []int{}
}

// func majorityElement(nums []int) []int {
//     if len(nums) <= 1{
//         return nums
//     }
//     sort.Ints(nums)
//     count := len(nums) / 3 + 1
//     res := []int{}
//     start := 0
//     for i := 1; i < len(nums); i++{
//         if nums[i] != nums[i-1]{
//             if i-start >= count{
//                 res = append(res, nums[i-1])
//             }
//             start = i
//         }
//     }
//     if len(nums)-start >= count{
//         res = append(res, nums[start])
//     }
//     return res
// }

// func majorityElement(nums []int) []int {
//     if len(nums) <= 1{
//         return nums
//     }
//     count := len(nums) / 3 + 1
//     record := make(map[int]int)
//     res := []int{}
//     for _, n := range nums{
//         record[n]++
//         if record[n] == count{
//             res = append(res, n)
//         }
//     }
//     return res
// }


//Fastest
func majorityElement(nums []int) []int {
    
    cm := make(map[int]int)
    
    cc := len(nums) / 3
    
    vv := []int{}
    
    for _, n := range nums {
        
        _, ok := cm[n]
        if ok {
            cm[n]++
        } else {
            cm[n] = 1
        }
    
    }
    
    for k, v := range cm {
        if v > cc {
            vv = append(vv, k)
        }
    }
    
    return vv
    
}