//Fastest
func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}
func maxPower(s string) int {
    maxRL,curRL := 1,1
    var prevChar rune
    for _,c := range s {
        if c == prevChar {
            curRL++
        } else {
            maxRL = max(curRL, maxRL)
            curRL = 1
            prevChar = c
        }
    }
    return max(curRL, maxRL)
}

//Another
func maxPower(s string) int {
    //Map:=make(map[string]int)
    pre:=""
    count:=0
    max:=0
    for i:=range s{
        if pre==string(s[i]){
            count++
        }else{
            count=1
            pre=string(s[i])
        }
        if max<count{
            max=count
        }
    }
    return max
}