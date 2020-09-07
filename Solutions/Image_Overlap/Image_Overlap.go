func largestOverlap(A [][]int, B [][]int) int {
	aValues := make([]int, len(A))
	bValues := make([]int, len(B))
	for i, vs := range A {
		for j, v := range vs {
			if v == 1 {
				aValues[i] += 1 << j
			}
			if B[i][j] == 1 {
				bValues[i] += 1 << j
			}
		}
	}
	maxValue := 0
	// i: row offset
	// j: col offset
	for i := 0; i < len(A); i++ {
		for j := 0; j < len(A); j++ {
			current1, current2 := 0, 0
			for m := 0; m + i < len(A); m++ {
				current1 += getOne(aValues[m] & (bValues[i+m] >> j))
				current2 += getOne(bValues[m] & (aValues[i+m] >> j))
			}
			if current1 > maxValue {
				maxValue = current1
			}
			if current2 > maxValue {
				maxValue = current2
			}
		}
	}
	return maxValue
}

func getOne(v int) int {
	n := 0
	for v != 0 {
		if v & 0x1 == 1 {
			n++
		}
		v >>= 1
	}
	return n
}

//Fastest
func largestOverlap(A [][]int, B [][]int) int {
    var count int
    for i := -len(A)+1; i < len(A); i++ {
        for j := -len(A)+1; j < len(A);j++ {
            countMaybe := intersect(A, B, i, j)
            if count < countMaybe {
                count = countMaybe
            }
        }
    }
    return count
}

func intersect(A, B [][]int, offI, offJ int) int {
    var count int
    for i := range A {
        for j := range A[0] {
            if i + offI < 0 || j+offJ < 0 || i+offI>=len(A) || j+offJ>= len(A) {
                continue
            }
            if A[i+offI][j+offJ] + B[i][j] == 2  {
                count++
            }
        }
    }
    return count
}