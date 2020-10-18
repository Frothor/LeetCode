//Most common
func max(x, y int) int {
    if x < y { return y }
    return x
}
func maxProfit(prices []int) int {
    if len(prices) == 0 { return 0 }
    buy1 := -prices[0]
    sell1, sell2, buy2 := 0, 0, buy1
    for _,x := range prices[1:] {
        buy1 = max(-x, buy1)
        sell1 = max(buy1 + x, sell1)
        buy2 = max(sell1 - x, buy2)
        sell2 = max(buy2 + x, sell2)
    }
    return sell2
}

//Third fastest
func maxProfit(prices []int) int {
    n:=len(prices)
    if n==0{
        return 0
    }
    k:=2
    dp:=make([]int,n+1)
    rst:=0
    for i:=1;i<=k;i++{
        incr:=-prices[0]
        for j:=1;j<n;j++{
            prev:=dp[j]
            dp[j]=Max(dp[j-1],incr+prices[j])
            incr=Max(incr,prev-prices[j])
            rst=Max(rst,dp[j])
        }
    }
    return rst
}

func Max(x,y int)int{
    if x>y{
        return x
    }
    return y
}

//Second fastest
func maxProfit(prices []int) int {
    if len(prices) <= 1{
        return 0
    }
    left_profit := make([]int, len(prices))
    right_profit := make([]int, len(prices)+1)
    leftMin := prices[0]
    rightMax := prices[len(prices)-1]
    j := len(prices)-2
    for i := 1; i < len(prices); i++{
        leftMin = int(math.Min(float64(leftMin), float64(prices[i])))
        left_profit[i] = int(math.Max(float64(left_profit[i]-1), float64(prices[i]-leftMin)))
        
        rightMax = int(math.Max(float64(rightMax), float64(prices[j])))
        right_profit[j] = int(math.Max(float64(right_profit[j+1]), float64(rightMax -prices[j])))
        j--        
    }
    var profit int 
    for i := 0; i < len(prices); i++{
        profit = int(math.Max(float64(profit), float64(left_profit[i]+right_profit[i+1]))) 
    }
    return profit
}

//Fastest
func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}

	profit1 := make([]int, len(prices))
	profit2 := make([]int, len(prices))
	profit := 0

	// find profit from left to right
	pMin := prices[0]
	for i := 1; i < len(prices); i++ {
		if prices[i] < pMin {
			pMin = prices[i]
		}

		if prices[i]-pMin > profit {
			profit1[i] = prices[i] - pMin
			profit = prices[i] - pMin
		} else {
			profit1[i] = profit
		}
	}

	// find profit from right to left
	pMax := prices[len(prices)-1]
	profit = 0
	for i := len(prices) - 1; i >= 0; i-- {
		if prices[i] > pMax {
			pMax = prices[i]
		}
		if pMax-prices[i] > profit {
			profit2[i] = pMax - prices[i]
		} else {
			profit2[i] = profit
		}
	}

	maxProfit := 0
	for i := 0; i < len(prices); i++ {
		if profit1[i]+profit2[i] > maxProfit {
			maxProfit = profit1[i] + profit2[i]
		}
	}

	return maxProfit
}