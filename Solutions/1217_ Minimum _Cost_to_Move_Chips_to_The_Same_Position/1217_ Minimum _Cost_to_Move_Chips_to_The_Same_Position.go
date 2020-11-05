func minCostToMoveChips(chips []int) int {
    odd, even := 0,0
    for _, c := range chips{
        if c % 2 == 0 {
            even++
        } else{
            odd++
        }
    }
    
    if even < odd{
        return even
    }
    
    return odd
}

//Another
func minCostToMoveChips(position []int) int {
	// odd 奇数 even 偶数
	oddNum, evenNum := 0, 0
	for i := range position {
		if position[i] % 2 != 0 {
			oddNum++
		} else {
			evenNum++
		}
	}
	if evenNum >= oddNum {
		return oddNum
	}
	return evenNum
}