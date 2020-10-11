func removeDuplicateLetters(s string) string {
	hashMap := [26]int{}
	visited := [26]bool{}

	for i := range s {
		hashMap[int(s[i])-int('a')] = i
	}

	var res []byte
	for i := range s {
		ch := s[i]
		for len(res) > 0 {
			lastCh := res[len(res)-1]
			if ch <= lastCh && hashMap[int(lastCh)-int('a')] >= i && !visited[int(ch)-int('a')] {
				visited[int(lastCh)-int('a')] = false
				res = res[:len(res)-1]
				continue
			}
			break
		}

		if !visited[int(ch)-int('a')] {
			res = append(res, ch)
			visited[int(ch)-int('a')] = true
		}
	}
	return string(res)
}

//Another
func removeDuplicateLetters(s string) string {
    
    // append char into array
    //     1. seen, skip 
    //     2. smaller than current lastItem and cntMap[lastItem] > 0   -> remove lastItem, append current item
    //     2.2. else { append}
    
    cntMap := make([]int, 26)
    res := make([]byte, 0)
    seen := make(map[byte]bool)
    for i:=0;i<len(s);i++{
        cntMap[int(s[i]-'a')]++
    }
    
    for i:=0;i<len(s);i++{
        c := s[i]
        cntMap[int(c-'a')]--
        if seen[c] {
            continue
        }
        
        for len(res) > 0 && c < res[len(res)-1] && cntMap[int(res[len(res)-1]-'a')] > 0 {
            lastItem := res[len(res)-1]
            seen[lastItem] = false
            res = res[:len(res)-1]
        }
        res = append(res, c)
        seen[c] = true
    }
    return string(res)
}