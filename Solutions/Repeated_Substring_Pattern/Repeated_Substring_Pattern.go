func repeatedSubstringPattern(s string) bool {
search:
	for i := 1; i <= len(s)/2; i++ {
		for j := i; j+i <= len(s); j += i {
			if s[j-i:j] != s[j:j+i] {
				continue search
			}
		}
		return len(s)%i == 0
	}
	return false
}