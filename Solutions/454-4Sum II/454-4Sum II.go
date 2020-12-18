//Third fastest
func fourSumCount(A []int, B []int, C []int, D []int) int {
    m := make(map[int]int, len(A)*len(B))
	for _, a := range A {
		for _, b := range B {
			m[a+b]++
		}
	}
	ret := 0
	for _, c := range C {
		for _, d := range D {
			ret += m[0-c-d]
		}
	}

	return ret
}

//Second fastest
func fourSumCount(A []int, B []int, C []int, D []int) int {
    var res int
    dp := make(map[int]int, len(A)*len(B))
    for _, a := range A {
        for _, b := range B {
            dp[a+b]++
        }
    }
    for _, c := range C {
        for _, d := range D {
            res += dp[0-c-d]
        }
    }
    return res
}

//Fastest
func fourSumCount(A []int, B []int, C []int, D []int) int {
    ABsumHash := make(map[int]int, len(A)*len(A))
    for i := range A{
        for j := range B{
            ABsumHash[A[i]+B[j]]++
        }   
    }
    ans := 0
    for i := range C{
        for j := range D{
            ans+=ABsumHash[-C[i]-D[j]]
        }   
    }
    return ans
}