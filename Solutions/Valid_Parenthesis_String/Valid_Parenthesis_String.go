func checkValidString(s string) bool {
	stack := []rune{}
	for _, v := range s {
		switch v {
		case '(':
            // (, append to stack
			stack = append(stack, v)
		case ')':
            // ), consume right-most (, if no (, consume right-most *
			if len(stack) == 0 {
				return false
			}
			for i := len(stack)-1; i >= 0; i-- {
				if stack[i] == '(' {
					copy(stack[i:], stack[i+1:])
					break
				}
			}
			stack = stack[:len(stack)-1]
		default:
            // *, append to stack
			stack = append(stack, v)
		}
	}
	left := 0
	for _, v := range stack {
		if v == '(' {
			left++
		} else if left > 0 {
			left--
		}
	}
	return left == 0
}