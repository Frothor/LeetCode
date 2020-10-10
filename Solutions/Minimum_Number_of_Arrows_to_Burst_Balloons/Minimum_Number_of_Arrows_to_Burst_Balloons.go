//Most common
func findMinArrowShots(points [][]int) int {
	sort.Slice(points, func(i, j int) bool {
		return points[i][1] < points[j][1]
	})
	shoot := 0
	count := 0
	i := 0
	for i < len(points) {
		shoot = points[i][1]
		count++
		for i < len(points) && points[i][0] <= shoot && points[i][1] >= shoot {
			i++
		}
	}
	return count
}

//Second fastest
func findMinArrowShots(points [][]int) int {
    if len(points) < 2 {
        return len(points)
    }
    sort.Slice(points, func(i, j int) bool {
        return points[i][1] < points[j][1]
    })
    
    end := points[0][1]
    ans := 1
    for i := 1; i < len(points); i++ {
        if points[i][0] > end {
            end = points[i][1]
            ans++
        }
    }
    return ans
}


//Fastest
func findMinArrowShots(points [][]int) int {
	if len(points) == 0 {
		return 0
	}
	sort.Sort(shots(points))
	i := 0
	j := 1
	count := 1
	for {
		if i+j > len(points)-1 {
			break
		}
		end := points[i][1]
		if end >= points[i+j][0] {
			j++
		} else {
			count++
			i = i + j
			j = 1
		}
	}
	return count    
}

type shots [][]int

func (s shots) Len() int {
	return len(s)
}
func (s shots) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
	return
}
func (s shots) Less(i, j int) bool {
	if s[i][1] < s[j][1] {
		return true
	}
	return false
}