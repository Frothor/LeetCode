func search(nums []int, target int) int {
    start := 0
    end := len(nums) - 1
    
    for start <= end {
        mid := (end + start) >> 1
        if nums[mid] == target {
            return mid
        } else if nums[mid] < target {
            start = mid + 1
        } else {
            end = mid - 1
        }
    }
    return -1
}

//Fastest
func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1

	for right >= left {
		midIdx := left + (right-left)/2
		midEl := nums[midIdx]
		if target == midEl {
			return midIdx
		}

		if target < midEl {
			right = midIdx - 1
			continue
		}

		if target > midEl {
			left = midIdx + 1
		}
	}

	return -1
}