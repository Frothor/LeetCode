//Second fastest
func calculate(s string) int {
    s = strings.ReplaceAll(s, " ", "")
    if len(s) == 0 {
        return 0
    }
    
    start, end := 0, 1
    prev := 0
    result := 0
    for end <= len(s) {
        if end == len(s) || isOperator(string(s[end])) {
            num, _ := strconv.Atoi(s[start:end])
            if start == 0 {
                result += num
                prev = num
            } else {
                oper := string(s[start-1])
                if oper == "-" {
                    result -= num
                    prev = -num
                } else if oper == "+" {
                    result += num
                    prev = num
                } else if oper == "*" {
                    result = result - prev + prev*num
                    prev = prev*num
                } else if oper == "/" {
                    result = result - prev + prev/num
                    prev = prev/num
                }
            }
            start = end+1
        }
        end++
    }
    
    return result
}

func isOperator(s string) bool {
    if s == "-" || s == "+" || s == "/" || s == "*" {
        return true
    }
    return false
}

//https://leetcode.com/problems/basic-calculator-ii/discuss/947927/Easy-to-follow-go-golang-solution-100-time
//Fastest
func calculate(s string) int {

	if len(s) == 0 {
		return 0
	}

	cal := 0
	var sign byte = '+'
	//sign := '+' // when I declare sign this way it is not working. Not sure why
	var stack []int

	for i := 0; i < len(s); i++ {
		if IsDigit(s[i]) {
			cal = cal * 10 + int(s[i]-'0')
		}
		if (!IsDigit(s[i]) && s[i] != ' ') || i == len(s)-1 {
			if sign == '+' {
				stack = append(stack, cal)

			} else if sign == '-' {
				stack = append(stack, -cal)
			} else if sign == '*' {
				stack[len(stack)-1] = stack[len(stack)-1] * cal
			} else if sign == '/' {
				stack[len(stack)-1] = stack[len(stack)-1] / cal
			}
			cal = 0
			sign = s[i]
		}
	}
	sum := 0
	for _, v := range stack {
		sum += v
	}
	return sum
}

func IsDigit(s byte) bool {
	if s >= '0' && s <= '9' {
		return true
	}
	return false
}

//Another
func calculate(s string) int {
    
    nums := make([]int, 0)
    curNum := 0
    prevOp := '+'
    s = s + "+"
    
    for i := 0; i < len(s); i++ {
        if s[i] >= '0' && s[i] <= '9' {
            curNum = curNum * 10 + int(s[i] - '0')
        } else if s[i] == ' ' {
            continue
        } else {
            if prevOp == '+' {
                nums = append(nums, curNum)
            } else if prevOp == '-' {
                nums = append(nums, -1 * curNum)
            } else if prevOp == '*' {
                nums[len(nums)-1] = nums[len(nums) - 1] * curNum
            } else if prevOp == '/' {
                nums[len(nums)-1]  =nums[len(nums) - 1] / curNum
            }
            prevOp = rune(s[i])
            curNum = 0
        }
    }
    
    sum := 0
    for _, num := range(nums) {
        sum += num
    }
    
    return sum
    
}