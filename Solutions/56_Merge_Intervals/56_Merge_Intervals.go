//Third fastest
type Intervals [][]int

func (i Intervals) Less(a, b int) bool {
    return i[a][0] < i[b][0]
}

func (i Intervals) Swap(a, b int) {
    i[a], i[b] = i[b], i[a]
}

func (i Intervals) Len() int {
    return len(i)
}

func merge(intervals [][]int) [][]int {
    var i Intervals
    i = intervals
    sort.Sort(i)
    
    i = append(i, []int{math.MaxInt32, -1})
    result := [][]int{}
    end := i[0][1]
    start := i[0][0]
    for _, r := range i {
        if r[0] > end {
            result = append(result, []int{start, end})   
            start = r[0]
        }
        
        end = max(end, r[1])
    }
    
    return result
}

func max(a,b int) int {
    if a > b {
        return a
    }
    
    return b
}

//Second fastest
func merge(intervalsCop [][]int) [][]int {
    out := make([][]int,0)
    sort.Slice(intervalsCop, func(i, k int) bool {
        return intervalsCop[i][0] < intervalsCop[k][0]
    })    
    start := false
    for i:=0; i<= len(intervalsCop)-1;i++{
        if intervalsCop[i] == nil{
            continue
        }
        if ! start {
            out  = append(out, intervalsCop[i]) 
            start = true
            continue
        }

        if out[len(out)-1][1]>= intervalsCop[i][0] && out[len(out)-1][1]<= intervalsCop[i][1]{
                out[len(out)-1] = []int{
                    out[len(out)-1][0],
                    intervalsCop[i][1],
                }
        }else if   out[len(out)-1][1] < intervalsCop[i][0]{
            out = append(out, intervalsCop[i])
        }
        
    }
    return out
    
}

//Fastest
type INTERVALS [][]int

func (I INTERVALS) Less(i, j int) bool {
	return I[i][0] < I[j][0]
}
func (I INTERVALS) Swap(i, j int) {
	I[i], I[j] = I[j], I[i]
}
func (I INTERVALS) Len() int {
	return len(I)
}

func merge(intervals [][]int) [][]int {
	sortByBIdx(intervals)
	var ans [][]int
	for _, v := range intervals {
		if len(ans) == 0 {
			ans = append(ans, v)
			continue
		}
		lastIdx := len(ans) - 1
		if v[0] > ans[lastIdx][1] {
			ans = append(ans, v)
			continue
		}

		if v[1] > ans[lastIdx][1] {
			ans[lastIdx][1] = v[1]
			continue
		}
	}

	return ans
}

func sortByBIdx(intervals [][]int) [][]int {
	sort.Sort(INTERVALS(intervals))
	return intervals
}