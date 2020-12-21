//Third fastest
//https://leetcode.com/problems/cherry-pickup-ii/discuss/977695/golang-clean-solution-beats-100
func cherryPickup(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	old, new := make([]int, n*n), make([]int, n*n)
	for i := range old {
		old[i] = -0xffffff               
	}
	old[n-1] = grid[0][0]+grid[0][n-1]   

	// dp
	for k:=1; k<m; k++ {
		for s:=0; s<n*n; s++ {
			new[s] = -0xffffff
			c1, c2 := s/n, s%n  
			toadd := grid[k][c1]
			if c1 != c2 {
				toadd += grid[k][c2]
			}
			for _, d1 := range []int{1,0,-1} {
				for _, d2 := range []int{1,0,-1} {
					nc1, nc2 := c1+d1, c2+d2
					if nc1>=0 && nc1<n && nc2>=0 && nc2<n && old[nc1*n+nc2]>=0 {
						new[s] = max(new[s], old[nc1*n+nc2]+toadd)
					}
				}
			}
		}
		old, new = new, old
	}
	allmax := 0
	for _, v := range old {
		if v>allmax {
			allmax = v
		}
	}
    return allmax
}

func max(a, b int) int {
	if a>b {
		return a
	}
	return b
}

//Second fastest
func cherryPickup(grid [][]int) int {
    M, N := len(grid), len(grid[0])   
    prev := make([][]int, N)
    for r := range prev {
        prev[r] = make([]int, N)
        for c := 0; c < N; c++ {
            prev[r][c] = grid[M - 1][r]
            if r != c {
                prev[r][c] += grid[M - 1][c]
            }
        }
    }
    next := make([][]int, N)
    for r := range next {
        next[r] = make([]int, N)
    }
    for l := M - 2; l >= 0; l-- {
        for r :=0; r < N; r++ {
            for c := 0; c < N; c++ {
                n := grid[l][r]
                if r != c {
                    n += grid[l][c]
                }
                var m int
                for _, d := range []int{-1, 0, 1} {
                    nr := r + d
                    if nr < 0 || nr >= N {
                        continue
                    }
                    for _, d := range []int{-1, 0, 1} {
                        nc := c + d
                        if nc >= 0 && nc < N {
                            x := n + prev[nr][nc] 
                            if x > m {
                                m = x
                            }
                        }
                    }
                }
                next[r][c] = m
            }
        }
        next, prev = prev, next
    }
    return prev[0][N - 1]
}

//Fastest
func cherryPickup(grid [][]int) int {

	d := []int{-1, 0, 1}
	cols := len(grid[0])

	initSlices := func() [][]int {
		tmp := make([][]int, cols)
		for i := range tmp {
			tmp[i] = make([]int, cols)
			for j := range tmp[i] {
				tmp[i][j] = -1
			}
		}
		return tmp
	}

	tmp, results := initSlices(), initSlices()

	tmp[0][cols-1] = grid[0][0] + grid[0][cols-1]
	for i := 1; i < len(grid); i++ {
		for col0 := 0; col0 < cols; col0++ {
			for col1 := 0; col1 < cols; col1++ {
				if tmp[col0][col1] == -1 {
					continue
				}

				for _, d0 := range d {
					for _, d1 := range d {
						nCol0 := col0 + d0
						if nCol0 < 0 || nCol0 >= cols {
							continue
						}

						nCol1 := col1 + d1
						if nCol1 < 0 || nCol1 >= cols {
							continue
						}

						var t int
						if nCol0 == nCol1 {
							t = tmp[col0][col1] + grid[i][nCol0]
						} else {
							t = tmp[col0][col1] + grid[i][nCol0] + grid[i][nCol1]
						}

						if t > results[nCol0][nCol1] {
							results[nCol0][nCol1] = t
						}
					}
				}
			}
		}

		tmp, results = results, tmp
	}

	var result int
	for col0 := 0; col0 < cols; col0++ {
		for col1 := 0; col1 < cols; col1++ {
			if tmp[col0][col1] > result {
				result = tmp[col0][col1]
			}
		}
	}

	return result
}