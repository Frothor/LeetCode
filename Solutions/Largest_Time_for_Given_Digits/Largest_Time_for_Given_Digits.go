func largestTimeFromDigits(A []int) string {
	var maxTime string
    // function define
	var dfs func(start int)
    
    // function to make times as string.
	var toString = func(times []int) string {
		return strconv.Itoa(times[0]) + strconv.Itoa(times[1]) + ":" + strconv.Itoa(times[2]) + strconv.Itoa(times[3])
	}
    
    // function to check times valid or not.
	var checkValid = func(times []int) bool {
		hours, minutes := times[0]*10+times[1], times[2]*10+times[3]

		if hours >= 24 || minutes >= 60 {
			return false
		}
		return true
	}

	dfs = func(start int) {
		if start == len(A)-1 {
			if checkValid(A) {
				time := toString(A)
				if maxTime < time {
					maxTime = time
				}
			}
			return
		}

		for i := start; i < len(A); i++ {
			A[i], A[start] = A[start], A[i]
			dfs(start + 1)
			A[i], A[start] = A[start], A[i]
		}
	}

	dfs(0)

	return maxTime
}


//Another fast
func largestTimeFromDigits(nums []int) string {
    pairs := make([][]int, 0)
    
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            anum := strconv.Itoa(nums[i])
            bnum := strconv.Itoa(nums[j])

            asumStr := anum + bnum
            bsumStr := bnum + anum
            asum, _ := strconv.Atoi(asumStr)
            bsum, _ := strconv.Atoi(bsumStr)

            if asum <= 23 {
                pairs = append(pairs, []int{i, j, asum})
            }

            if bsum <= 23 {
                pairs = append(pairs, []int{j, i, bsum})
            }   
        }
    }
    
    sort.Slice(pairs, func(i, j int) bool {
		return pairs[i][2] > pairs[j][2]
	})
    
    for _, pair := range pairs {
        i := pair[0]
        j := pair[1]
        
        var k, t int
        
        if (i == 0 && j == 1) || (i == 1 && j == 0) {
            k, t = 2, 3
        } else if (i == 0 && j == 2) || (i == 2 && j == 0) {
            k, t = 1, 3
        } else if (i == 0 && j == 3) || (i == 3 && j == 0) {
            k, t = 1, 2
        } else if (i == 1 && j == 2) || (i == 2 && j == 1) {
            k, t = 0, 3
        } else if (i == 1 && j == 3) || (i == 3 && j == 1) {
            k, t = 0, 2
        } else if (i == 2 && j == 3) || (i == 3 && j == 2) {
            k, t = 0, 1
        }
        
        anum := strconv.Itoa(nums[k])
        bnum := strconv.Itoa(nums[t])

        asumStr := anum + bnum
        bsumStr := bnum + anum
        asum, _ := strconv.Atoi(asumStr)
        bsum, _ := strconv.Atoi(bsumStr)
            
        time := -1
        
        if asum <= 59 && bsum <= 59 {
            time = asum
            if time < bsum {
                time = bsum
            }
        } else if asum <= 59 {
            time = asum
        } else if bsum <= 59 {
            time = bsum
        } else {
            continue
        }
        
        timeStr := strconv.Itoa(time)
        hourStr := strconv.Itoa(pair[2])
        
        
        if len(hourStr) == 1 {
            hourStr = "0" + hourStr
        }
        
        if len(timeStr) == 1 {
            timeStr = "0" + timeStr
        }
        
        return hourStr + ":" + timeStr
    }
    
    return ""
}