//The idea is, declaring two variables for tracking the minimum and the maximum product value. We need to keep track of minimum value for negative number. If the any ith (nums[i])number is a negative number then we need to swap between mimimun value and maximum value as in this case minimum value will be multiplied by a negative number and it will become a positive maximum value.
//For Deciding the min and max value in each iteration we have to look for the best option available means for max value we have to check maxvalue*nums[i] or nums[i] which is the max - which is the better option to choose similarly for the min value
//So basically it's dynamic programing problem where we have a take decision based upon previous reult and current option

func maxProduct(nums []int) int {
    minval := nums[0]
    maxval := nums[0]
    maxproduct := nums[0]
    for i := 1; i<len(nums); i++{
        if nums[i] < 0{
            minval, maxval = maxval, minval
        }
        minval = int(math.Min(float64(nums[i]),float64(minval*nums[i])))
        maxval = int(math.Max(float64(nums[i]),float64(maxval*nums[i])))
        if maxval > maxproduct{
            maxproduct = maxval
        }
    }
    return maxproduct
}