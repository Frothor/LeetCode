func combinationSum3(k int, n int) [][]int {
	if k < 1 || k > 9 {
		return [][]int{}
	}
	r, _ := dfs(1, k, n)
	return r
}

func dfs(start int, count int, summary int) ([][]int, bool) {
	if summary <= 0 {
		return nil, false
	}
	if count == 1 {
		if start <= summary && summary <= 9 {
			return [][]int{{summary}}, true
		}
		return nil, false
	}
	result := [][]int{}
	for i := start; i <= 10 - count; i++ {
		next, ok := dfs(i+1, count-1, summary-i)
		if ok {
			for _, n := range next {
				result = append(result, append([]int{i}, n...))
			}
		}
	}
	return result, len(result) > 0
}

//Most common --> memory usage
func combinationSum3(k int, n int) [][]int {
    res := make([][]int, 0)
    store := make([]int, 0)

    getComb(k,n,&res,&store,0)
    return res
}

func getComb(k int, n int, res *[][] int, store *[] int, i int) {
    if len(*store) == k && n==0 {
        temp := make([]int, k)
        copy(temp, *store)
        *res = append(*res, temp)
        return
    }
    if n < 0 || len(*store) == k {
        return
    }

    for j := i; j <9; j++ {
        *store = append(*store, j+1)
        getComb(k,n-j-1,res,store,j+1)
        *store = (*store) [:len(*store)-1]
    }
}

//Best --> memory usage
func combinationSum3(k int, n int) [][]int {
    
    res := make([][]int, 0)
    cur := make([]int, 0)
    
    helper(&res, &cur, k, n, 1, 0)
    return res
}   

func helper(res *[][]int, cur *[]int, k, n, start, curSum int) {
    if len(*cur) == k && curSum == n {
        temp := make([]int, k)
        copy(temp, *cur)
        *res = append(*res, temp)
    } else {
        for i := start; i <= 9; i ++ {
            curSum += i
            *cur = append(*cur, i)
            helper(res, cur, k, n, i+1, curSum)
            *cur = (*cur)[:len(*cur)-1]
            curSum -= i
        }
    }
}