func maxProfit(prices []int) int {
    var max, total int
    var min = prices[0]
    for i := 1; i < len(prices); i++  {
        if prices[i] < min {
            min = prices[i]
            max = 0
        } else {
            if prices[i] > max {
                max = prices[i]
            } 
            if max > min {
                total += max-min
                min, max = prices[i], 0
            }
        }
    }
    if max > min {
        total += max-min
    }
    return total
}

//Another
func maxProfit(prices []int) int {
    profit :=0
    for i := 0; i< len(prices)-1; i++ {
        if prices[i+1] > prices[i] {
            profit += prices[i+1] - prices[i]
        }
    }
    return profit
}

//Fastest
func maxProfit(prices []int) int {
	profit := 0
	cur := 0

	buy := prices[0]
	sold := prices[0]
	for _, price := range prices[1:] {
			if price < sold {
					profit += cur
					buy = price
					sold = math.MinInt32
					cur = 0
					continue
			}

			if price < buy {
					buy = price
					continue
			}

			if cur < price - buy {
					cur = price - buy
					sold = price
			}
	}

	profit += cur

	return profit
}