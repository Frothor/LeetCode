//Most common
func longestMountain(A []int) int {
    n := len(A)
    up, down := 0, 0
    var res int
    for i := 1; i < n; i++ {
        if A[i] == A[i-1] || (down > 0 && A[i] > A[i-1]) {
            up, down = 0, 0
        }
        if A[i] > A[i-1] {
            up++
        }
        if A[i] < A[i-1] {
            down++
        }
        if up > 0 && down > 0 {
            res = max(res, up+down+1)
        }
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

//Second fastest
func longestMountain(A []int) int {
	if len(A) < 3 {
		return 0
	}
	longest := 0
	asc := false
	desc := false
	curC := 0

	if A[0] < A[1] {
		curC = 2
		asc = true
	}
	for i := 1; i < len(A)-1; i++ {
		cur := A[i]
		next := A[i+1]
		if cur < next { // ascending
			if desc {
				if curC > longest {
					longest = curC
				}
				curC = 1
			}
			asc = true
			desc = false
			if curC == 0 {
				curC = 1
			}
			curC++
		} else if cur > next { // descending
			if asc || (desc && curC > 0) {
				curC++
			}
			asc = false
			desc = true
		} else {
			if desc && curC > 0 && curC > longest {
				longest = curC
				curC = 0
			}
			desc = false
			asc = false
			curC = 0
		}
	}
	if desc && curC > longest {
		longest = curC
	}
	if longest < 3 {
		return 0
	}
	return longest
}

//Fastest
//Two pointers
func longestMountain(A []int) int {
    N := len(A)
    left, res := 0,0
    
    for left < N{
        end := left
        
        if end+1 < N && A[end] < A[end+1]{
            for end + 1 < N && A[end+1] > A[end]{
                end++
            }
            
            if end+1 < N && A[end] > A[end+1]{
                for end + 1 < N && A[end] > A[end+1]{
                    end++
                }
                
                res = max(res, end-left+1)
            }
        }
        
        left = max(end, left+1)
    }
    
    return res
}

func max(a,b int) int{
    if a > b{
        return a
    }
    
    return b
}