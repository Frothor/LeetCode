func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
    sums := map[int64]int{}
    points := [][]int{p1, p2, p3, p4}
    
    for i := range points {
        for k:= i+1; k < 4; k++ {
            xl := points[i][0] - points[k][0]
            yl := points[i][1] - points[k][1]
            
            sqSum := int64(xl*xl)+int64(yl*yl)
            if sqSum == 0 {
                return false
            }
            sums[sqSum] = 1
            if len(sums) > 2 {
                return false
            }
        }
    }
    return true
}