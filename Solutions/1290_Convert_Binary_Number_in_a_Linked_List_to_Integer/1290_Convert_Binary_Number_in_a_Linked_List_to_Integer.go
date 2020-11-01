//Fastest
func getDecimalValue(head *ListNode) (decimal int) {
    
    for head != nil {
        decimal = (decimal*2 ) + head.Val
        head = head.Next
    }
    
    return
}

//Another
func getDecimalValue(head *ListNode) int {
	var bs []byte
	for head != nil {
		bs = append(bs, byte(head.Val)+'0')
		head = head.Next
	}
 
	res, _ := strconv.ParseInt(string(bs), 2, 0)
	return int(res)
}
 