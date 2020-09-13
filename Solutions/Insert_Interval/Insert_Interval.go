func insert(intervals [][]int, newInterval []int) [][]int {
    var sol = make([][]int,0)
    sol = append(sol, newInterval)
    //append the newInterval to our solution and interate in O(N) over the intervals
    //at each step take a decision whether the next incoming interval precedes, merges or succeeds the current interval - O(1) time 
    //after step above, append to the sol variable 
    //Total Complexity -- O(N) Time and O(N) Space
    currInterval := sol[len(sol)-1]
    for i:=0;i<len(intervals);i++{
        nextInterval := intervals[i]
        if nextInterval[0] <= currInterval[1] { //merges or precedes 
            if nextInterval[1] < currInterval[0] { //precedes
                sol[len(sol)-1] = nextInterval 
                sol = append(sol, currInterval)
            } else {
                sol[len(sol)-1] = merge(currInterval, nextInterval)
            }
        } else { //succeeds 
            sol = append(sol, nextInterval)
        }
        currInterval = sol[len(sol)-1]
    }
    return sol
}

func merge(int1, int2 []int) []int {
    var ret = make([]int,2)
    if int1[0] < int2[0] {
        ret[0] = int1[0]
    } else {ret[0] = int2[0]}
    
    if int1[1] > int2[1] {
        ret[1] = int1[1]
    } else {ret[1] = int2[1]}
    return ret
}

//Fastest
func insert(intervals [][]int, newInterval []int) [][]int {
    if len(intervals) == 0 {
        return [][]int{newInterval}
    }
    
    l := len(intervals)
    if newInterval[1] < intervals[0][0] {
        return append([][]int{newInterval}, intervals...)
    } else if newInterval[0] > intervals[l - 1][1] {
        return append(intervals, newInterval)
    }
    start, end := newInterval[0], newInterval[1]
    
    res := make([][]int, 0)
    for i := 0; i < l; i++ {
        if intervals[i][1] < newInterval[0] {
            res = append(res, intervals[i])
        } else if intervals[i][0] > newInterval[1] {
            res = append(res, intervals[i])
        } else  {
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
        }
        //fmt.Println(start, end)
        
    }
    res = append(res, []int{start, end})
    sort.Slice(res, func(i, j int) bool {
        return res[i][0] < res[j][0]
    })
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}