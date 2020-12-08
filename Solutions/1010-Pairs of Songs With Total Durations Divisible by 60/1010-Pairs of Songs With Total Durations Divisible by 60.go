//Second fastest
// func numPairsDivisibleBy60(time []int) int {
    
//    remainders := [60]int{}
//    count := 0
//     for _, t := range time {
//         if t % 60 == 0 { // check if a%60==0 && b%60==0
//             count += remainders[0]
//         } else { // check if a%60+b%60==60
//             count += remainders[60 - t % 60]
//         }
//         remainders[t % 60]++ // remember to update the remainders
//     }
//         return count;
    
// }



func numPairsDivisibleBy60(time []int) int {
    c := 0
    m := map[int]int{}
    for _, t := range time {
        k := t % 60
        var need int
        if k == 0 {
            need = 0
        } else {
           need = 60 -k
        }
        c+= m[need]
        m[k]++
    }
    
    return c
}

//Fastest
func numPairsDivisibleBy60(time []int) int {
    
    // https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/259681/2ms-Java-solution-easy-to-understand.
    
    mods := make([]int, 60)
    total := 0
    for _, t := range(time) {
        mod := t % 60
        
        required := 60 - mod
        if mod == 0 {
            required = 0
        }
        total = total + mods[required]
        mods[mod] = mods[mod] + 1
    }
    
    return total
    
}