/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/942720/Golang-solution-beats-100
The basic idea is binary search

However the array is rotated, either left to middle or middle to right will be monotonically increasing

If left to middle is monotonically increasing and target is in the range, we can do binary search on the left side
if middle to right is monotonically increasing and target is in the range, we can do binary search on the right side
if left == middle, we could move left++ and repeat the process
*/
func search(nums []int, target int) bool {
    if len(nums) == 0 {
        return false
    }
    
    l := 0
    r := len(nums) - 1
    
    for l + 1 < r { 
        mid := (l + r) / 2
        if nums[mid] == target {
            return true
        }
        if nums[l] < nums[mid] {
            if nums[l] <= target && nums[mid] > target {
                r = mid
            } else {
                l = mid
            }
        } else if nums[l] > nums[mid] {
            if nums[mid] < target && nums[r] >= target {
                l = mid
            } else {
                r = mid
            }
        } else {
            l++
        }
    } 
    if nums[l] == target || nums[r] == target {
        return true
    } else {
        return false
    }
}

//Another
func search(nums []int, target int) bool {
    if len(nums) == 0 {
        return false
    }
    start := 0 
    end := len(nums) - 1
    for ; start + 1 < end ; {
        mid := start + (end - start)/2
        if nums[mid] == target {
            return true
        }
        if nums[mid] <= nums[end] {
            if nums[mid] == nums[end] {
                end--
            }else if target >= nums[mid] && target <= nums[end]{
                start = mid
            }else  {
                end = mid
            }
        }else{
            if target <= nums[mid] && target >= nums[start]{
                end = mid
            }else {
                start = mid
            }
        }
        
    }

    if nums[start] == target {
        return true
    }
    if nums[end] == target {
        return true
    }
    return false
}