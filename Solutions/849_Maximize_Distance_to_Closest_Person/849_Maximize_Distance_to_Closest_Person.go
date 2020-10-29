//Second fastest
func maxDistToClosest(seats []int) int {
	dist := 0

	size := len(seats)
	l, r := 0, 0
	prev := -1
	for r < size {
		if seats[r] == 1 {
			if prev == -1 {
				l = -r
			}
			d := max((r-l)/2, 1)
			dist = max(dist, d)
			l = r
			prev = r
		} else if r == size-1 {
			d := max(r-l, 1)
			dist = max(dist, d)
		}
		r++
	}

	return dist
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

//Fastest
func maxDistToClosest(seats []int) int {
    n := len(seats)
    prev := -1
    ans := 0
    
    for i := 0; i < n; i++ {
        if seats[i] == 1 {
            if prev == -1 {
                ans = i
            } else {
                ans = max(ans, (i - prev) / 2)        
            }
            prev = i
        }
    }
    ans = max(ans, n - prev - 1)
    return ans
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

//Second fastest
func maxDistToClosest(seats []int) int {
	max := func(i, j int) int {
		if i > j {
			return i
		}
		return j
	}
	visited := make([]int, 0)
	for index, s := range seats {
		if s == 0 {
			continue
		}
		visited = append(visited, index)
	}
	if len(visited) == 1 {
		return max(visited[0], len(seats)-1-visited[0])
	}
	m := max(visited[0], len(seats)-1-visited[len(visited)-1])
	for i := 0; i < len(visited)-1; i++ {
		mid := (visited[i+1] + visited[i]) / 2
		if mid-visited[i] > m {
			m = mid - visited[i]
		}
	}
	return m    
}