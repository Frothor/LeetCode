func findPoisonedDuration(a []int, k int) int {
    ans:=0
    if len(a)==0{
        return ans
    }
    for i:=0;i<len(a)-1;i++{
        ans+=min(a[i+1]-a[i],k)
    }
    return ans+k
}

func min(a,b int ) int {
    if a<b{
        return a
    }
    return b
}

//Another
func findPoisonedDuration(timeSeries []int, duration int) int {
    
    start := 0
    end := 0
    dur := 0
    for i, e := range timeSeries {
        if i == 0 {
            start = e
            end = start + duration
        }
        if e < end {
            end = e + duration
            if  i == len(timeSeries) - 1{
                dur += end - start
            }
        } else {
            dur += end - start
            start = e
            end = e + duration
            if i == len(timeSeries) - 1 {
                dur += end - start
            }
        }
    }
    return dur
}