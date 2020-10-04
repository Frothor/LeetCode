func removeCoveredIntervals(intervals [][]int) int {
    sort.Slice(intervals, func(i, j int) bool {
        if intervals[i][0] != intervals[j][0] {
            return intervals[i][0] < intervals[j][0]
        } else {
            return intervals[i][1] > intervals[j][1]
        }
    })
    bound := -1
    valid := 0
    for _, v := range intervals {
        if v[1] <= bound {
            continue
        } else {
            bound = v[1]
            valid++
        }
    }
    return valid
}

//Another fastest
func removeCoveredIntervals(intervals [][]int) int {
	if len(intervals) <= 1 {
		return 0
	}
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		} else {
			return intervals[i][0] < intervals[j][0]
		}
	})

	ans := 0
	minRight := intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		if intervals[i][1] <= minRight {
			ans++
		} else {
			minRight = intervals[i][1]
		}
	}
	return len(intervals) - ans
}