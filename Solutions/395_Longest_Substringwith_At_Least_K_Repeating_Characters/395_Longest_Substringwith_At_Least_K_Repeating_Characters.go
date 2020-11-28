//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/308459/golang
func longestSubstring(s string, k int) int {
	if k <= 0 {
		return 0
	}
	cache := make(map[string]int)
	return longestSubstringHelper(s, k, cache)
}

func longestSubstringHelper(s string, k int, cache map[string]int) int {
	if r, ok := cache[s]; ok {
		return r
	}
	res := 0
	counts := make([]int, 26)
	for i := 0; i < len(s); i++ {
		counts[int(s[i]-'a')]++
	}

	meet := true
	for i := 0; i < 26; i++ {
		if counts[i] > 0 && counts[i] < k {
			meet = false
			strs := strings.Split(s, string(i+'a'))
			for j := 0; j < len(strs); j++ {
				res = max(res, longestSubstringHelper(strs[j], k, cache))
			}
		}
	}

	if meet {
		cache[s] = len(s)
		return len(s)
	}
	cache[s] = res
	return res
}
func max(x, y int) int {
	if x > y {
		return x
	}

	return y
}

//Fastest
func longestSubstring(s string, k int) int {
    var m [26]int
    num := 0
    for i:=0; i<len(s); i++ {
        idx := int(s[i]-'a')
        if m[idx] == 0 {
            num++
        }
        m[idx]++
    }
    
    max := 0
    
    for n:=1; n<=num; n++ {
        var m [26]int
        cnt := 0
        i := 0
        j := 0
        unique := 0
        
        for j < len(s) {
            
            if unique <= n {
                c := int(s[j]-'a')
                m[c]++
                j++
                // cnt is the number that >= k
                if m[c] == k {
                    cnt++
                }
                if m[c] == 1 {
                    unique++
                }
            } else {
                c := int(s[i]-'a')
                if m[c] == k {
                    cnt--
                }
                m[c]--
                i++
                if m[c] == 0 {
                    unique--
                }
            }
            
            if unique == n && unique == cnt {
                if j-i > max {
                    max = j-i
                }
            }
        }
    }
    
    return max   
}