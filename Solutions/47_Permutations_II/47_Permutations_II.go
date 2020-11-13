//Second
func permuteUnique(nums []int) [][]int {

	sort.Ints(nums)

	return permuteWithSorted(nums)
}

func permuteWithSorted(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	if len(nums) == 1 {
		return [][]int{{nums[0]}}
	}

	res := make([][]int, 0, 1)
	for i := range nums {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		subNums := make([]int, 0, len(nums)-1)
		subNums = append(subNums, nums[:i]...)
		subNums = append(subNums, nums[i+1:]...)
		subPermutation := permuteWithSorted(subNums)
		for j := range subPermutation {
			res = append(res, append([]int{nums[i]}, subPermutation[j]...))
		}
	}
	return res
}

//Fastest
func permuteUnique(nums []int) [][]int {
	counter := make(map[int]int)
	for _, v := range nums {
		counter[v] += 1
	}
	results := [][]int{}
	back_track([]int{}, len(nums), &counter, &results)
	return results
}

func back_track(comb []int, n int, counter *map[int]int, results *[][]int) {
	if len(comb) == n {
		row := make([]int, n)
		copy(row, comb)
		*results = append(*results, row)
		return
	}
	c := *counter
	for num, count := range c {
		if count == 0 {
			continue
		}
		comb = append(comb, num)
		c[num] -= 1

		back_track(comb, n, counter, results)

		comb = comb[:len(comb)-1]
		c[num] += 1
	}
}