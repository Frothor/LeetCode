func winnerSquareGame(n int) bool {
    a:= make([]int, n+1)
    a[1]=1
    for i:=2;i<=n;i++ {
        for j:=1; (i- j*j) >=0;j++ {
            if i- j*j == 0 {
               a[i]= 1
                break
            }
            remaining := i- j*j
            if a[remaining] ==0 {
                a[i]= 1
                break
            }
        }
    }
    if a[n]==1 {
        return true
    }
    return false
}

//Fastest
func winnerSquareGame(n int) bool {
    a:= make([]int, n+1)

    for i:=1;i<=n;i++ {
        for j:=1; (i-j*j) >=0;j++ {
            if a[i-j*j] == 0 {
                a[i]= 1
                break
            }
        }
    }
    
    return a[n]==1 
}