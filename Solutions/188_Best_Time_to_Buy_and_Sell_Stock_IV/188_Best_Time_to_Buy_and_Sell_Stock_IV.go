//Third fastest
func maxProfit(k int, prices []int) int {
    if len(prices) == 0 || k == 0 {
        return 0
    }
    if (2 * k > len(prices)) {
        res := 0;
        for i := 1; i < len(prices); i++ {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
    // memo := make(map[string]int)
    
    
    m := [][][]int{}
    for i := 0; i <= k; i++{
        line := make([][]int, len(prices))
        for j := range line {
            line[j] = []int{-1,-1}
        }
        
        m = append(m, line)
    }
    return recursive(prices, 0, k, 0, m)
    // return iterativeSlow(k, prices)
}

func iterative(k int, prices []int) int {
    // current day, k transactions, prev stock day
    if len(prices) == 0 {
        return 0
    }
    
    dp := [][]int{}
    for i := 0; i <= k; i++ {
        column := make([]int, len(prices))
        for j := range column {
            column[j] = -1
            if i == 0 {
                column[j] = 0
            }
        }
        column[0] = 0
        dp = append(dp, column)
    }
    
    
    for i := 1; i < len(dp); i++ {
        maxDiff := -prices[0]
        for j := 1; j < len(dp[i]); j ++ {
            dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff)
            maxDiff = max(maxDiff, dp[i-1][j]-prices[j])
        }
    }
    // fmt.Println(dp)
    return dp[k][len(prices)-1]
}

func iterativeSlow(k int, prices []int) int {
    // current day, k transactions, prev stock day
    if len(prices) == 0 {
        return 0
    }

    dp := [][]int{}
    for i := 0; i <= k; i++ {
        column := make([]int, len(prices))
        for j := range column {
            column[j] = -1
            if i == 0 {
                column[j] = 0
            }
        }
        column[0] = 0
        dp = append(dp, column)
    }
    
    
    best := 0 
    for i := 1; i < len(dp); i ++ {
        for j := 1; j < len(dp[i]); j ++ {
            b := 0
            for x := 0 ; x < j; x++ {
                b = max(b, prices[j] + dp[i-1][x] - prices[x])
            }
            dp[i][j] = max(dp[i][j-1],b)
            best = max(best, dp[i][j])
        }
    }
    return best
}

//Second fastest and most common
// maxProfit is a solution that has
// O(n*k) time complexity and
// O(n) space complexity, where n=len(prices) and k=k.
func maxProfit(k int, prices []int) int {
    n := len(prices)
    
    if n <= 0 || k <= 0 {
        return 0
    }
            
    if 2*k >= n { // 2*k -> k-poins for buying and k-points for selling.
        maxDiff := 0
        for i := 1; i < n; i++ {
            maxDiff += max(prices[i]-prices[i-1], 0)
        }
        return maxDiff
    }
    
    dp := make([]int, n)
    for k > 0 {
        value := 0
        for i := 1; i < n; i++ {
            value = max(dp[i], value+prices[i]-prices[i-1])
            dp[i] = max(dp[i-1], value)
        }
        k--
    }
    return dp[n-1]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b

//Fastest
// maxProfit is a solution that has
// O(n*k) time complexity and
// O(n) space complexity, where n=len(prices) and k=k.
func maxProfit(k int, prices []int) int {
    n := len(prices)
    
    if n <= 0 || k <= 0 {
        return 0
    }
            
    if 2*k >= n {
        maxDiff := 0
        for i := 1; i < n; i++ {
            maxDiff += max(prices[i]-prices[i-1], 0)
        }
        return maxDiff
    }
    
    dp := make([]int, n)
    for k > 0 {
        val := 0
        for i := 1; i < n; i++ {
            val = max(dp[i], val+prices[i]-prices[i-1])
            dp[i] = max(dp[i-1], val)
        }
        k--
    }
    return dp[n-1]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}