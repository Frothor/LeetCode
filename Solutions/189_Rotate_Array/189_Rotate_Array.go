//Second fastest
func rotate(nums []int, k int)  {
    var (
        l = len(nums)
    )
    if k >= l {
        k = k % l
    }
    if k == 0 {
        return
    }
    
    var (
        tmp int
        dem int
        i int
        j int
        v int
    )
    
    // move element to the right if k is less than half of the number of elements
    if k <= l/2 {
        i = k
        v = nums[j]
        for dem < l {
            tmp = nums[i]
            nums[i] = v
            dem++
            if i == j {
                j++
                v = nums[j]
                i = k+j
                continue
            }
            i = (i+k) % l
            v = tmp
        }
        return
    }
    
    // move elements to the left
    k = l-k
    i = 0
    j = k
    v = nums[j]
    for dem < l {
        tmp = nums[i]
        nums[i] = v
        dem++
        if i == j {
            j++
            v = nums[j]
            i = (j-k+l)% l
            continue
        }
        i = (i-k+l)% l
        v = tmp
    }
}

//Fastest
func rotate(nums []int, k int)  {
    length := len(nums)
	if length < 2 {
		return
	}

	k = k % length

	reverse(nums,  length - k, length - 1)
	reverse(nums, 0, length - k - 1)
	reverse(nums,  0, length - 1)
}

func reverse(nums[] int, start int, end int) {
	count := (end - start + 1) / 2
	for i := 0; i < count; i++ {
		current := i + start
		j := end - i
		nums[current] += nums[j]
		nums[j] = nums[current] - nums[j]
		nums[current] -= nums[j]
	}
}