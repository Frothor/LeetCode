func maxProfit(prices []int) int {
	var max, result int
    if len(prices) > 1 {
        var min = prices[0]
        for i := 1; i < len(prices); i++ {
            if prices[i] < min {
                min = prices[i]
                max = 0
                continue
            } else {
                if prices[i] > max && prices[i] - min > result {
                    result = prices[i] - min
                }
            }
        }
    }
	return result
}


//Fastest
import "math"

func maxProfit(prices []int) int {
    
    b := math.MaxInt64
    ans := 0
    
    for i := range prices {
        if prices[i] < b {
            b = prices[i]
        } else if prices[i] - b > ans{
            ans = prices[i] - b
        }
    }
    
    return ans
}