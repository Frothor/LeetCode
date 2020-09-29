func wordBreak(str string, words []string) bool {
	mem := make(map[int]bool)
	var dfs func(string) bool
	dfs = func(str string) bool {
		if str == "" {
			return true
		}
		if ret, ok := mem[len(str)]; ok {
			return ret
		}
		for _, w := range words {
			if len(w) <= len(str) && w == str[:len(w)] {
				try := dfs(str[len(w):])
				if try {
					mem[len(str)] = true
					return true
				}
			}
		}
		mem[len(str)] = false
		return false
	}
	return dfs(str)
}

//Another
func wordBreak(s string, wordDict []string) bool {
    dict := make(map[string]bool, len(wordDict))
    for _, word := range wordDict {
        dict[word] = true
    }
    memo := make(map[int]bool, len(s))
    return dfs(s, dict, 0, memo)
}

func dfs(s string, dict map[string]bool, idx int, memo map[int]bool) bool {
  if idx == len(s) {
    return true
  }
    
    r, calculated := memo[idx]
    if calculated {
        return r
    }

  for i := idx + 1; i <= len(s); i++ {
    prefix := s[idx:i]
    if dict[prefix] && dfs(s, dict, i, memo) {
        memo[idx] = true
      return true
    }
  }
    
    memo[idx] = false
  return false
}