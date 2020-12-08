//https://leetcode.com/problems/spiral-matrix-ii/discuss/22322/Golang-3-ms
func generateMatrix(n int) [][]int {
        matrix := make([][]int, n)
        for i := range matrix {
            matrix[i] = make([]int, n)
        }
        
        if n==0 {
            return matrix
        }
        
        rowStart := 0
        rowEnd := n - 1
        colStart := 0
        colEnd := n - 1
        num := 1
        
        for rowStart <= rowEnd && colStart <= colEnd {
            for i := colStart; i <= colEnd; i++ {
                matrix[rowStart][i] = num
                num++
            }
            rowStart++
            
            for i := rowStart;i<=rowEnd; i++ {
                matrix[i][colEnd] = num
                num++
            }
            colEnd--
            for  i:= colEnd; i >= colStart; i-- {
                if rowStart <= rowEnd {
                    matrix[rowEnd][i] = num
                    num++
                }
            }
            rowEnd--
            for  i:= rowEnd; i >= rowStart; i-- {
                if colStart <= colEnd {
                    matrix[i][colStart] = num
                    num++
                }
            }
            colStart++
        }
        return matrix
}

//Another
func generateMatrix(n int) [][]int {
	i, j := 1, 0
	x, y := -1, 0
	mat := make([][]int, n)
	for i := range mat {
		mat[i] = make([]int, n)
	}
	v := 1
	for v <= n*n {
		x += i
		y += j
		for x < n && x >= 0 && y >= 0 && y < n && mat[y][x] == 0 {
			mat[y][x] = v
			v++
			x += i
			y += j
		}
		x -= i
		y -= j
		i, j = -j, i
	}
	return mat
}