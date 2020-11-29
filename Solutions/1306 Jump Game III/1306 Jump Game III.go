//Third fastest (Most common)
func canReach(arr []int, start int) bool {
    visited:=make(map[int]bool)

    return jump(arr, start + arr[start], visited) || jump(arr, start - arr[start], visited)
}

func jump(arr []int, next int, visited map[int]bool) bool {
    if next < 0 || next >= len(arr) {
        return false
    }
    
    if arr[next] == 0 {
        return true
    }
    
    if visited[next] {
        return false
    }
    
    visited[next] = true
    
    return jump(arr, next + arr[next], visited) || jump(arr, next - arr[next], visited)
    
}

//Second fastest
var visited []bool

func canReach(arr []int, start int) bool {
	visited = make([]bool, len(arr))
	return canReachRec(arr, start)
}

func canReachRec(arr []int, start int) bool {
	if start >= len(arr) || start < 0 {
		return false
	}
	if visited[start] {
		return false
	}
	if arr[start] == 0 {
		return true
	}
	visited[start] = true
	left := start - arr[start]
	right := start + arr[start]

	return canReachRec(arr, right) || canReachRec(arr, left)
}

//Fastest
func canReach(arr []int, s int) bool {
    moves := []int{}
    visited := map[int]bool{s:true}
    if m := s+arr[s]; m < len(arr){
        moves = append(moves, m)
        visited[m] = true
    }
    if m := s-arr[s]; m >= 0{
        moves = append(moves, m)
        visited[m] = true
    }
    for len(moves) > 0{
        nextmoves := []int{}
        for _, m := range moves{
            if arr[m] == 0{return true}
            if newm := m+arr[m]; newm < len(arr) && !visited[newm]{
                nextmoves = append(nextmoves, newm)
                visited[newm] = true
            }
            if newm := m-arr[m]; newm >= 0 && !visited[newm]{
                visited[newm] = true
                nextmoves = append(nextmoves, newm)
            }
        }
        moves = nextmoves
    }
    return false
}