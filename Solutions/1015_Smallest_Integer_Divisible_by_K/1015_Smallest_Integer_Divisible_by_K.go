//https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260977/Golang-O(K)O(1)-and-O(K)O(K)
func smallestRepunitDivByK(K int) int {
    for n, i := 0, 1; i<=K; i++ {
        n = n*10 + 1
        n = n%K
        if n == 0 { return i }
    }
    return -1
}

//Another
func smallestRepunitDivByK(K int) int {
	r := 0
	for l := 1; l <= K; l++ {
		r = (r*10 + 1) % K
		if r == 0 {
			return l
		}
	}
	return -1
}