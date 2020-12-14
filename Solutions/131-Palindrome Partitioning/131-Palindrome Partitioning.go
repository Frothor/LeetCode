//Third fastest
func isPalindrome(s string) bool {
    for i, j := 0, len(s)-1; i < j; i,j = i+1,j-1 {
        if s[i] != s[j] {
            return false
        }
    }
    
    return true
}

func partition(s string) [][]string {
    if len(s) == 0 {
        return [][]string{{}}
    }
    
    res := [][]string{}
    for i := 0; i < len(s); i += 1 {
        cur := s[:i+1]
        if !isPalindrome(cur) {
            continue
        }
        rest := partition(s[i+1:])
        
        for _, x := range(rest) {
            t := append([]string{cur}, x...)
            res = append(res, t)
        }
    }
    
    return res
}

//Second fastest
func partition(s string) [][]string {
    
    results := make([][]string, 0)
    collect(s, []string{}, &results)
    return results
    
    
}

func collect(s string, current []string, results *[][]string) {
    if len(s) == 0 {
        *results = append(*results, current)
        return
    }
    
    for i := 1; i <= len(s); i++ {
        if s[0] == s[i-1] && isPalin(s[:i]) {
            collect(s[i:], append(append([]string{}, current...), s[:i]), results)
        }
    }
    
}

func isPalin(s string) bool {
    left, right := 0, len(s) - 1
    for left < right {
        if s[left] != s[right] {
            return false
        }
        left++
        right--
    }
    
    return true
}

//Fastest
func partition(s string) [][]string {
    
	var ret [][]string
	var cur []string

	helper(cur, s, &ret)

	return ret
}

func helper(cur []string, s string, ret *[][]string) {
	p := len(strings.Join(cur, ""))
	if p == len(s) {
		tmp := make([]string,len(cur))
		copy(tmp,cur)
		*ret = append(*ret, tmp)
		return
	}
	for i := p; i < len(s); i++ {
		l := p
		r := i
		if isPalindrome(s,l,r) {
			helper(append(cur, s[l:r+1]), s, ret)
		}

	}
}

func isPalindrome(s string, l int, r int) bool{
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}

	return true
}

//