//Most common
func rand10() int {
    x := rand7() - 1
    y := rand7() - 1
    for x*7+y >= 40{
        x = rand7()-1
        y = rand7()-1
    }
    
    return (x*7+y)%10+1
}

//Fastest
var prev int
func rand10() int {
    
    if prev < 10 {
        u := 1
        //p :=prev
        for u < 10000000 {
            prev = prev * 7 + rand7() - 1
            u *= 7
        }
        //fmt.Println(p, prev, u)
    }
    ret := prev % 10 + 1
    prev = prev / 10
    //fmt.Println(ret, prev)
    return ret
}