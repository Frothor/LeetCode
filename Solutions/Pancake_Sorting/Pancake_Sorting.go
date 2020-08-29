func pancakeSort(A []int) []int {
	N := len(A)
	res := make([]int, N)
	for i := 0; i < len(res); i++ {
		res[i] = i + 1
	}
	sort.Slice(res, func(i, j int) bool {
		return A[res[i]-1] >= A[res[j]-1]
	})
	var ans []int
	for _, i := range res {
		for _, f := range ans {
			if i <= f {
				i = f + 1 - i
			}
		}
		ans = append(ans, i)
		ans = append(ans, N)
		N--
	}
	return ans
}