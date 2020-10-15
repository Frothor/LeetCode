func threeSum(nums []int) [][]int {
	var results [][]int
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue//To prevent the repeat
		}
		target, left, right := -nums[i], i+1, len(nums)-1
		for left < right {
			sum := nums[left] + nums[right]
			if sum == target {
				results = append(results, []int{nums[i], nums[left], nums[right]})
				left++
				right--
				for left < right && nums[left] == nums[left-1] {
					left++
				}
				for left < right && nums[right] == nums[right+1] {
					right--
				}
			} else if sum > target {
				right--
			} else if sum < target {
				left++
			}
		}
	}
	return results
}

//Third fastest
func threeSum(nums []int) [][]int {
	var ans [][]int

	if len(nums) == 0 {
		return ans
	}

	sort.Ints(nums)

	for i := 0; i < len(nums)-2; i++ {
		if i == 0 || nums[i] != nums[i-1] {
			find := 0 - nums[i]
			low := i + 1
			high := len(nums) - 1
			for low < high {
				if nums[low]+nums[high] == find {
					res := []int{nums[i], nums[low], nums[high]}
					ans = append(ans, res)

					for low < high && nums[low] == nums[low+1] {
						low++
					}

					for low < high && nums[high] == nums[high-1] {
						high--
					}
					low++
					high--
				} else if nums[low]+nums[high] > find {
					high--
				} else {
					low++
				}
			}

		}

	}
	return ans

}

//Second fastest
func threeSum(nums []int) (result [][]int) {
    sort.Ints(nums)
    
    for i := 0; i < len(nums) && nums[i] <= 0; i++ {
        low := i + 1
        high := len(nums)-1
        if i == 0 || nums[i] != nums[i-1] {
            for low < high {
                sum := nums[i] + nums[low] + nums[high]
                if sum < 0 || (low > i + 1 && nums[low] == nums[low-1]) {
                    low++
                } else if sum > 0 || (high < len(nums) - 1 && nums[high] == nums[high + 1]) {
                    high--
                } else {
                    result = append(result, []int{nums[i], nums[low], nums[high]})
                    low++
                    high--
                }
            }            
        }
    }
    
    return
}

//Fastest
import "sort"
import "fmt"

func threeSum(nums []int) [][]int {
    
    var res [][]int
    sort.Ints(nums)
    l := len(nums)
    for i:= 0; i<l; i++ {
        j := i+1
        k := l-1
        for ; j<k ; {
            if (nums[i] + nums[j] + nums[k]) < 0 {
                j++
            } else if (nums[i] + nums[j] + nums[k]) == 0 {
                res = append(res, []int{nums[i], nums[j], nums[k]})
                for ; j+1<l && nums[j] == nums[j+1]; j++ {
                    continue
                }
                j++
            } else {
                k--
            }
        }
        for ; i+1<l && nums[i] == nums[i+1]; i++ {
            continue
        }
    }
    return res
}