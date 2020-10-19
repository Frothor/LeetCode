//Most common
func minDominoRotations(A []int, B []int) int {
    rotations := 1 << 63-1
    
    rotations = min(rotations, getDominoRot(A, B, A[0]))
    rotations = min(rotations, getDominoRot(B, A, B[0]))
    rotations = min(rotations, getDominoRot(A, B, B[0]))
    rotations = min(rotations, getDominoRot(B, A, A[0]))
    
    if rotations == 1 <<63-1 {
        return -1
    }
    return rotations
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func getDominoRot(a, b []int, val int) int {
    if len(a) == 0 || len(b) == 0 {
        return 0
    }
    
    countRot := 0
    for i := range a {
        if a[i] == val {
            continue
        } else if b[i] == val {
            countRot++
        } else {
            return 1 <<63 -1
        }
    }
    
    
    return countRot
}

//Third fastest
func minDominoRotations(A []int, B []int) int {
    res := helper(A, B, A[0])
    if res != -1 || A[0] == B[0]{
        return res
    }
    return helper(A, B, B[0])
}

func helper(A []int, B []int, x int) int {
    i := 0
    rotCountA := 0
    rotCountB := 0
    for i < len(A){
        if A[i] != x && B[i] != x{
            return -1
        }
        if A[i] != x {
            rotCountA++
        }else if B[i] != x {
            rotCountB++
        }
        i++
    } 
    if rotCountA < rotCountB {
        return rotCountA
    }
    return rotCountB
}

//Second fastest
func minDominoRotations(A []int, B []int) int {
    a := A[0]
    b := B[0]
    
    countATop := 1
    countBTop := 0
    
    countABottom := 0
    countBBottom := 1
    for i := 1; i < len(A); i++ {
        if a != A[i] && a != B[i] {
            a = -1
        }
        
        if b != A[i] && b != B[i] {
            b = -1
        }
        
        if a == A[i] {
            countATop++
        }
        
        if b == A[i] {
            countBTop++
        }
        
        if a == B[i] {
            countABottom++
        }
        
        if b == B[i] {
            countBBottom++
        }
        
        if a == -1 && b == -1 {
            return -1
        }
    }
    
    if a == b {
        return len(A) - max(max(countATop, countABottom), max(countBTop, countBBottom))
    }
    
    if a > b {
        return len(A) - max(countATop, countABottom)
    }
    return len(A) - max(countBTop, countBBottom)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

//Fastest
func minDominoRotations(A []int, B []int) int {

	var aCtr = make([]int, 8)
	var bCtr = make([]int, 8)
	var sameCtr = make([]int, 8)

	for i := range A {
		if A[i] == B[i] {
			sameCtr[A[i]]++
		}

		aCtr[A[i]]++
		bCtr[B[i]]++
	}

	min := 99999

	for i := 1; i <= 6; i++ {

		if aCtr[i]+bCtr[i]-sameCtr[i] == len(A) {

			min = mn(min, mn(aCtr[i]-sameCtr[i], bCtr[i]-sameCtr[i]))

		}
	}

	if min == 99999 {
		return -1
	}

	return min

}

func mn(a, b int) int {

	if a < b {
		return a
	}

	return b

}