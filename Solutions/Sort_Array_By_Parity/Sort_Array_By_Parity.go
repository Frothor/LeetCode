func sortArrayByParity(A []int) []int {
    i, j := 0, len(A) - 1
    for i < j {
        if A[j] % 2 == 0 {
            for i < j && A[i] % 2 == 0 { i++ }
            A[i], A[j] = A[j], A[i]
            i++
        } else {
            j--
        }
    }
    return A
}

//Another
func sortArrayByParity(nums []int) []int {
    // target idx for even numbers
    nextEvenPosition := 0
    for cur := 0; cur < len(nums); cur++ {
        if nums[cur]%2 == 0 {
            nums[nextEvenPosition], nums[cur] = nums[cur], nums[nextEvenPosition]
            nextEvenPosition++
        }
    }
    return nums
}