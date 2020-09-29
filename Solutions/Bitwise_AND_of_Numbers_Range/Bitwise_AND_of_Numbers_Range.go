//Fastest
func rangeBitwiseAnd(m int, n int) int {
    i := 0
    
    for ; m != n; i++ {
        m >>= 1
        n >>= 1
    }
    
    return n << i
}