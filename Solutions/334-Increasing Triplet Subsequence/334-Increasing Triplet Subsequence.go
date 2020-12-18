//Second fastest
//https://leetcode.com/problems/increasing-triplet-subsequence/discuss/79019/Golang-solution
func increasingTriplet(nums []int) bool {
    min := 1<<31 - 1
    sMin := 1<<31 - 1
    for _, num:= range nums {
        if num <= min { min = num 
        } else if num <= sMin { sMin = num 
        } else { return true }
    }
    return false
}

//Another
func increasingTriplet(nums []int) bool {
    firstNumber := math.MaxInt64
    secondNumber := math.MaxInt64
    
    for _, num := range nums{
        if num <= firstNumber{
            firstNumber = num
        }else if num <= secondNumber{
            secondNumber = num
        }else{
            return true
        }
    }
    return false
}

//Fastest
func increasingTriplet(nums []int) bool {

    if len(nums) < 3 {
        return false
    }
    small := 2147483647 
    middle := 2147483647 
    for i := range nums {
        if nums[i] < small {
            small = nums[i]
        } else if nums[i] < middle && nums[i] > small {
            middle = nums[i]
        }
        if nums[i] > middle {
            
            return true
        }
    }
    fmt.Println(small,middle)
    return false
}