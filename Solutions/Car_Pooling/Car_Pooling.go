// solution 1: Due to the small number of stations(only 1001), we can do in this way
func carPooling(trips [][]int, capacity int) bool {
	station := make([]int, 1001)
	for _, trip := range trips {
		station[trip[1]] += trip[0]
		station[trip[2]] -= trip[0]
	}
	passengers := 0
	for _, v := range station {
		passengers += v
		if passengers > capacity {
			return false
		}
	}
	return true
}

// solution 2: works better if the number of stations is very large
func carPooling(trips [][]int, capacity int) bool {
	sort.Slice(trips, func(i, j int) bool {
		if trips[i][1] == trips[j][1] {
			return trips[i][2] < trips[j][2]
		}
		return trips[i][1] < trips[j][1]
	})

	current := [][2]int{} // 0-destination 1-passengers
	for _, trip := range trips {
		if !process(&current, trip, &capacity) {
			return false
		}
	}
	return true
}

func process(numbers *[][2]int, trip []int, capacity *int) bool {
	index := 0
	for i, v := range *numbers {
		// arrive destination
		if v[0] <= trip[1] {
			index = i + 1
			*capacity += v[1]
		}
	}
	*numbers = (*numbers)[index:]

	*capacity -= trip[0]
	// overload
	if *capacity < 0 {
		return false
	}

	l, r := 0, len(*numbers)-1
	for l <= r {
		m := (l+r)>>1
		if (*numbers)[m][0] == trip[2] {
			(*numbers)[m] = [2]int{(*numbers)[m][0], (*numbers)[m][1] + trip[0]}
			return true
		} else if (*numbers)[m][0] > trip[2] {
			r = m-1
		} else {
			l = m+1
		}
	}
	// (*numbers)[r] < trip[2] or r == -1
	index = r + 1
	tail := make([][2]int, len((*numbers)[index:]))
	copy(tail, (*numbers)[index:])
	*numbers = append((*numbers)[:index], [2]int{trip[2], trip[0]})
	*numbers = append(*numbers, tail...)
	return true
}


////////////////////////////////////
//Another
func carPooling(trips [][]int, capacity int) bool {
    m := make(map[int]int)
    xs := make([]int, 0)
    for _, trip := range trips {
        p, s, e := trip[0], trip[1], trip[2]
        if _, ok := m[s]; !ok {
            xs = append(xs, s)
        }
        m[s] -= p
        if _, ok := m[e]; !ok {
            xs = append(xs, e)
        }
        m[e] += p
    }
    sort.Ints(xs)
    
    for _, x := range xs {
        capacity += m[x]
        if capacity < 0 {
            return false
        }
    }
    return true
}