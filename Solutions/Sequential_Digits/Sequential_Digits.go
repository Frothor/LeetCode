func sequentialDigits(low int, high int) []int {
    tmp := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
    res := []int{}
    for len(tmp) > 0 {
        cur := tmp[0]
        tmp = tmp[1:]
        if cur >= low && cur <= high { res = append(res, cur) }
        lastDigit := cur % 10
        if lastDigit < 9 && cur * 10 + lastDigit + 1 <= high { tmp = append(tmp, cur * 10 + lastDigit + 1) }
    }
    return res
}

func sequentialDigits(low int, high int) []int {
    res := make([]int, 0, 100)

    q := make([]int, 0, 10)
    for i := 1; i < 9; i++ {
        q = append(q, i)
    }
    
    for len(q) > 0 {
        qn := make([]int, 0, len(q))
        for _, num := range q {
            if num > high {
                break
            }
            if num >= low {
                res = append(res, num)
            }
            digit := num % 10
            if digit < 9 {
                qn = append(qn, num * 10 + digit + 1)
            }
        }        
        q = qn
    }
    return res
}