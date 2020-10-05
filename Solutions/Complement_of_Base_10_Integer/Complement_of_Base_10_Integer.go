func bitwiseComplement(N int) int {
	if N == 0 {
		return 1
	}
	
	NP := N // a copy of N
	for offset := uint(1); N>>offset > 0; offset <<= 1 {
		N |= (N >> offset)
	}
	return NP ^ N
}

//Another
func bitwiseComplement(N int) int {
    if N == 0 {
        return 1
    }
    p2 := 1
    r := 0
    for N > 0 {
        x := N & 1
        if x == 0 {
            r |= p2
        }
        N >>= 1
        p2 <<= 1
    }
    return r
}