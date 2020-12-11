func removeDuplicates(nums []int) int {
	length := 0

	i := 0
	for i < len(nums) {
		p := i
		for i+1 < len(nums) && nums[i] == nums[i+1] {
			i++
		}

		for j := p; j <= i; j++ {
			if j-p+1 <= 2 {
				nums[length] = nums[p]
				length++
			} else {
				break
			}
		}

		i++
	}

	return length
}

//Another
func removeDuplicates(nums []int) int {
	var i int
	for _, num := range nums {
		if i < 2 || num != nums[i-2] {
			nums[i] = num
			i++
		}
	}
	return i
}