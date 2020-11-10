//Second fastest
func flipAndInvertImage(A [][]int) [][]int {
    
    
    n := len(A)
    for i := 0; i < n;i++{
        for j := 0;j < n/2;j++{
            aux := A[i][j]
            A[i][j] =  A[i][n - j - 1]
            A[i][n - j - 1] = aux
        }
    }
    
    fmt.Println(A)
    for i := 0; i < n;i++{
        for j := 0; j < n;j++{
            
            if A[i][j] == 0{
                A[i][j] = 1
            }else{
                A[i][j] = 0
            }
        }
    } 
    
    return A
    
}

//Fastest
func flipAndInvertImage(A [][]int) [][]int {
	for i := 0; i < len(A); i++ {
		for l, r := 0, len(A[i]) - 1; l <= r; l,r = l+1,r-1 {
			if l == r {
				A[i][l] = A[i][l] ^ 1
			} else {
				A[i][l] = A[i][l] ^ 1
				A[i][r] = A[i][r] ^ 1
			}

			A[i][l], A[i][r] = A[i][r], A[i][l]
		}
	}

	return A
}

//Second fastest
func invertBinary(a int) int {
    if a == 0 {
        return 1
    }
    return 0
}

func flipAndInvertImage(A [][]int) [][]int {
    if len(A) == 0 {
        return [][]int{}
    }
    
    m := len(A)
    n := len(A[0])
    nHalf := n / 2

    for i := 0; i < m; i++ {
        for j := 0; j < nHalf; j++ {
            aux := A[i][n-j-1]
            A[i][n-j-1] = A[i][j]
            A[i][j] = aux
        }
    }
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if A[i][j] == 0 {
                A[i][j] = 1
            } else {
                A[i][j] = 0
            }
        }
    }
    
    return A
}