func firstMissingPositive(numbers []int) int {
	for i := 0; i < len(numbers); i++ {
		for numbers[i] > 0 && numbers[i] <= len(numbers) && numbers[numbers[i]-1] != numbers[i] {
			numbers[numbers[i]-1], numbers[i] = numbers[i], numbers[numbers[i]-1]
		}
	}
	for i := 1; i <= len(numbers); i++ {
		if numbers[i-1] != i {
			return i
		}
	}
	return len(numbers) + 1
}

//Another
func firstMissingPositive(nums []int) int {
	sort.Ints(nums)
	i := 0
	for ; i < len(nums); i++ {
		if nums[i] <= 0 {
			continue
		} else {
			break
		}
	}
	if i == len(nums) {
		// no element found. return 1
		return 1
	}
	// positive element found, either start search or return 1
	if nums[i] > 1 {
		return 1
	}
	i++
	for ; i < len(nums); i++ {
		if nums[i]-nums[i-1] > 1 {
			return nums[i-1] + 1
		}
	}
	// return last+1
	return nums[len(nums)-1] + 1
}