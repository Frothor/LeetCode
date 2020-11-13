func permute(numbers []int) [][]int {
	backtracks := map[int]bool{}
	var f func(int, int, []int, [][]int) [][]int
	f = func(i, walked int, row []int, out [][]int) [][]int {
		if backtracks[i] {
			return out
		}
		backtracks[i] = true
		defer func() { backtracks[i] = false }()
		row = append(row, numbers[i])
		walked++
		if walked == len(numbers) {
			out = append(out, append([]int(nil), row...))
			return out
		}
		for j := 0; j < len(numbers); j++ {
			out = f(j, walked, row, out)
		}
		return out
	}
	out := [][]int{}
	for i := 0; i < len(numbers); i++ {
		out = f(i, 0, nil, out)
	}
	return out
}

//Another
var result [][]int

func permute(a []int) [][]int {
	result = [][]int{}
	permuteLocal(a, 0)
	return result
}

func permuteLocal(a []int, index int) {
	if len(a) == index {
		result = append(result, append([]int{}, a...))
	}
	for i := index; i < len(a); i++ {
		a[index], a[i] = a[i], a[index]
		permuteLocal(a, index+1)
		a[i], a[index] = a[index], a[i]
	}
}